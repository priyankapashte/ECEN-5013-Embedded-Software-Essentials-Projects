/**********************************************************
* FILE NAME : DMA.h
* FILE DESCRIPTION : 
* AUTHOR : Akshitha Chanda
*
************************************************************/

#ifndef INCLUDES_DMA_H_             /* Include guards */
#define INCLUDES_DMA_H_
#include "MKL25Z4.h"                /* Including libraries */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define DMA_ZERO 0                   /* Macros */
#define DMA_ONE 1
#define DMA_TWO 2
#define DMA_FOUR

void DMA0_configure(void);

void DMA1_configure(void);

void memove_dma_one_byte_DMA0( void * src, void * dst, uint32_t DMASize);


void memove_dma_one_byte_DMA1( void * src, void * dst, uint32_t DMASize);




#endif
