/*
 * analysis.h
 *
 *  Created on: Mar 6, 2017
 *      Author: Priyanka Pashte, Shreya Verma
 */

#ifndef INCLUDE_ANALYSIS_H_
#define INCLUDE_ANALYSIS_H_

/* Included libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "circbuf.h"
#include "uart.h"

typedef struct char_analysis
{
  uint32_t alpha;				/* Store count of Alphabets */
  uint32_t num;					/* Store count of Numbers */
  uint32_t punc;				/* Store count of Punctuations */
  uint32_t misc;				/* Store count of Miscellaneous characters */
} analysis_t;

typedef enum {

	SUCCESS
} analysis_e;

/*
*  analyze_bytes
*  Analyze whether the byte received is numeric, alphabetic, punctuation or miscellaneous.
*  @param buf: Pointer to the byte received.
*  @param result: Structure pointer variable of analysis_t.
*  @param numr: length of the bytes received.
*
*/

analysis_e analyze_bytes(CircBuf *buf, analysis_t *result, uint8_t numr);


#endif /* INCLUDE_ANALYSIS_H_ */
