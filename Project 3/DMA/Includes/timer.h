/**********************************************************
* FILE NAME : timer.h
* FILE DESCRIPTION : 
* AUTHOR : Akshitha Chanda
*
************************************************************/

#ifndef INCLUDES_TIMER_H_
#define INCLUDES_TIMER_H_

#include "MKL25Z4.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void start_timer(void);

void stop_timer(void);

void TPM0_IRQHandler(void);

#endif