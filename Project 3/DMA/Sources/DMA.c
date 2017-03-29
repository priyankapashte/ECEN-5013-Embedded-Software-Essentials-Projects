/**********************************************************
* FILE NAME : DMA.c
* FILE DESCRIPTION : 
* AUTHOR : Akshitha Chanda
*
************************************************************/

#include "dma.h"

#define LENGTH_MEMZERO_TEN_BYTES 10
#define LENGTH_MEMMOVE_TEN_BYTES 10
#define LENGTH_MEMZERO_HUNDRED_BYTES 100
#define LENGTH_MEMMOVE_HUNDRED_BYTES 100
#define LENGTH_MEMZERO_THOUSAND_BYTES 1000
#define LENGTH_MEMMOVE_THOUSAND_BYTES 1000

void memove_dma( void * src, void * dst, uint32_t DMASize){

			SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;         				//Enable clock  to dmamux

			SIM_SCGC7 |= SIM_SCGC7_DMA_MASK; 							//Enable clock \ to dma 


			DMAMUX0_CHCFG0 = 0x00;			                            // Disable DMA Mux channel first

			DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;                      // Clearing Mark of done

			DMA_SAR0 = (uint32_t)src;                                   // Setting Source Address


			#ifdef MEMOVE_EIGHT_BIT_TRANSFER

				DMA_DSR_BCR0 |= DMASize;								// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |=   ( DMA_DCR_AA_MASK|                        /* Enabling Auto aligned */
								DMA_DCR_EINT_MASK|						/*  Enabling interrupt after successful operation */
								DMA_DCR_SSIZE(1)|						/* Setting source size to 8 bits */
								DMA_DCR_DSIZE(1)|						/* Setting Destination size to 8 bits */
								DMA_DCR_SINC_MASK|                      /* Source Address increments after sucessful operation */
								DMA_DCR_DINC_MASK                       /* Destination address increments */


					);
				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */

				// Write counter start code here

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */

			#elif MEMOVE_SIXTEEN_BIT_TRANSFER

				if(DMASize % 2 == 0){

				DMA_DSR_BCR0 |= DMASize;								// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |=   ( DMA_DCR_AA_MASK|                        /* Enabling Auto aligned */
								DMA_DCR_EINT_MASK|						/*  Enabling interrupt after successful operation */
								DMA_DCR_SSIZE(2)|						/* Setting source size to 16 bits */
								DMA_DCR_DSIZE(2)|						/* Setting Destination size to 16 bits */
								DMA_DCR_SINC_MASK|                      /* Source Address increments after sucessful operation */
								DMA_DCR_DINC_MASK                       /* Destination address increments */


					);
				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */

				// Write counter start code here

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */


				}

				else MEMOVE_THIRTY_TWO_BIT_TRANSFER

				if(DMASize % 4 == 0){

				DMA_DSR_BCR0 |= DMASize;								// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |=   ( DMA_DCR_AA_MASK|                        /* Enabling Auto aligned */
								DMA_DCR_EINT_MASK|						/*  Enabling interrupt after successful operation */
								DMA_DCR_SSIZE(0)|						/* Setting source size to 32 bits */
								DMA_DCR_DSIZE(0)|						/* Setting Destination size to 32 bits */
								DMA_DCR_SINC_MASK|                      /* Source Address increments after sucessful operation */
								DMA_DCR_DINC_MASK                       /* Destination address increments */


					);
				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */

				// Write counter start code here

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */


				}

			#endif 

void memzero_dma( void * src, void * dst, uint32_t DMASize){


			SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;         				//Enable clock  to dmamux

			SIM_SCGC7 |= SIM_SCGC7_DMA_MASK; 							//Enable clock \ to dma 


			DMAMUX0_CHCFG0 = 0x00;			                            // Disable DMA Mux channel first

			DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;                      // Clearing Mark of done

			DMA_SAR0 = (uint32_t)src;                                   // Setting Source Address


			#ifdef MEMOVE_EIGHT_BIT_TRANSFER

				DMA_DSR_BCR0 |= DMASize;								// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |=   ( DMA_DCR_AA_MASK|                        /* Enabling Auto aligned */
								DMA_DCR_EINT_MASK|						/*  Enabling interrupt after successful operation */
								DMA_DCR_SSIZE(1)|						/* Setting source size to 8 bits */
								DMA_DCR_DSIZE(1)|						/* Setting Destination size to 8 bits */
								DMA_DCR_DINC_MASK                       /* Destination address increments */


					);
				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */

				// Write counter start code here

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */

			#elif MEMOVE_SIXTEEN_BIT_TRANSFER

				if(DMASize % 2 == 0){

				DMA_DSR_BCR0 |= DMASize;								// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |=   ( DMA_DCR_AA_MASK|                        /* Enabling Auto aligned */
								DMA_DCR_EINT_MASK|						/*  Enabling interrupt after successful operation */
								DMA_DCR_SSIZE(2)|						/* Setting source size to 16 bits */
								DMA_DCR_DSIZE(2)|						/* Setting Destination size to 16 bits */
								DMA_DCR_DINC_MASK                       /* Destination address increments */


					);
				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */

				// Write counter start code here

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */


				}

				else MEMOVE_THIRTY_TWO_BIT_TRANSFER

				if(DMASize % 4 == 0){

				DMA_DSR_BCR0 |= DMASize;								// Setting the data transfer size

				/* Initializing DMA */ 

				DMA_DCR0 |=   ( DMA_DCR_AA_MASK|                        /* Enabling Auto aligned */
								DMA_DCR_EINT_MASK|						/*  Enabling interrupt after successful operation */
								DMA_DCR_SSIZE(0)|						/* Setting source size to 32 bits */
								DMA_DCR_DSIZE(0)|						/* Setting Destination size to 32 bits */
								DMA_DCR_DINC_MASK                       /* Destination address increments */


					);
				DMA_DAR0 = (uint32_t)dst;

				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;				/* Enabling the  DMA Channel source */
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);				/* Selecting DMA Channel */

				// Write counter start code here

				DMA_DCR0 |= DMA_DCR_START_MASK;                         /* Starting DMA transfer */


				}

			#endif 




}



}



