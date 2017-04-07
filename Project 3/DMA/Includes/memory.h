/***************************************************************************
* FILENAME: memory.h
* OWNER: Akshitha Chanda.
* FILE DESCRIPTION: This is file is the header file for the function defined in memory.c
****************************************************************************/

#ifndef _MEMORY_H
#define _MEMORY_H


/* Defining  macros */

#define MEMORY_NUM_ZERO (0)
#define MEMORY_NUM_ONE (1)
#define MEMORY_NUM_TWO (2)
#define MEMORY_ERROR_NEGATIVEONE (-1)

/**********************************************************************
* my_memmove
* Function copies characters of length l from srcto dst and also checks for overlapping.
* @param src : Source location pointer
* @param dst : Destination location pointer
* @param length: length of bytes

************************************************************************/

int8_t my_memmove(uint8_t * src, uint8_t * dst, uint32_t length);

/*********************************************************************
* my_memset
* Function copies value to the first length(number) characters of the string pointed by src.
* @param src : Source location pointer
* @param length : Number of bytes to which the value to be set.
* @param value:  The value to be set to the string pointed by src.

**********************************************************************/

int8_t  my_memset(uint8_t * src, uint32_t length, uint8_t value);

/*********************************************************************
* my_memzero
* Function sets value zero to the first length(number) characters of the string pointed by src.
* @param src : Source location pointer
* @param length : Number of bytes to which the value zero to be set.

**********************************************************************/

int8_t  my_memzero(uint8_t * src, uint32_t length);

/**********************************************************************
* my_reverse
* Function takes the source pointer to a memory location and length of the bytes is given. It reverses the array.
  Inputs are the source pointer which points to array and the length of bytes to be reversed.
* @param src : Source location pointer
* @param length : Number of bytes to reverse.

***********************************************************************/

int8_t my_reverse(uint8_t * src, uint32_t length);

#endif


