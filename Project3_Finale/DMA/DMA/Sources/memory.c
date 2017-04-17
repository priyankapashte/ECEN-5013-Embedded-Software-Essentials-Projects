#include <stdio.h>                                                           /* Including header files */
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "memory.h"


/* Definition of my_memmove function */

int8_t my_memmove(uint8_t * src, uint8_t * dst, uint32_t length)

{

	if((src != NULL) && (dst != NULL) && (length > MEMORY_NUM_ZERO))       	/* Check for NULL pointer of src and dst and length >0 */
	{
		if(src != dst)                                                   /* Checking if src and dst address are not same */
		{

			if( src >= dst || src >= (dst + length))                  /* Checking if src and dst are overlapping */
			{
				for(uint8_t i = MEMORY_NUM_ZERO; i < length; i++ )  /* If src is greater than dst copying from beginning*/
				{
					*(dst+i) = *(src+i);
				}
			}
			else                                                         /* If src is less than dst copying from the end */
			{
				for (uint32_t i = MEMORY_NUM_ZERO; i != length; i++)
				{
					*(dst + length - i - MEMORY_NUM_ONE) = *(src + length - i - MEMORY_NUM_ONE);
				}
			}
			return MEMORY_NUM_ZERO;
		}
		else
		{
			return MEMORY_ERROR_NEGATIVEONE;
		}

	}
	else
	{

		return MEMORY_ERROR_NEGATIVEONE;            		                      /* Error case */
	}
}

/* Definition of my_memset function */

int8_t  my_memset(uint8_t * src, uint32_t length, uint8_t value)
{

	if((src != NULL) && (length > MEMORY_NUM_ZERO))                                /* Check for NULL pointer and length >0 */
	{	

		for(uint32_t increment=MEMORY_NUM_ZERO; increment < length; increment++)
		{
			*src = value;                                           	/* Replacing the value till increment matches length */
			src++;
		}
		return MEMORY_NUM_ZERO;
	}
	else
	{

		return MEMORY_ERROR_NEGATIVEONE;                                      		/* Error case */
	}
}

/* Definition of my_memzero function */

int8_t  my_memzero(uint8_t * src, uint32_t length)
{	
	if((src != NULL) && (length > MEMORY_NUM_ZERO))                             	/* Check for NULL pointer and length >0 */
	{		 

		for(int32_t loop=MEMORY_NUM_ZERO; loop < length; loop++)            /* Replacing the value with zero till loop matches length */
		{
			*src =  MEMORY_NUM_ZERO;
			src++;
		}
		return MEMORY_NUM_ZERO;
	}
	else
	{  
		return MEMORY_ERROR_NEGATIVEONE;                                 /*Error case */
	}
}

/* Definition of my_reverse function */

int8_t my_reverse(uint8_t * src, uint32_t length)
{	

	if((src != NULL) && (length > MEMORY_NUM_ZERO))                 	/* Check for NULL pointer and length >0 */
	{
		uint8_t *end;                                                  /* Defining end pointer and a uint8 temp variable */
		uint8_t temp;
		end= src;

		for (uint8_t counter = MEMORY_NUM_ZERO; counter < length - MEMORY_NUM_ONE; counter++)
		{
			end++;                                                 /* Incrementing end pointer till it points to last address */
		}
		for (uint8_t counter = MEMORY_NUM_ZERO; counter < length/MEMORY_NUM_TWO; counter++)
		{        
			temp   = *end;        /* storing last byte to temp and then replacing the end byte with first byte and then replacing
                                              last byte with the first and this continues till counter increments to half the length */
			*end   = *src;
  
			*src = temp;

			src++;
			end--;
		}
		return MEMORY_NUM_ZERO;
	}
	else
	{
		return MEMORY_ERROR_NEGATIVEONE;                                 /* Error case */
	}
}

