/**********************************************************
* FILE NAME : DMA.c
* FILE DESCRIPTION : This file consists of memove and memzero functions using DMA
* AUTHOR : Akshitha Chanda
*
************************************************************/

#include "DMA.h"



#define LENGTH_MEMZERO_TEN_BYTES 10
#define LENGTH_MEMMOVE_TEN_BYTES 10
#define LENGTH_MEMZERO_HUNDRED_BYTES 100
#define LENGTH_MEMMOVE_HUNDRED_BYTES 100
#define LENGTH_MEMZERO_THOUSAND_BYTES 1000
#define LENGTH_MEMMOVE_THOUSAND_BYTES 1000

void DMA_configure(void){

			SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;         				//Enable clock  to dmamux

			SIM_SCGC7 |= SIM_SCGC7_DMA_MASK; 					//Enable clock to dma 


			DMAMUX0_CHCFG0 = 0x00;			                                // Disable DMA Mux channel first
			DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;                                  // Clearing Mark of done


}

void memove_dma_one_byte( void * src, void * dst, uint32_t DMASize){


			DMA_configure();

			DMA_SAR0 = (uint32_t)src;                                               // Setting Source Address

			if(DMASize % DMA_ONE == DMA_ZERO ){

				DMA_DSR_BCR0 |= DMASize;					// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |= DMA_DCR_AA_MASK;                                    /* Enabling Auto aligned */
				DMA_DCR0 |=	DMA_DCR_EINT_MASK;				/*  Enabling interrupt after successful operation */
				DMA_DCR0 |=	DMA_DCR_SSIZE(1);			     	/* Setting source size to 8 bits */
				DMA_DCR0 |=	DMA_DCR_DSIZE(1);				/* Setting Destination size to 8 bits */
				DMA_DCR0 |=	DMA_DCR_SINC_MASK;                       /* Source Address increments after sucessful operation */
				DMA_DCR0 |=	DMA_DCR_DINC_MASK;                             /* Destination address increments */



				DMA_DAR0 = (uint32_t)dst;

				DMA_DCR0 |= DMA_DCR_EINT_MASK;					// Enable DMA Interrupt

				//NVIC_EnableIRQ(DMA0_IRQn);
			    //__enable_irq();

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */


				start_timer1();

				DMA_DCR0 |= DMA_DCR_START_MASK;                         		/* Starting DMA transfer */

			}

		}

void memove_dma_two_byte( void * src, void * dst, uint32_t DMASize){


			    DMA_configure();

			    DMA_SAR0 = (uint32_t)src;                                   // Setting Source Address

			    if(DMASize % DMA_TWO == DMA_ZERO ){

				DMA_DSR_BCR0 |= DMASize;			     // Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |= DMA_DCR_AA_MASK;                         /* Enabling Auto aligned */
				DMA_DCR0 |=	DMA_DCR_EINT_MASK;		   /*  Enabling interrupt after successful operation */
				DMA_DCR0 |=	DMA_DCR_SSIZE(2);		 /* Setting source size to 16 bits */
				DMA_DCR0 |=	DMA_DCR_DSIZE(2);		 /* Setting Destination size to 16 bits */
				DMA_DCR0 |=	DMA_DCR_SINC_MASK;                       /* Source Address increments after successful operation */
				DMA_DCR0 |=	DMA_DCR_DINC_MASK;                       /* Destination address increments */



				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */


				start_timer1();

				DMA_DCR0 |= DMA_DCR_START_MASK;                                       /* Starting DMA transfer */


				}

			}


void memove_dma_four_byte( void * src, void * dst, uint32_t DMASize){


			    DMA_configure();

			    DMA_SAR0 = (uint32_t)src;                                   // Setting Source Address


				 if(DMASize % DMA_FOUR == DMA_ZERO ){

				DMA_DSR_BCR0 |= DMASize;				/* Setting the data transfer size */

				/* Initializing DMA */

				DMA_DCR0 |= DMA_DCR_AA_MASK;                            /* Enabling Auto aligned */
				DMA_DCR0 |=	DMA_DCR_EINT_MASK;		       /*  Enabling interrupt after successful operation */
				DMA_DCR0 |=	DMA_DCR_SSIZE(0);			/* Setting source size to 32 bits */
				DMA_DCR0 |=	DMA_DCR_DSIZE(0);			 /* Setting Destination size to 32 bits */
				DMA_DCR0 |=	DMA_DCR_SINC_MASK;                       /* Source Address increments after successful operation */
				DMA_DCR0 |=	DMA_DCR_DINC_MASK;                       /* Destination address increments */



				/* Initializing DMA */ 


				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */

				// Write counter start code here

				start_timer1();

				DMA_DCR0 |= DMA_DCR_START_MASK;                        		 /* Starting DMA transfer */


				}


				else{        
			                                                           /* If the DMASize is not a multiple of 4 or 2 or an odd number */

				DMA_DSR_BCR0 |= DMASize - (DMASize % DMA_FOUR);	   /* Setting the data transfer size */

				/* Initializing DMA */

				DMA_DCR0 |= DMA_DCR_AA_MASK;                         /* Enabling Auto aligned */
				DMA_DCR0 |=	DMA_DCR_EINT_MASK;			/*  Enabling interrupt after successful operation */
				DMA_DCR0 |=	DMA_DCR_SSIZE(0);			/* Setting source size to 32 bits */
				DMA_DCR0 |=	DMA_DCR_DSIZE(0);			/* Setting Destination size to 32 bits */
				DMA_DCR0 |=	DMA_DCR_SINC_MASK;                       /* Source Address increments after successful operation */
				DMA_DCR0 |=	DMA_DCR_DINC_MASK;                       /* Destination address increments */



				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;		/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);		/* Selecting DMA Channel */

				// Write counter start code here



				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */


			}

		    }


