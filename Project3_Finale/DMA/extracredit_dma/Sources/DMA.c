/**********************************************************
* FILE NAME : DMA.c
* FILE DESCRIPTION : 
* AUTHOR : Akshitha Chanda
*
************************************************************/

#include "DMA.h"

void DMA0_configure(void){

	SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;         				//Enable clock  to dmamux

	SIM_SCGC7 |= SIM_SCGC7_DMA_MASK; 							//Enable clock to dma


	DMAMUX0_CHCFG0 = 0x00;			                            // Disable DMA Mux channel first
	DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;                      // Clearing Mark of done

}

void DMA1_configure(void){

	SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;         				//Enable clock  to dmamux

	SIM_SCGC7 |= SIM_SCGC7_DMA_MASK; 							//Enable clock to dma


	DMAMUX0_CHCFG0 = 0x00;			                            // Disable DMA Mux channel first
	DMA_DSR_BCR1 |= DMA_DSR_BCR_DONE_MASK;                      // Clearing Mark of done


}

void memove_dma_one_byte_DMA0( void * src, void * dst, uint32_t DMASize){

			DMA0_configure();

			DMA_SAR0 = (uint32_t)src;                                   // Setting Source Address

			if(DMASize % DMA_ONE == DMA_ZERO ){

			DMA_DSR_BCR0 |= DMASize;								// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |= DMA_DCR_AA_MASK;                         /* Enabling Auto aligned */
				DMA_DCR0 |=	DMA_DCR_EINT_MASK;						 /*  Enabling interrupt after successful operation */
				DMA_DCR0 |=	DMA_DCR_SSIZE(1);						 /* Setting source size to 8 bits */
				DMA_DCR0 |=	DMA_DCR_DSIZE(1);						 /* Setting Destination size to 8 bits */
				DMA_DCR0 |=	DMA_DCR_SINC_MASK;                       /* Source Address increments after sucessful operation */
				DMA_DCR0 |=	DMA_DCR_DINC_MASK;                       /* Destination address increments */



				DMA_DAR0 = (uint32_t)dst;

				DMA_DCR0 |= DMA_DCR_EINT_MASK;	// Enable DMA Interrupt

				//NVIC_EnableIRQ(DMA0_IRQn);
			    //__enable_irq();

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */

				// Write counter start code here

				start_timer1();

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */

			}


}

void memove_dma_one_byte_DMA1(void * src, void * dst, uint32_t DMASize){

								DMA1_configure();

								DMA_SAR1 = (uint32_t)src;                                   // Setting Source Address

							if(DMASize % DMA_ONE == DMA_ZERO ){

								DMA_DSR_BCR1 |= DMASize;								// Setting the data transfer size

								/* Initializing DMA */

								DMA_DCR1 |= DMA_DCR_AA_MASK;                         /* Enabling Auto aligned */
								DMA_DCR1 |=	DMA_DCR_EINT_MASK;						 /*  Enabling interrupt after successful operation */
								DMA_DCR1 |=	DMA_DCR_SSIZE(1);						 /* Setting source size to 8 bits */
								DMA_DCR1 |=	DMA_DCR_DSIZE(1);						 /* Setting Destination size to 8 bits */
								DMA_DCR1 |=	DMA_DCR_SINC_MASK;                       /* Source Address increments after sucessful operation */
								DMA_DCR1 |=	DMA_DCR_DINC_MASK;                       /* Destination address increments */



								DMA_DAR1 = (uint32_t)dst;

								DMA_DCR1 |= DMA_DCR_EINT_MASK;	// Enable DMA Interrupt

								//NVIC_EnableIRQ(DMA0_IRQn);
							    //__enable_irq();

								DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
								DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(60);				/* Selecting DMA Channel */

								// Write counter start code here

								DMA_DCR1 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */

							}

}

