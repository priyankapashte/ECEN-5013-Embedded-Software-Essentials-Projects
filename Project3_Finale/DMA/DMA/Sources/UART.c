#include "UART.h"



void uart0_config(){

	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;                        /* Enabling clock for PORTA module */
	
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;												/* Enabling clock gate for UART0 */
	
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(UART_NUM_ONE);						/* Selecting clock source for UART0 either MCGFLLCLK clock or MCGPLLCLK/2 clock */
	

	PORTA_PCR1 = PORT_PCR_MUX(UART_NUM_TWO);									/* Setting MUX to Alternative 2 to enable UART0 */
	PORTA_PCR2 = PORT_PCR_MUX(UART_NUM_TWO);
	
	UART0_C1 = UART_NUM_ZERO;																	/* Setting 8 bit data and disabling parity for UART0 */	

	UART0_C2 = UART_NUM_ZERO;																	/* Setting 8 bit data and disabling parity for UART0 */	

	
	uint16_t baud = (uint16_t) (DEFAULT_SYSTEM_CLOCK/(BAUD_RATE*OVER_SAMPLING_RATIO));			/* Baud rate calculation */

	UART0_BDH |= (baud >> UART_NUM_EIGHT) & UART0_BDH_SBR_MASK;															/* Storing the SBR bits of 8 to 11 */
	UART0_BDL = (baud & UART0_BDL_SBR_MASK);																								/* Storing the SBR bits of 0 to 7 */

	UART0_C2 = (UART_C2_RIE_MASK | UART0_C2_RE_MASK | UART0_C2_TE_MASK);  /* Enabling Tx and Rx interrupt */

	tx_buf = (CircBuf *)malloc(sizeof(CircBuf));
			CB_BufferInitialize(tx_buf,TXBUF_LENGTH);


			rx_buf = (CircBuf *)malloc(sizeof(CircBuf));
			CB_BufferInitialize(rx_buf,RXBUF_LENGTH);



	NVIC_EnableIRQ(UART0_IRQn);																/* Set NVIC interrupts */
	NVIC_SetPriority(UART0_IRQn,UART_NUM_TWO);								/* Setting priority of UART0 */

	

}

inline UART_e uart_send_byte(uint8_t item) {
	
	if(item != NULL){
		while(!(UART0_S1 & UART_S1_TDRE_MASK));                /* loop till transmit data register is empty */
		UART0_D = item;																			 /* Sending the data */
		return eUART_SUCCESS;
	}
	else{
		return eUART_FAILURE;
	}
}

inline UART_e uart_send_n_bytes(uint8_t* item, uint32_t length) {
	
	if(item != NULL && length >UART_NUM_ZERO){
		uint32_t counter ;																		/* loop for the length of the n byte sequence */
		for(counter = UART_NUM_ZERO; counter < length; counter++){
			uart_send_byte(*item);
			item++;
		}
		return eUART_SUCCESS;
	}
	else{
		return eUART_FAILURE;	
	}
}

inline UART_e uart_receive_byte(uint8_t *ptr) {


		while(!(UART0_S1 & UART_S1_RDRF_MASK));                 /* loop till the  receive buffer is full */
		*ptr = UART0_D;
		/*BinaryLogger *log2;
		log2 = (BinaryLogger*)malloc(sizeof(BinaryLogger));
		if(log2 != 0){
			create_log_item(log2,DATA_RECEIVED,0,*ptr);
			log_item(tx_buf,log2);
			destroy_log_item(tx_buf,log2);
		}
		log2=NULL;*/

		return eUART_SUCCESS;

}

extern void UART0_IRQHandler() {

	// Critical section don't allow an interrupt in an interrupt
	NVIC_DisableIRQ(UART0_IRQn);

	uint8_t status = UART0_S1;

	CB_e error_code = CB_isBufferEmpty(tx_buf);
																														/* If buffer is not empty and TDRE flag is set then transmit the character */
	if((status & UART0_S1_TDRE_MASK) && error_code==eCB_NOT_EMPTY){
			uint8_t string_1[32];
			uint8_t *temp;
			temp = string_1;
			CB_RemoveItem(tx_buf,temp);
			uart_send_byte(*temp);
	}
	else{
		UART0_C2 &= ~UART0_C2_TIE_MASK;			                   /* If tx buffer is empty then disable the tx interrupt */
	}

	error_code = CB_isBufferFull(rx_buf);

	if((status & UART0_S1_RDRF_MASK) && error_code==eCB_NOT_FULL){
														                              /* If buffer is not and RDRF flag is set then recieve the character from UARTD0 */
		uint8_t c;
		uart_receive_byte(&c);
		uart_send_byte(c);
		CB_AddItem(rx_buf, c);
	}
	else{
		UART0_C2 &= ~UART0_C2_RIE_MASK;  		                  /* If rx buffer is full then disable the rx interrupt */
	}

	// Turn interrupts back on
	NVIC_EnableIRQ(UART0_IRQn);
}





