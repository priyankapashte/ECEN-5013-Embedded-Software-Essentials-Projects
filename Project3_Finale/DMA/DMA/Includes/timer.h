/**********************************************************
* FILE NAME : timer.h
* FILE DESCRIPTION : This file is the header file for timer1.c
* AUTHOR : Akshitha Chanda
*
************************************************************/

#ifndef INCLUDES_TIMER_H_
#define INCLUDES_TIMER_H_

#include "MKL25Z4.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**********************************************************
*
* FUNCTION : configure_timer1()
* FUNCTION DESCRIPTION : This function configures the TPM0 timer
*
************************************************************/

void configure_timer1(void);

/**********************************************************
*
* FUNCTION : start_timer1()
* FUNCTION DESCRIPTION : This function starts the timer TPM0
*
************************************************************/

void start_timer1(void);

/**********************************************************
*
* FUNCTION : stop_timer1()
* FUNCTION DESCRIPTION : This function stops the timer by making SC zero and calculate the time and clockcycles
*
************************************************************/

int32_t stop_timer1(void);

/**********************************************************
*
* FUNCTION : TPM1_IRQHandler()
* FUNCTION DESCRIPTION : IRQ handler for TPM1
*
************************************************************/

void TPM1_IRQHandler(void);


#endif
