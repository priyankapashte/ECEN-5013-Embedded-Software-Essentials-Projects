/*
 * nordic.h
 *
 *  Created on: Mar 22, 2017
 *      Author: Priyanka
 */

#ifndef INCLUDES_NORDIC_H_
#define INCLUDES_NORDIC_H_

/**************************************************************************************
* nrf_read_register
* Read the register and return the value
*
* @param register - Register from where value is read
* @return - Register value read
**************************************************************************************/
uint8_t nrf_read_register(uint8_t register);

/**************************************************************************************
* nrf_write_register
*  Write to the given register with the data.
*
* @param register - Register to write the value
* @param value - Value to be written in the register
* @return - None
**************************************************************************************/
void nrf_write_register(uint8_t register, uint8_t value);

/**************************************************************************************
* nrf_read_status
* Reads the STATUS register
*
* @return - Value of STATUS register
**************************************************************************************/
uint8_t nrf_read_status();

/**************************************************************************************
* nrf_write_config
* Write to CONFIG register
*
* @param config - Value to be written in CONFIG register
* @return - None
**************************************************************************************/
void nrf_write_config(uint8_t config);

/**************************************************************************************
* nrf_read_config
* Read the CONFIG register
*
* @return - Value of the CONFIG register read
**************************************************************************************/
uint8_t nrf_read_config();

/**************************************************************************************
* nrf_read_rf_setup
* Reads RF_SETUP register
*
* @return - Value of the RF_SETUP register read
**************************************************************************************/
uint8_t nrf_read_rf_setup();

/**************************************************************************************
* nrf_write_rf_setup
* Writes to the RF_SETUP register
*
* @param rf_setup - Value to be written to the RF_SETUP register
* @return - None
**************************************************************************************/
void nrf_write_rf_setup(uint8_t rf_setup);

/**************************************************************************************
* nrf_read_rf_ch
* Reads ??
*
* @return - ??
**************************************************************************************/
uint8_t nrf_read_rf_ch();

/**************************************************************************************
* nrf_write_rf_ch
* Reads ??
*
* @return - ??
**************************************************************************************/
void nrf_write_rf_ch(uint8_t channel);

/**************************************************************************************
* nrf_read_TX_ADDR
* Reads the 8 bytes of the TX_ADDR register
*
* @return - Pointer to the bytes of the TX_ADDR register
**************************************************************************************/
uint8_t * nrf_read_TX_ADDR();

/**************************************************************************************
* nrf_write_TX_ADDR
* Writes the 8 byte TX_ADDR register
*
* @param tx_addr - Pointer to the 8 bytes to be written into the TX_ADDR register
* @return - None
**************************************************************************************/
void nrf_write_TX_ADDR(uint8_t * tx_addr);

/**************************************************************************************
* nrf_read_fifo_status
* Reads FIFO_STATUS register
*
* @return - Value of the FIFO_STATUS register read
**************************************************************************************/
uint8_t nrf_read_fifo_status();

/**************************************************************************************
* nrf_flush_tx_fifo
* Sends the command FLUSH_TX
*
* @return - None
**************************************************************************************/
void nrf_flush_tx_fifo();

/**************************************************************************************
* nrf_flush_rx_fifo
* Sends the command FLUSH_RX
*
* @return - None
**************************************************************************************/
void nrf_flush_rx_fifo();

#endif /* INCLUDES_NORDIC_H_ */
