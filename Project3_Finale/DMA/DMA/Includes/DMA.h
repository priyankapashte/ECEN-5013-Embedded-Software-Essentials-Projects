/**********************************************************
* FILE NAME : DMA.h
* FILE DESCRIPTION : This is the header file for DMA.c
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
#define DMA_FOUR 4
#define DMA_HUNDRED 100
#define DMA_TEN 10
#define DMA_THOUSANd 1000
#define DMA_FIVE_THOUSAND 5000

/**********************************************************
*
* FUNCTION : memove_dma_one_byte()
* FUNCTION DESCRIPTION : This memove transfers data from src to dst using DMA and the transfer size is one byte
*
************************************************************/

void memove_dma_one_byte( void * src, void * dst, uint32_t DMASize);

/**********************************************************
*
* FUNCTION : memove_dma_two_byte()
* FUNCTION DESCRIPTION : This memove transfers data from src to dst using DMA and the transfer size is two byte
*
************************************************************/

void memove_dma_two_byte( void * src, void * dst, uint32_t DMASize);

/**********************************************************
*
* FUNCTION : memove_dma_four_byte()
* FUNCTION DESCRIPTION : This memove transfers data from src to dst using DMA and the transfer size is four byte
*
************************************************************/

void memove_dma_four_byte( void * src, void * dst, uint32_t DMASize);

/**********************************************************
*
* FUNCTION : memzero_dma_one_byte()
* FUNCTION DESCRIPTION : This memzero transfers data from zero value to dst using DMA and the transfer size is one byte
*
************************************************************/

void memzero_dma_one_byte( void * src, void * dst, uint32_t DMASize);

/**********************************************************
*
* FUNCTION : memzero_dma_two_byte()
* FUNCTION DESCRIPTION : This memzero transfers data from zero value to dst using DMA and the transfer size is two byte
*
************************************************************/

void memzero_dma_two_byte( void * src, void * dst, uint32_t DMASize);

/**********************************************************
*
* FUNCTION : memzero_dma_four_byte()
* FUNCTION DESCRIPTION : This memzero transfers data from zero value to dst using DMA and the transfer size is four byte
*
************************************************************/

void memzero_dma_four_byte( void * src, void * dst, uint32_t DMASize);


#endif
