/*
 * spi.c
 *
 *  Created on: Mar 22, 2017
 *      Author: Priyanka
 */
#include "spi.h"

 void SPI_init(){

	 SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;                      // Turn on clock to D module
	 SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;                       // Enable SPI0 clock

	 GPIO_nrf_init();									     // Initialize GPIO Pins for SPI

	 SPI0_C1 = SPI_C1_MSTR_MASK;        					 // Set SPI0 to Master

	 SPI0_BR = (SPI_BR_SPPR(0x02) | SPI_BR_SPR(0x08));       // Set baud rate prescale divisor to 3 & set baud rate divisor to 64 for baud rate of 15625 Hz

	 SPI0_C1 |= SPI_C1_SPE_MASK;                             // Enable SPI0

 }

 uint8_t SPI_read_byte(){
	 uint8_t byte;
	 while ((SPI0->S & SPI_S_SPRF_MASK) != SPI_S_SPRF_MASK);          // Check if transfer is complete, hence receive buffer full
	 byte = SPI0->D;									              // Read Data
	 return byte;
 }

 uint8_t SPI_write_byte(uint8_t byte){
	 uint8_t status;
	 while ((SPI0->S & SPI_S_SPTEF_MASK) != SPI_S_SPTEF_MASK);        // Check if transfer buffer is empty
	 SPI0->D = byte;							                      // Send data
	 status = SPI_read_byte();
	 return status;
 }

 void SPI_send_packet(uint8_t *p, size_t length){
	for (uint8_t i = 0; i < length; i++) {
		while ((SPI0->S & SPI_S_SPTEF_MASK) != SPI_S_SPTEF_MASK);    // Check if transfer buffer is empty
		SPI_write_byte(*p);											 // Send byte in the packet
		p++;
	}
 }

 void SPI_flush(){
	 while ((SPI0->S & SPI_S_SPTEF_MASK) != SPI_S_SPTEF_MASK);       // Check if transfer buffer is empty
 }



