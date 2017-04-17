/*
* Including header files 
*/
#include "circbuf.h"


/* Definition of CB_AddItem function */
CB_e CB_AddItem(CircBuf * buf , CircBufItem_t  item){
	
	if(NULL != buf){																															/* Check for NULL pointer */
	
		if(eCB_FULL == CB_isBufferFull(buf))                                        /* Calling CB_isBufferFull function to know whether buffer is full */
			return eCB_BUFFER_ALLOCATION_FAILURE;																			/* Returning allocation failure case */

		if(buf->count == CIRC_BUF_NUM_ZERO){																				/* Initial case for adding first element */
			
				*(buf->head) = item;
					(buf->head)++;
				(buf->count)++;
				return eCB_BUFFER_ALLOCATION_SUCCESS;																		/* Returning allocation success case */
		}
		else{                                                                                  
																																						/* Adding element and Updating the head pointer if the head pointer is at the last location */
			*(buf->head) = item;
			buf->head = ((buf->head) < (buf->buffer + buf->length)? (buf->head) + CIRC_BUF_NUM_ONE : buf->buffer);
			

			if(buf->count != buf->length)
				(buf->count)++;
			
			return eCB_BUFFER_ALLOCATION_SUCCESS;																			/* Returning allocation success case */
		}	 
	}
	else
	{
		return eCB_NULL_POINTER;																										/* Returning null pointer error case */
	}
}


/* Definition of CB_RemoveItem function */
CB_e CB_RemoveItem(CircBuf * buf , CircBufItem_t * item){

	if(NULL != buf){																															/* Check for NULL pointer */
	
		if(eCB_EMPTY == CB_isBufferEmpty(buf))                                      /* Calling CB_isBufferEmpty function to know whether buffer is empty */
			return eCB_BUFFER_DEALLOCATION_FAILURE;																		/* Returning de-allocation failure case */
		
		if(buf->head == buf->tail){
			*item =*(buf->tail);
			buf->head = buf->buffer;
			buf->tail = buf->buffer;
			buf->count = CIRC_BUF_NUM_ZERO;
			return eCB_BUFFER_DEALLOCATION_SUCCESS;
		}
		/*else if(buf->tail == (( buf->buffer) + ( buf->length)) - CIRC_BUF_NUM_ONE){
			*item = *(buf->tail);
      buf->tail=buf->buffer;
			(buf->count)--;
			return eCB_BUFFER_ALLOCATION_SUCCESS;
    }*/
		else{
			*item = *(buf->tail);
			(buf->tail)++;
			(buf->count)--;
			if(buf->count ==0){
				buf->head = buf->buffer;
				buf->tail = buf->buffer;
				buf->count = CIRC_BUF_NUM_ZERO;
			}
			return eCB_BUFFER_ALLOCATION_SUCCESS;
		}

	}	
	else
	{
		return eCB_NULL_POINTER;
	}

}


/* Definition of CB_isBufferFull function */
CB_e CB_isBufferFull(CircBuf * buf){
	if(NULL != buf){
		
		if(buf->count == buf->length)
			return eCB_FULL;
		else
			return eCB_NOT_FULL;
	}
	else{
		
		return eCB_NULL_POINTER;
	}
}


/* Definition of CB_isBufferEmpty function */
CB_e CB_isBufferEmpty(CircBuf * buf){
	if(NULL != buf){
		
		if(buf->count == CIRC_BUF_NUM_ZERO)
			return eCB_EMPTY;
		else
			return eCB_NOT_EMPTY;
	}
	else{
	
		return eCB_NULL_POINTER;
	}
}


/* Definition of CB_BufferPeak function */
CB_e CB_BufferPeak(CircBuf * buf, CircBufItem_t * item_n , size_t n){

	if((NULL != buf) || (NULL != item_n)){

		CircBufItem_t * temp;
		temp = buf;
		while(n != CIRC_BUF_NUM_ZERO){
			temp++;
			n--;
		}
		item_n = temp - CIRC_BUF_NUM_ONE;
		return eCB_PEAK_VALUE_RETURN_SUCCESS;
	}
	else{
		
		return eCB_NULL_POINTER;
	}

}


/* Definition of CB_BufferInitialize function */
CB_e CB_BufferInitialize(CircBuf * buf , uint32_t size){

	if(NULL != buf){
		
		if(size > CIRC_BUF_NUM_ZERO){
			
			buf->buffer = (CircBufItem_t*)malloc(sizeof(CircBufItem_t) * size);
			if(buf->buffer == CIRC_BUF_NUM_ZERO)
				return eCB_HEAP_ALLOCATION_ERROR;
			else
				buf->head = buf->buffer;
				buf->tail = buf->buffer;
				buf->length = size;
				buf->count = CIRC_BUF_NUM_ZERO;	
				return eCB_NO_ERROR;	
				
		}
		else{
			
			return eCB_INPUT_SIZE_ERROR;
		}
	}
	else{
		
		return eCB_NULL_POINTER;
	}

}


/* Definition of CB_BufferDestroy function */
CB_e CB_BufferDestroy(CircBuf * buf){

	if(NULL != buf){
		
		free(buf->buffer);
		buf->head = NULL;
		buf->tail = NULL;
		buf->length = CIRC_BUF_NUM_ZERO;
		buf->count = CIRC_BUF_NUM_ZERO;
	}
	else{
		
		return eCB_NULL_POINTER;
	}

}