void memzero_dma_one_byte( void * src, void * dst, uint32_t DMASize){


			   DMA_configure();

			   DMA_SAR0 = (uint32_t)src;                                   // Setting Source Address

			   if(DMASize % DMA_ONE == DMA_ZERO){

				DMA_DSR_BCR0 |= DMASize;								// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |=    DMA_DCR_AA_MASK;                        /* Enabling Auto aligned */
				DMA_DCR0 |=	   DMA_DCR_EINT_MASK;			/*  Enabling interrupt after successful operation */
				DMA_DCR0 |=	   DMA_DCR_SSIZE(1);			/* Setting source size to 8 bits */
				DMA_DCR0 |=	   DMA_DCR_DSIZE(1);			/* Setting Destination size to 8 bits */
				DMA_DCR0 |=	   DMA_DCR_DINC_MASK;                    /* Destination address increments */



				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */

				// Write counter start code here

				start_timer1();

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */
			}

		}

void memzero_dma_two_byte( void * src, void * dst, uint32_t DMASize){


			   DMA_configure();

			   DMA_SAR0 = (uint32_t)src;                                   // Setting Source Address

	     	   if(DMASize % DMA_TWO == DMA_ZERO ){

				DMA_DSR_BCR0 |= DMASize;				// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |=    DMA_DCR_AA_MASK;                         /* Enabling Auto aligned */
				DMA_DCR0 |=	   DMA_DCR_EINT_MASK;			/*  Enabling interrupt after successful operation */
				DMA_DCR0 |=	   DMA_DCR_SSIZE(2);			/* Setting source size to 16 bits */
				DMA_DCR0 |=	   DMA_DCR_DSIZE(2);			/* Setting Destination size to 16 bits */
				DMA_DCR0 |=	   DMA_DCR_DINC_MASK;                   /* Destination address increments */


				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;		/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);		/* Selecting DMA Channel */

				// Write counter start code here

				start_timer1();

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */


				}
		}

void memzero_dma_four_byte( void * src, void * dst, uint32_t DMASize){


			   DMA_configure();

			   DMA_SAR0 = (uint32_t)src;                                   // Setting Source Address



			 if(DMASize % DMA_FOUR == DMA_ZERO){

				DMA_DSR_BCR0 |= DMASize;				// Setting the data transfer size

				/* Initializing DMA */

				DMA_DCR0 |=    DMA_DCR_AA_MASK;                         /* Enabling Auto aligned */
				DMA_DCR0 |=	   DMA_DCR_EINT_MASK;			/*  Enabling interrupt after successful operation */
				DMA_DCR0 |=	   DMA_DCR_SSIZE(0);			/* Setting source size to 32 bits */
				DMA_DCR0 |=	   DMA_DCR_DSIZE(0);			/* Setting Destination size to 32 bits */
				DMA_DCR0 |=	   DMA_DCR_DINC_MASK;                   /* Destination address increments */



				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;		/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);		/* Selecting DMA Channel */

				// Write counter start code here
				start_timer1();

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */


				}

				else{

				DMA_DSR_BCR0 |= DMASize - (DMASize % DMA_FOUR);			   /* Setting the data transfer size */

				/* Initializing DMA */ 

				/* Initializing DMA */

				DMA_DCR0 |=    DMA_DCR_AA_MASK;                         /* Enabling Auto aligned */
				DMA_DCR0 |=	   DMA_DCR_EINT_MASK;			/*  Enabling interrupt after successful operation */
				DMA_DCR0 |=	   DMA_DCR_SSIZE(0);			/* Setting source size to 32 bits */
				DMA_DCR0 |=	   DMA_DCR_DSIZE(0);			/* Setting Destination size to 32 bits */
				DMA_DCR0 |=	   DMA_DCR_DINC_MASK;                   /* Destination address increments */


				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;		/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);		/* Selecting DMA Channel */

				// Write counter start code here

				start_timer1();

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */


			}

			}

/******************************************************************************************************
*FUNCTION DESCRIPTION : The below function checks for the overlap of src and dst, if it detects any overlap
* the src is copied to another string and memove take splace from string to dst. 
*
******************************************************************************************************/

/* 

       void overlap(uint8_t * src, uint8_t * dst, uint32_t DMASize){

	uint8_t string[1000];

	if( src >= dst || src >= (dst + DMASize)) {

		for( uint32_t i = 0; i <= DMASize; i++){

			string[i] = src[i];

		}
	else{
		
		memove_dma_one_byte(src,dst,DMASize);
	}
	}
	
	memove_dma_one_byte(string, dst, DMASize);

} 

*/












