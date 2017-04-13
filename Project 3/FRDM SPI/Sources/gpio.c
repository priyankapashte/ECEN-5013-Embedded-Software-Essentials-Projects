/*
 * gpio.c
 *
 *  Created on: Apr 13, 2017
 *      Author: Priyanka
 */

#include "gpio.h"

void GPIO_nrf_init(){
	 PORTD_PCR6 = PORT_PCR_MUX(1);
	 PTD_BASE_PTR->PDDR |= 1<<6;              //Set PortC Pin 4 output direction
	 PTC_BASE_PTR->PSOR = 1<<6;				  // Make PortC Pin 4 high

	 //PORTD_PCR0 = PORT_PCR_MUX(0x2);          // Set PTD0 to mux 2 [SPI0_PCS0]
	 PORTD_PCR1 = PORT_PCR_MUX(0x2);          // Set PTD1 to mux 2 [SPI0_SCK]
	 PORTD_PCR2 = PORT_PCR_MUX(0x2);          // Set PTD2 to mux 2 [SPI0_MOSI]
	 PORTD_PCR3 = PORT_PCR_MUX(0x2);          // Set PTD3 to mux 2 [SPIO_MISO]
}
