/***************************************************************************************
* FILENAME: data.h                                                                     *
* OWNER: Sridhar Pavithrapu/ Akshitha Chanda.							       *
* FILE DESCRIPTION: This file is the header file for the function's defined in data.c  *
***************************************************************************************/

#ifndef _DATA_H
#define _DATA_H

/* Including prerequisite header file's */
#include <stdio.h>
//#include "memory.h"


/* Defining macros */

#define DATA_ERROR_VALUE (-1)
#define DATA_NUM_ZERO (0)
#define DATA_NUM_ONE (1)
#define DATA_NUM_TWO (2)
#define DATA_NUM_THREE (3)
#define DATA_NUM_FOUR (4)
#define DATA_NUM_NINE (9)
#define DATA_NUM_TEN (10)
#define DATA_NUM_NEGATIVEONE (-1)

/****************************************************************************
* my_itoa
* Function converts integer(data) into null terminated string(str) with respect to the base value(base).
* @param str : input data
* @param data : output string
* @param base: base value

*****************************************************************************/

int8_t * my_itoa(int8_t * str, int32_t data, int32_t base);

/*****************************************************************************
* my_atoi
* Function converts string(str) to an integer.
* @param str : input string

*****************************************************************************/

int32_t my_atoi(int8_t * str);

/*****************************************************************************
* big_to_little32
* Function converts the given input from big endian to little endian.
* @param data : input data
* @param length: length of bytes
*
*****************************************************************************/

int8_t big_to_little32(uint32_t * data, uint32_t length);

/*****************************************************************************
* little_to_big32
* Function converts the given input from little endian to big endian.
* @param data : input data
* @param length: length of bytes
*
*****************************************************************************/

int8_t little_to_big32(uint32_t * data, uint32_t length);

/*****************************************************************************
* print_memory
* Function prints the value present in the given start pointer to the given length of bytes.
* @param start : Source location pointer
* @param length: length of bytes
*
*****************************************************************************/

void print_memory(uint8_t * start, uint32_t length);

/*****************************************************************************
*
* Function converts float to ascii value.
* @param res : string value after conversion
* @param data: input float data.
* @afterpoint: upto how many digits after decimal point.
*
*****************************************************************************/

char *ftoa(float f, int *status);

int32_t NUMERIC_COUNT(int8_t * src, int32_t length);
int32_t PUNCTUATIONS_COUNT(int8_t * src, int32_t length);
int32_t ALPHA_COUNT(int8_t * src, int32_t length);

#endif
