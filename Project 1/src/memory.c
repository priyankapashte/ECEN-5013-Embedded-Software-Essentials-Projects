#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

/************************************************************************
* my_memmove
************************************************************************/
int8_t my_memmove(uint8_t * src, uint8_t * dst, uint32_t length)
{  
	if(src == NULL || dst == NULL || (length < 0)) 		// Check for valid input
		return -1;
		
	if(src == dst)	// Check if source & destination address are same
	{
		return 0;
	}
	else if((src < dst) && ((src + length) > dst)   // Check for overlapping
	{
		for(int i=length-1; i>0; i--)
		{
			dst[i] = src[i];
		}	
	}
	else
	{
		for(int i=0; i<length; i++)
		{
			dst[i] = src [i];
		}
	}
	return 0;
}

/************************************************************************
* my_memset
************************************************************************/
int8_t my_memset(uint8_t *src, uint32_t length, uint8_t value)
{
    if(src == NULL || (length < 0))		// Check for valid input
        return -1;
    
    for (int i=0; i<length; i++)		// Set the bytes to the given value
        src[i] = value;
    
    return 0;
}

/************************************************************************
* my_memzero
************************************************************************/
int8_t my_memzero(uint8_t * src, uint32_t length)
{
    if(src == NULL || (length < 0))		// Check for valid input
        return -1;
    
    for (int i=0; i<length; i++)		// Set the bytes to zero
        src[i] = 0;
    
    return 0;
}

/************************************************************************
* my_reverse
************************************************************************/
int8_t my_reverse(uint8_t * src, uint32_t length)
{
    if (src == NULL || (length < 0))	// Check for valid input
        return -1;
    
    uint8_t temp;     
    for (i= 0, j = (length-1); i<j; i++, j--)	// Swap the characters
	{
        temp = src[i];           
        src[i]= src[j];     
        src[j]= temp;           
    }
	
    return 0; 
}