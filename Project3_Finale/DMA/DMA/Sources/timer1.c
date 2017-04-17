/**********************************************************
* FILE NAME : timer1.c
* FILE DESCRIPTION : This file consists of the configuration of timer and functions start and stop timer
* AUTHOR : Akshitha Chanda
*
************************************************************/

#include "timer.h"


uint32_t overflow_count = 0;

void configure_timer1(void){

	SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;				/* Enabling  TPM0 Clock  */
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);           			/* Selecting MCGFLLCLK/2 as counter timer clock  Up to 48 MHz */ 
	TPM0_SC = 0;                               			/* clearing out the  timer control registers */
	TPM0_SC = TPM_SC_PS(0);						/* Setting prescalar to one when counter is disabled */
	TPM0->MOD = 65535;                          			/* Setting counter for 10us */
	NVIC_EnableIRQ(TPM0_IRQn);                  			/* Enabling interrupt register in NVIC */
	TPM0_SC |= TPM_SC_TOIE_MASK;					/* Enabling Interrupt for Timer overflow */


}

void start_timer1(void){

    TPM0_SC |= TPM_SC_CMOD(1);      						/* starting counter */

    	TPM0->CNT = 0;                              				/* Reset the CNT register */

	//   TPM0->SC = 0X00000080;                     			 /* Enabling TPM counter */

}

int32_t stop_timer1(void){

	TPM0->SC = 0x0;                                                      /* Stopping the counter */
	int32_t time = 0;                                                    /* Defining time variable which accounts for time spent for clock cycles */
	uint32_t total_clock_cycles = 0;
	//uint32_t clock_cycles = TPM0->CNT;                                 /* Defining clock_cycles variable which is TPM0->CNT count over the overflow */
	total_clock_cycles = overflow_count*65535 + TPM0->CNT;               /* Calculating the total number of clock cycles including overflow count and TPM0->CNT */

	time = total_clock_cycles/21;                                        /* We get time spent in micro seconds and 21 MHz is the clock frequency */
	//return time;
	
	 int8_t string[32];
	 int8_t *temp=string;
	 my_itoa(temp,time,6);                                               /* COnverting integer value to ascii */
	 while(*temp != '\0'){
	 uart_send_byte(*temp);                                              /* Sending ascii through uart */
	 temp++;
	}
}

void TPM0_IRQHandler(void){

	if(TPM0_SC & TPM_SC_TOF_MASK)
	{

		TPM0->SC = 0x0;  	   		    /* Disabling the counter */
		TPM0->CNT = 0;                              /* Reset the CNT register */
		overflow_count++;  			    /* incrementing the overflow count */
		TPM0_SC |= TPM_SC_TOF_MASK;                 /* clearing the overflow mask */
    	TPM0_SC |= TPM_SC_CMOD(1);      		    /* starting counter */


	}

}
