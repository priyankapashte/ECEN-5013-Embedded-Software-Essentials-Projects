/**********************************************************
* FILE NAME : gpio.c/ gpio.h
* AUTHOR : Akshitha Chanda and Priyanka Pashte
*
************************************************************/


#ifndef _GPIO_H
#define _GPIO_H

#include <stdio.h>
#include <stdint.h>

uint8_t fd;

/*****************************************************************************
* GPIO_nrf_init
* Function configures the GPIO ports for SPI and nRF module.
*
******************************************************************************/
void GPIO_nrf_init();

void nrf_cs_low();
void nrf_cs_high();

#endif
