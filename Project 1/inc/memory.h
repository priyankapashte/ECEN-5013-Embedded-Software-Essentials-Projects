#ifndef _MEMORY_H
#define _MEMORY_H

#include <stdint.h>

/**************************************************************************************
* my_memmove
* Move a length of bytes from source to destination using pointers. Checks for
* overlapped areas between the two memory blocks. Returns an error if the move failed.
*
* @param src - Pointer of source location 
* @param dst - Pointer of destination location 
* @param length - Length of bytes to move
* @return - 0 if move is successful,else an error code 
**************************************************************************************/
int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length);



/*************************************************************************************
* my_memset 
* Set all the bytes starting from source upto a given length to a given value. Returns
* an error if the move failed.
*
* @param src - Pointer of source location 
* @param length - Length of bytes to set
* @param value - Value to be set for the memory locations 
* @return - 0 if successful, else an error code 
*************************************************************************************/
int8_t my_memset(uint8_t *src, uint32_t length, uint8_t value);



/*************************************************************************************
* my_memzero
* Set all the bytes starting from source upto a given length to zero. Returns
* an error if the move failed.
*
* @param src - Pointer of source location 
* @param length - Length of bytes to set
* @return - 0 if successful, else an error code 
*************************************************************************************/
int8_t my_memzero(uint8_t *src, uint32_t length);



/*************************************************************************************
* my_reverse
* Takes a source pointer to a memory location and a length in bytes and reverses
* the order of all of the bytes. Returns an error if the move failed.
*
* @param src - Pointer of source location 
* @param length - Length of bytes to reverse
* @return - 0 if successful, else an error code 
*************************************************************************************/
int8_t my_reverse(uint8_t *src, uint32_t length);


#endif