/**********************************************************
* FILE NAME : profiler.h
* FILE DESCRIPTION : This is the header file for profiler.c.
* AUTHOR : Akshitha Chanda
*
************************************************************/

#ifndef INCLUDES_PROFILER_H_
#define INCLUDES_PROFILER_H_

//#include "MKL25Z4.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include "memory.h"

#define PROFILER_ZERO 0
#define TEN_BYTES 10
#define HUNDRED_BYTES 100
#define THOUSAND_BYTES 1000
#define FIVE_THOUSAND_BYTES 5000

void profiler_FRDM_DMA_memmove_one_byte(void);

void profiler_FRDM_DMA_memmove_two_byte(void);

void profiler_FRDM_DMA_memmove_four_byte(void);

void profiler_FRDM_DMA_memzero_one_byte(void);

void profiler_FRDM_DMA_memzero_two_byte(void);

void profiler_FRDM_DMA_memzero_four_byte(void);

void profiler_non_DMA_memove(void);

void profiler_non_DMA_memzero(void);

void profiler_std_library_memzero(void);

void profiler_std_library_memmove(void);

double getTimeMoveMem_std(uint8_t * destination, uint8_t  * source, uint32_t num);

double getTimeMoveSet_std(uint8_t * source, uint32_t num);

void profiler_BBB_std_library_memmove(void);

void profiler_BBB_std_library_memzero(void);

double getTimeMoveMem(uint8_t * destination, uint8_t * source, uint32_t num);

void profiler_BBB_non_DMA_memmove(void);

void profiler_BBB_non_DMA_memset(void);



#endif
