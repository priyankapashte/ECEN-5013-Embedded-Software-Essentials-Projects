/*
 * spi.c
 *
 *  Created on: Mar 22, 2017
 *      Author: Priyanka
 */
#include "spi.h"

 void SPI_init(){

	 SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;      // Turn on clock to D module
	 SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;       // Enable SPI0 clock

	 PORTD_PCR0 = PORT_PCR_MUX(0x2);         // Set PTD0 to mux 2 [SPI0_PCS0]
	 PORTD_PCR1 = PORT_PCR_MUX(0x2);         // Set PTD1 to mux 2 [SPI0_SCK]
	 PORTD_PCR2 = PORT_PCR_MUX(0x2);         // Set PTD2 to mux 2 [SPI0_MOSI]
	 PORTD_PCR3 = PORT_PCR_MUX(0x2);         // Set PTD3 to mux 2 [SPIO_MISO]

	 GPIOD_PDDR |= 1;				// Set PortD Pin 0 as output for SS
	 GPIOD_PSOR |= 1;				// Keep SS high initially

	 SPI0_C1 = SPI_C1_MSTR_MASK | SPI_C1_SSOE_MASK;   // Set SPI0 to Master & SS pin to auto SS

	 SPI0_BR = (SPI_BR_SPPR(0x02) | SPI_BR_SPR(0x08));     // Set baud rate prescale divisor to 3 & set baud rate divisor to 64 for baud rate of 15625 hz

	 SPI0_C1 |= SPI_C1_SPE_MASK;    // Enable SPI0

 }

 uint8_t SPI_read_byte(){
	 uint8_t byte;
	 SPI0->D = 0x00;
	 while ((SPI0->S & SPI_S_SPTEF_MASK) != SPI_S_SPTEF_MASK);
	 byte = SPI0->D;
	 return byte;
 }

 void SPI_write_byte(uint8_t byte){
	 while ((SPI0->S & SPI_S_SPRF_MASK) != SPI_S_SPRF_MASK);          // Check if transfer buffer is empty
	 SPI0->D = byte;							                     // Send data
 }

 void SPI_send_packet(uint8_t * p, size_t length){
	for (uint8_t i = 0; i < length; i++) {
		while ((SPI0->S & SPI_S_SPTEF_MASK) != SPI_S_SPTEF_MASK);		// Poll until empty
		SPI0->D = p[i];
	}
 }

 void SPI_flush(){

 }



