/***************************************************************************************
* FILENAME: circbuf.h                                                                     
* OWNER: Sridhar Pavithrapu/Akshitha Chanda.							       
* FILE DESCRIPTION: This file is the header file for the function's defined in circbuf.c  
***************************************************************************************/
#ifndef __CIRCBUFF_H__
#define __CIRCBUFF_H__


/* Include section */
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "memory.h"

/* Defining macros */
#define CIRC_BUF_NUM_ZERO (0)
#define CIRC_BUF_NUM_ONE (1)


typedef uint8_t CircBufItem_t;

/*
* The structure contains the elements of the circular buffer.
*/ 
typedef struct CircBuf_t {

  CircBufItem_t * buffer;													/* valid buffer pointer pointing to the circular buffer */
	CircBufItem_t * head;														/* valid head pointer for adding elements to the circular buffer */
	CircBufItem_t * tail;														/* valid tail pointer for removing elements from the circular buffer */
	size_t length;																	/* holds the size of the circular buffer */
	size_t count; 																	/* holds the count of the elements present in the circular buffer */

} CircBuf;

/*
* CB_Enum_t : This enum defines the error’s for protection and fail-safe mechanisms in Circular Buffer.
*/
typedef enum {

	eCB_NO_ERROR,																		/* No error case */
	eCB_HEAP_ALLOCATION_ERROR,											/* Heap allocation failure case */
	eCB_INPUT_SIZE_ERROR, 	 		  									/* Input size of the circular buffer error case */
	eCB_FULL,																				/* Circular Buffer is completely full */
	eCB_NOT_FULL,																		/* Circular Buffer is not full */	
	eCB_EMPTY,																			/* Circular Buffer is empty */
	eCB_NOT_EMPTY,																	/* Circular Buffer is not empty */
	eCB_NULL_POINTER,																/* Error case for NULL pointer */
	eCB_NO_LENGTH,																	/* Error case for no length */
	eCB_BUFFER_ALLOCATION_SUCCESS,									/* Circular Buffer allocation success case */ 
	eCB_BUFFER_ALLOCATION_FAILURE,									/* Circular Buffer allocation failed case */ 
	eCB_BUFFER_DEALLOCATION_SUCCESS,								/* Circular Buffer de-allocation success case */ 
	eCB_BUFFER_DEALLOCATION_FAILURE,									/* Circular Buffer de-allocation failed case */
	eCB_PEAK_VALUE_RETURN_SUCCESS									      /* Circular Buffer peak value return case */

}CB_e;

/* Function Prototype Section */

/****************************************************************************
* CB_AddItem
* Function adds the item to the circular buffer.
* @param buf : valid pointer to circular buffer
* @param item : value/item to be added to the circular buffer
* @return_value CB_e : Return's the success and failure cases while adding elements to circular buffer 

*****************************************************************************/
CB_e CB_AddItem(CircBuf * buf , CircBufItem_t item);

/****************************************************************************
* CB_RemoveItem
* Function removes the item from the circular buffer.
* @param buf : valid pointer to circular buffer
* @param item : valid pointer which stores the copy of removed/deleted item
* @return_value CB_e : Return's the success and failure cases while removing elements from circular buffer 

*****************************************************************************/
CB_e CB_RemoveItem(CircBuf * buf , CircBufItem_t * item);

/****************************************************************************
* CB_isBufferFull
* Function checks whether the circular buffer is full or not.
* @param buf : valid pointer to circular buffer
* @return_value CB_e : Return's the value showing whether the circular buffer is full or not

*****************************************************************************/
CB_e CB_isBufferFull(CircBuf * buf);

/****************************************************************************
* CB_isBufferEmpty
* Function removes the item from the circular buffer.
* @param buf : valid pointer to circular buffer
* @return_value CB_e : Return's the value showing whether the circular buffer is empty or not

*****************************************************************************/
CB_e CB_isBufferEmpty(CircBuf * buf);

/****************************************************************************
* CB_BufferPeak
* Function returns the nth item of a circular buffer.
* @param buf : valid pointer to circular buffer
* @param item_n : valid pointer which points to the nth item in the circular buffer
* @param source : parameter which points to the nth item in the circular buffer
* @return_value CB_e : Return's the failure values while removing elements from circular buffer

*****************************************************************************/
CB_e CB_BufferPeak(CircBuf * buf, CircBufItem_t * item_n ,size_t source);

/****************************************************************************
* CB_BufferInitialize
* Function initializes the circular buffer.
* @param buf : valid pointer to circular buffer
* @param size : number of elements in the circular buffer
* @return_value CB_e : Return's the success and failure cases for circular buffer initialization

*****************************************************************************/
CB_e CB_BufferInitialize(CircBuf * buf, uint32_t size);

/****************************************************************************
* CB_BufferDestroy
* Function destroys the circular buffer and returns the memory back to the heap .
* @param buf : valid pointer to circular buffer
* @return_value CB_e : Return's the success and failure cases for destroying the circular buffer

*****************************************************************************/
CB_e CB_BufferDestroy(CircBuf * buf);


#endif
