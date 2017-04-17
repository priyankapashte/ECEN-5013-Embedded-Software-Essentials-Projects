/**********************************************************
* FILE NAME : profiler_FRDM.c
* FILE DESCRIPTION : This file consists of profiling of DMA memove/mezero, NON DMA memove/memzero and Standard library memove/memzero functions 
* 10, 100, 1000, 5000 bytes
* AUTHOR : Akshitha Chanda
*
************************************************************/

#include "profiler.h"

#ifdef PROFILING_FRDM

	uint8_t  src[TEN_BYTES] = "newstrings" , dst[TEN_BYTES];
	uint8_t src1[HUNDRED_BYTES] = "123456789" ,dst1[HUNDRED_BYTES];
	uint8_t src2[THOUSAND_BYTES] = "123456" , dst2[THOUSAND_BYTES];
	uint8_t src3[FIVE_THOUSAND_BYTES] = "123" , dst3[FIVE_THOUSAND_BYTES];


	/**********************************************************
	*
	* FUNCTION : profiler_FRDM_DMA_memmove_one_byte()
	* FUNCTION DESCRIPTION : This function profiles DMA memove functions for 10 , 100, 1000, 5000 bytes on FRDM with transfer size of 1 byte
	*
	************************************************************/

	void profiler_FRDM_DMA_memmove_one_byte(void){



		/*********************************** 10 Bytes MEMMOVE DMA  function on FRDM **************************************/
		memove_dma_one_byte(src,dst,10);
		stop_timer1();

		/*********************************** 100 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memove_dma_one_byte(src1,dst1,100);
		stop_timer1();

		/*********************************** 1000 Bytes MEMMOVE DMA function on FRDM **************************************/


		memove_dma_one_byte(src2,dst2,1000);
		stop_timer1();

		/*********************************** 5000 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memove_dma_one_byte(src3,dst3,5000);
		stop_timer1();

	}


	/**********************************************************
	*
	* FUNCTION : profiler_FRDM_DMA__memove()
	* FUNCTION DESCRIPTION : This function profiles DMA memove functions for 10 , 100, 1000, 5000 bytes on FRDM with transfer size of 2 bytes
	*
	************************************************************/

	void profiler_FRDM_DMA_memmove_two_byte(void){



		/*********************************** 10 Bytes MEMMOVE DMA  function on FRDM **************************************/
		memove_dma_two_byte(src,dst,10);
		stop_timer1();

		/*********************************** 100 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memove_dma_two_byte(src1,dst1,100);
		stop_timer1();

		/*********************************** 1000 Bytes MEMMOVE DMA function on FRDM **************************************/


		memove_dma_two_byte(src2,dst2,1000);
		stop_timer1();

		/*********************************** 5000 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memove_dma_two_byte(src3,dst3,5000);
		stop_timer1();

	}

	/**********************************************************
	*
	* FUNCTION : profiler_FRDM_DMA_memmove_four_byte()
	* FUNCTION DESCRIPTION : This function profiles DMA memove functions for 10 , 100, 1000, 5000 bytes on FRDM with transfer size of 4 byte
	*
	************************************************************/

	void profiler_FRDM_DMA_memmove_four_byte(void){



		/*********************************** 10 Bytes MEMMOVE DMA  function on FRDM **************************************/
		memove_dma_four_byte(src,dst,10);
		stop_timer1();

		/*********************************** 100 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memove_dma_four_byte(src1,dst1,100);
		stop_timer1();

		/*********************************** 1000 Bytes MEMMOVE DMA function on FRDM **************************************/


		memove_dma_four_byte(src2,dst2,1000);
		stop_timer1();

		/*********************************** 5000 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memove_dma_four_byte(src3,dst3,5000);
		stop_timer1();

	}

	/**********************************************************
	*
	* FUNCTION : profiler_FRDM_DMA_memzero_one_byte()
	* FUNCTION DESCRIPTION : This function profiles memzero DMA function on FRDM board for 10,100,1000,5000 bytes with transfer size of 2 bytes
	*
	************************************************************/



	void profiler_FRDM_DMA_memzero_one_byte(void){

		int8_t a =0;
		uint8_t *src = &a;

		/*********************************** 10 Bytes MEMMOVE DMA  function on FRDM **************************************/
		memzero_dma_one_byte(src,dst,10);
		stop_timer1();

		/*********************************** 100 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memzero_dma_one_byte(src,dst1,100);
		stop_timer1();

		/*********************************** 1000 Bytes MEMMOVE DMA function on FRDM **************************************/


		memzero_dma_one_byte(src,dst2,1000);
		stop_timer1();

		/*********************************** 5000 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memzero_dma_one_byte(src,dst3,5000);
		stop_timer1();

	}


	/**********************************************************
	*
	* FUNCTION : profiler_FRDM_DMA_memzero_two_byte()
	* FUNCTION DESCRIPTION : This function profiles memzero DMA function on FRDM board for 10,100,1000,5000 bytes with transfer size of 2 bytes
	*
	************************************************************/



	void profiler_FRDM_DMA_memzero_two_byte(void){

		int8_t a =0;
		uint8_t *src = &a;

		/*********************************** 10 Bytes MEMMOVE DMA  function on FRDM **************************************/
		memzero_dma_two_byte(src,dst,10);
		stop_timer1();

		/*********************************** 100 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memzero_dma_two_byte(src,dst1,100);
		stop_timer1();

		/*********************************** 1000 Bytes MEMMOVE DMA function on FRDM **************************************/


		memzero_dma_two_byte(src,dst2,1000);
		stop_timer1();

		/*********************************** 5000 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memzero_dma_two_byte(src,dst3,5000);
		stop_timer1();

	}


	/**********************************************************
	*
	* FUNCTION : profiler_FRDM_DMA_memzero_four_byte()
	* FUNCTION DESCRIPTION : This function profiles memzero DMA function on FRDM board for 10,100,1000,5000 bytes with transfer size of 4 bytes
	*
	************************************************************/



	void profiler_FRDM_DMA_memzero_four_byte(void){

		int8_t a =0;
		uint8_t *src = &a;

		/*********************************** 10 Bytes MEMMOVE DMA  function on FRDM **************************************/
		memzero_dma_four_byte(src,dst,10);
		stop_timer1();

		/*********************************** 100 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memzero_dma_four_byte(src,dst1,100);
		stop_timer1();

		/*********************************** 1000 Bytes MEMMOVE DMA function on FRDM **************************************/


		memzero_dma_four_byte(src,dst2,1000);
		stop_timer1();

		/*********************************** 5000 Bytes MEMMOVE DMA  function on FRDM **************************************/

		memzero_dma_four_byte(src,dst3,5000);
		stop_timer1();

	}



/**********************************************************
*
* FUNCTION : profiler_FRDM_NON_DMA__memove()
* FUNCTION DESCRIPTION : This function profiles NON DMA for 10 , 100, 1000, 5000 bytes on FRDM
*
************************************************************/

void profiler_FRDM_NON_DMA_memove(void){

	
	/*********************************** 10 Bytes MEMMOVE DMA  function on FRDM **************************************/
	start_timer1();
	my_memmove(src,dst,TEN_BYTES);
	stop_timer1();

	/*********************************** 100 Bytes MEMMOVE DMA  function on FRDM **************************************/
	 start_timer1();
	my_memmove(src1,dst1,HUNDRED_BYTES);
	stop_timer1();

	/*********************************** 1000 Bytes MEMMOVE DMA  function on FRDM **************************************/
	start_timer1();
	my_memmove(src2,dst2,THOUSAND_BYTES);
	stop_timer1();

	/*********************************** 5000 Bytes MEMMOVE DMA  function on FRDM **************************************/
	start_timer1();
	my_memmove(src3,dst3,FIVE_THOUSAND_BYTES);
	stop_timer1();



}

/**********************************************************
*
* FUNCTION : profiler_FRDM_NON_DMA__memzero()
* FUNCTION DESCRIPTION : This function profiles  non DMA  function memzero for 10 , 100, 1000, 5000 bytes on FRDM
*
************************************************************/

void profiler_FRDM_non_DMA_memzero(void){


	/*********************************** 10 Bytes MEMMOVE DMA  function on FRDM **************************************/
	 start_timer1();
	my_memset(src, TEN_BYTES, PROFILER_ZERO);
	stop_timer1();

	/*********************************** 100 Bytes MEMMOVE DMA  function on FRDM **************************************/
	 start_timer1();
	my_memset(src1, HUNDRED_BYTES, PROFILER_ZERO);
	stop_timer1();

	/*********************************** 1000 Bytes MEMMOVE DMA  function on FRDM **************************************/
	start_timer1();
	my_memset(src2, THOUSAND_BYTES, PROFILER_ZERO);
	stop_timer1();

	/*********************************** 5000 Bytes MEMMOVE DMA  function on FRDM **************************************/
	 start_timer1();
	my_memset(src3, FIVE_THOUSAND_BYTES, PROFILER_ZERO);
	stop_timer1();



}

/**********************************************************
*
* FUNCTION : profiler_FRDM_STD_LIB_MEMOVE()
* FUNCTION DESCRIPTION : This function profiles  standard library function memove for 10 , 100, 1000, 5000 bytes on FRDM
*
************************************************************/

void profiler_FRDM_STD_LIB_MEMOVE(void){


	/*********************************** 10 Bytes MEMMOVE STANDARD LIBRARY function on FRDM **************************************/
	 start_timer1();
	memmove(dst, src, TEN_BYTES);
	stop_timer1();

	/*********************************** 100 Bytes MEMMOVE STANDARD LIBRARY  function on FRDM **************************************/
	 start_timer1();
	memmove(dst1, src1, HUNDRED_BYTES);
	stop_timer1();

	/*********************************** 1000 Bytes MEMMOVE STANDARD LIBRARY function on FRDM **************************************/
	 start_timer1();
	memmove(dst2, src2, THOUSAND_BYTES);
	stop_timer1();

	/*********************************** 5000 Bytes MEMMOVE STANDARD LIBRARY function on FRDM **************************************/
	 start_timer1();
	memmove(dst3, src3, FIVE_THOUSAND_BYTES);
	stop_timer1();

}

/**********************************************************
*
* FUNCTION : profiler_FRDM_STD_LIB_memzero()
* FUNCTION DESCRIPTION : This function profiles  standard library function memzero for 10 , 100, 1000, 5000 bytes on FRDM
*
************************************************************/

void profiler_FRDM_STD_LIB_memzero(void){

	/*********************************** 10 Bytes MEMMOVE STANDARD LIBRARY function on FRDM **************************************/

	start_timer1();
	memset(src, PROFILER_ZERO, TEN_BYTES);
	stop_timer1();

	/*********************************** 100 Bytes MEMMOVE STANDARD LIBRARY  function on FRDM **************************************/

	start_timer1();
	memset(src1, PROFILER_ZERO, HUNDRED_BYTES);
	stop_timer1();

	/*********************************** 1000 Bytes MEMMOVE STANDARD LIBRARY function on FRDM **************************************/

	start_timer1();
	memset(src2, PROFILER_ZERO, THOUSAND_BYTES);
	stop_timer1();

	/*********************************** 5000 Bytes MEMMOVE STANDARD LIBRARY function on FRDM **************************************/
	start_timer1();
	memset(src3, PROFILER_ZERO, FIVE_THOUSAND_BYTES);
	stop_timer1();

}

#endif



