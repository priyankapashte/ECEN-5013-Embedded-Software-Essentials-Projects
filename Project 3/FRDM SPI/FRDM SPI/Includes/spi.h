/*
 * spi.h
 *
 *  Created on: Mar 22, 2017
 *      Author: Priyanka
 */

#ifndef INCLUDES_SPI_H_
#define INCLUDES_SPI_H_

/**************************************************************************************
* SPI_init
* Initializes the SPI controller
*
* @param size - None
* @return - None
**************************************************************************************/
 void SPI_init();

 /**************************************************************************************
 * SPI_read_byte
 * Reads a single byte from the SPI bus
 *
 * @param byte - Store the value read in byte
 * @return - None
 **************************************************************************************/
void SPI_read_byte(uint8_t byte);

/**************************************************************************************
* SPI_write_byte
* Sends a single byte on the SPI bus
*
* @param byte - Value of the byte to be written
* @return - None
**************************************************************************************/
void SPI_write_byte(uint8_t byte);


/**************************************************************************************
* SPI_send_packet
* Sends numerous SPI Bytes given a pointer to a byte array and a length of how many
* bytes to send.
*
* @param p - Pointer to the packet start
* @param size - Size of the packet
* @return - None
**************************************************************************************/
void SPI_send_packet(uint8_* p, size_t length);


/**************************************************************************************
* SPI_flush
* Blocks until SPI transmit buffer has completed transmitting
*
* @return - None
**************************************************************************************/
void SPI_flush();

#endif /* INCLUDES_SPI_H_ */
