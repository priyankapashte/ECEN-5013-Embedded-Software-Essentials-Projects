/**********************************************************
* FILE NAME : profiler.c
* FILE DESCRIPTION : This code is for profiling the code using timer counter
* AUTHOR : Akshitha Chanda
*
************************************************************/
#include "time.h"
#include "profiler.h"
#include "memory.h"
#include "memory.c"

// FRDM include switches for both FRDM and BBB

/**********************************************************
*
* FUNCTION : profiler_DMA_memzero()
* FUNCTION DESCRIPTION : This function profiles DMA version of memzero for 10 , 100, 1000, 5000 bytes
*
************************************************************/

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

/**********************************************************
*
* FUNCTION : profiler_DMA_memove()
* FUNCTION DESCRIPTION : This function profiles DMA version of memove for 10 , 100, 1000, 5000 bytes
*
************************************************************/

void profiler_DMA_memove(void){


}

/**********************************************************
*
* FUNCTION : profiler_DMA_memove()
* FUNCTION DESCRIPTION : This function profiles DMA version of memove for 10 , 100, 1000, 5000 bytes
*
************************************************************/

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

/**********************************************************
*
* FUNCTION : profiler_non_DMA_memove()
* FUNCTION DESCRIPTION : This function profiles non DMA version of memove for 10 , 100, 1000, 5000 bytes
*
************************************************************/

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

/**********************************************************
*
* FUNCTION : profiler_std_library_memzero()
* FUNCTION DESCRIPTION : This function profiles  standard library function memset which behaves as memzero for 10 , 100, 1000, 5000 bytes
*
************************************************************/

void profiler_std_library_memzero(void){

	uint8_t  src[10] = "newstrings" , dst[10];
	uint8_t src1[100] = "123456789" ,dst1[100];
	uint8_t src2[1000] = "123456" , dst2[1000];
	uint8_t src3[5000] = "123" , dst3[5000];

	/*********************************** 10 Bytes MEMZERO standard C library  function **************************************/

	start_timer();
	memset(src, 0, 10);                 /* Calculation the time spend standard library memzero  function for 10 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 100 Bytes MEMZERO standard C library  function **************************************/

	start_timer();
	memset(src1, 0, 100);                 /* Calculation the time spend standard library memzero  function for 100 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 100 Bytes MEMZERO standard C library  function **************************************/

	start_timer();
	memset(src2, 0, 1000);                 /* Calculation the time spend standard library memzero  function for 100 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */

	/*********************************** 100 Bytes MEMZERO standard C library  function **************************************/

	start_timer();
	memset(src3, 0, 5000);                 /* Calculation the time spend standard library memzero  function for 100 bytes */
	stop_timer();
	printf("micro seconds");                   /* Use logger functions instead of printf here */


}

/**********************************************************
*
* FUNCTION : profiler_std_library_memmove()
* FUNCTION DESCRIPTION : This function profiles  standard library function memove for 10 , 100, 1000, 5000 bytes
*
************************************************************/

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

/************************************************* BEAGLEBONE PROFILING *******************************************************/

/**********************************************************
*
* FUNCTION : profiler_BBB_std_library_memmove()
* FUNCTION DESCRIPTION : This function profiles  standard library function memove for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

void profiler_BBB_std_library_memmove(void){

	uint8_t  src[10] = "newstrings" , dst[10];
	uint8_t src1[100] = "123456789" ,dst1[100];
	uint8_t src2[1000] = "123456" , dst2[1000];
	uint8_t src3[5000] = "123" , dst3[5000];

	/*********************************** 10 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	memmove(dst, src, 10);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 10 bytes : %f seconds\n", time_spent);


	/*********************************** 100 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	memmove(dst1, src1, 100);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 100 bytes : %f seconds\n", time_spent);

	/*********************************** 100 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	memmove(dst2, src2, 1000);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 1000 bytes : %f seconds\n", time_spent);

	/*********************************** 100 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	memmove(dst3, src3, 5000);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 5000 bytes : %f seconds\n", time_spent);

	
}

/**********************************************************
*
* FUNCTION : profiler_BBB_std_library_memset()
* FUNCTION DESCRIPTION : This function profiles  standard library function memove for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

void profiler_BBB_std_library_memset(void){

	uint8_t  src[10] = "newstrings" , dst[10];
	uint8_t src1[100] = "123456789" ,dst1[100];
	uint8_t src2[1000] = "123456" , dst2[1000];
	uint8_t src3[5000] = "123" , dst3[5000];

	/*********************************** 10 Bytes MEMSET standard C library  function on BBB **************************************/

	clock_t start = clock();
	memset(src, 0, 10);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 10 bytes : %f seconds\n", time_spent);


	/*********************************** 100 Bytes MEMSET standard C library  function on BBB **************************************/

	clock_t start = clock();
	memset(src1, 0, 100);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 100 bytes : %f seconds\n", time_spent);

	/*********************************** 1000 Bytes MEMSET standard C library  function on BBB **************************************/

	clock_t start = clock();
	memset(src2, 0, 1000);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 1000 bytes : %f seconds\n", time_spent);

	/*********************************** 5000 Bytes MEMSET standard C library  function on BBB **************************************/

	clock_t start = clock();
	memset(src3, 0, 5000);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 5000 bytes : %f seconds\n", time_spent);
	

}

/********************************** Profiling on BBB for non-DMA versions of memmove and memset ****************************************/

/**********************************************************
*
* FUNCTION : profiler_non_DMA_memmove()
* FUNCTION DESCRIPTION : This function profiles  non DMA version of memove for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

void profiler_non_DMA_memmove(void){

	uint8_t  src[10] = "newstrings" , dst[10];
	uint8_t src1[100] = "123456789" ,dst1[100];
	uint8_t src2[1000] = "123456" , dst2[1000];
	uint8_t src3[5000] = "123" , dst3[5000];

	/*********************************** 10 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	my_memmove(dst, src, 10);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 10 bytes : %f seconds\n", time_spent);

	/*********************************** 10 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	my_memmove(dst1, src1, 100);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 100 bytes : %f seconds\n", time_spent);

	/*********************************** 10 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	my_memmove(dst2, src2, 1000);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 1000 bytes : %f seconds\n", time_spent);


}

/**********************************************************
*
* FUNCTION : profiler_non_DMA_memzero()
* FUNCTION DESCRIPTION : This function profiles  non DMA version of memzero for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

void profiler_non_DMA_memzero(void){

	uint8_t  src[10] = "newstrings" , dst[10];
	uint8_t src1[100] = "123456789" ,dst1[100];
	uint8_t src2[1000] = "123456" , dst2[1000];
	uint8_t src3[5000] = "123" , dst3[5000];

	/*********************************** 10 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	my_memzero(src, 0, 10);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 10 bytes : %f seconds\n", time_spent);

	/*********************************** 100 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	my_memzero(src, 0, 100);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 100 bytes : %f seconds\n", time_spent);

	/*********************************** 1000 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	my_memzero(src, 0, 1000);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 1000 bytes : %f seconds\n", time_spent);

	/*********************************** 1000 Bytes MEMMOVE standard C library  function on BBB **************************************/

	clock_t start = clock();
	my_memzero(src, 0, 5000);
	clock_t stop = clock();
	double time_spent = double(stop - start)/ CLOCKS_PER_SEC ;
	printf("Time Spent for 1000 bytes : %f seconds\n", time_spent);


}




