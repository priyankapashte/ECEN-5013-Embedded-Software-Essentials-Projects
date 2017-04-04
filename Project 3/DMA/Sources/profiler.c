/**********************************************************
* FILE NAME : profiler.c
* FILE DESCRIPTION : This code is for profiling the code using timer counter
* AUTHOR : Akshitha Chanda
*
************************************************************/

#include "profiler.h"
#include "memory.h"
#include "memory.c"

// FRDM include switches for both FRDM and BBB

void profiler_DMA_memzero(void){

	uint8_t *src = (uint8_t *)0x10000000;
	uint8_t *dst = (uint8_t *)0x10001000;

	*src = 0;                                    /* src declared zero for memzero */

	/*********************************** 10 Bytes Memzero function **************************************/

	start_timer();
	memzero_dma(src, dst, 10);                  /* Calculation the time spend by memzero function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */



	/*********************************** 100 Bytes Memzero function **************************************/

	start_timer();
	memzero_dma(src, dst, 100);                  /* Calculation the time spend by memzero function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */



	/*********************************** 1000 Bytes Memzero function **************************************/

	start_timer();
	memzero_dma(src, dst, 1000);                  /* Calculation the time spend by memzero function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */


	/*********************************** 5000 Bytes Memzero function **************************************/

	start_timer();
	memzero_dma(src, dst, 5000);                  /* Calculation the time spend by memzero function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

}

void profiler_DMA_memove(void){


}


void profiler_non_DMA_memzero(void){

	uint8_t src[10] = "newstrings";
	uint8_t src1[100] = "123456789";
	uint8_t src2[1000] = "123456";
	uint8_t src3[5000] = "123";

	/*********************************** 10 Bytes Memzero non DMA function **************************************/

	start_timer();
	my_memzero(src, 10);                  /* Calculation the time spend by memzero function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */


	/*********************************** 100 Bytes Memzero non DMA function **************************************/

	start_timer();
	my_memzero(src1, 100);                  /* Calculation the time spend by memzero function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */



	/*********************************** 1000 Bytes Memzero non DMA function **************************************/

	start_timer();
	my_memzero(src2, 1000);                  /* Calculation the time spend by memzero function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 5000 Bytes Memzero non DMA function **************************************/

	start_timer();
	my_memzero(src3, 5000);                  /* Calculation the time spend by memzero function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */



}

void profiler_non_DMA_memove(void){

	uint8_t src[10] = "newstrings" , dst[10];
	uint8_t src1[100] = "123456789" ,dst1[100];
	uint8_t src2[1000] = "123456" , dst2[1000];
	uint8_t src3[5000] = "123" , dst3[5000];

	/*********************************** 10 Bytes MEMOVE non DMA function **************************************/

	start_timer();
	my_memmove(src, 10);                  /* Calculation the time spend by non DMA version of memmove function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 100 Bytes MEMOVE non DMA function **************************************/

	start_timer();
	my_memmove(src1, 100);                  /* Calculation the time spend by non DMA version of memmove function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 1000 Bytes MEMOVE non DMA function **************************************/

	start_timer();
	my_memmove(src2, 1000);                  /* Calculation the time spend by non DMA version of memmove function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */


	/*********************************** 1000 Bytes MEMOVE non DMA function **************************************/

	start_timer();
	my_memmove(src3, 5000);                  /* Calculation the time spend by non DMA version of memmove function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */



}

void profiler_std_library_memzero(void){

	uint8_t  src[10] = "newstrings" , dst[10];
	uint8_t src1[100] = "123456789" ,dst1[100];
	uint8_t src2[1000] = "123456" , dst2[1000];
	uint8_t src3[5000] = "123" , dst3[5000];

	/*********************************** 10 Bytes MEMZERO standard C library  function **************************************/

	start_timer();
	memmove(dst, 0, 10);                 /* Calculation the time spend standard library memzero  function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 100 Bytes MEMZERO standard C library  function **************************************/

	start_timer();
	memmove(dst1, 0, 100);                 /* Calculation the time spend standard library memzero  function for 100 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 100 Bytes MEMZERO standard C library  function **************************************/

	start_timer();
	memmove(dst2, 0, 1000);                 /* Calculation the time spend standard library memzero  function for 100 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 100 Bytes MEMZERO standard C library  function **************************************/

	start_timer();
	memmove(dst3, 0, 5000);                 /* Calculation the time spend standard library memzero  function for 100 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */



}

void profiler_std_library_memmove(void){



	uint8_t  src[10] = "newstrings" , dst[10];
	uint8_t src1[100] = "123456789" ,dst1[100];
	uint8_t src2[1000] = "123456" , dst2[1000];
	uint8_t src3[5000] = "123" , dst3[5000];

	/*********************************** 10 Bytes MEMMOVE standard C library  function **************************************/

	start_timer();
	memmove(dst, src, 10);                 /* Calculation the time spend standard library memmove  function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 100 Bytes MEMMOVE standard C library  function **************************************/

	start_timer();
	memmove(dst1, src1 , 100);                 /* Calculation the time spend standard library memmove  function for 100 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 1000 Bytes MEMMOVE standard C library  function **************************************/

	start_timer();
	memmove(dst2, src2 , 1000);                 /* Calculation the time spend standard library memmove  function for 1000 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 5000 Bytes MEMMOVE standard C library  function **************************************/

	start_timer();
	memmove(dst3, src3, 5000);                 /* Calculation the time spend standard library memmove  function for 1000 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */
	

	
}



