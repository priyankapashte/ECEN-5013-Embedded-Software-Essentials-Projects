/*
 * analysis.c
 *
 *  Created on: Mar 6, 2017
 *      Author: Priyanka Pashte, Shreya Verma
 */

/* Including header file containing function definitions used in analysis.c */
#include "analysis.h" 


analysis_e analyze_bytes(CircBuf * buf, analysis_t * result, uint8_t numr)
{
  uint8_t num = 0;
  uint8_t alpha = 0;
  uint8_t punc = 0;
  uint8_t misc = 0;


  for(uint8_t i = 0; i < numr; i++)
  {

    //uint8_t item = CB_RemoveItem(buf);
	  uint8_t item = *(buf->buffer+i);
    //LOG_RAW_STRING("Item");
    //LOG_RAW_INTR(item);

    // Adding numbers
    if (item >= 48 && item <= 57)
    {
      num++;
    }

    // Adding upper case letters
    else if (item >= 65 && item <= 90)
    {
      alpha++;
    }

    // Adding lower case letters
    else if (item >= 97 && item <= 122)
    {
      alpha++;
    }

    // Adding punctuation
    else if (item >= 33 && item <= 47)
    {
      punc++;
    }

    // Adding miscellaneous characters
    else
    {
      misc++;
    }
  }

  // Set members of results structure
  result->alpha = alpha;
  result->num = num;
  result->punc = punc;
  result->misc = misc;

}



