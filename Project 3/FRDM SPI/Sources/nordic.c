/*
 * nordic.c
 *
 *  Created on: Mar 23, 2017
 *      Author: Priyanka
 */

/* Included libraries */
#include "MKL25Z4.h"
#include "nordic.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void nrf_read_register(uint8_t reg){
	SPI_write_byte(R_REG | reg); 					// Write Command
}
void nrf_write_register(uint8_t reg){
	SPI_write_byte(W_REG | reg);					// Read Command
}

uint8_t nrf_read_status(){
	uint8_t value;
	SS_LOW;											// Make SS line Low
	nrf_read_register(NRF_STATUS_REG);				// Send Read Command for STATUS Register
	value = SPI_write_byte(DUMMY_BYTE);				// Send Dummy Byte
	SS_HIGH;										// Make SS line High
	return value;
}

void nrf_write_config(uint8_t value){
	SS_LOW;														// Make SS line Low
	nrf_write_register(NRF_CONFIG_REG);							// Send Write Command for CONFIG Register
	SPI_write_byte(value);     									// Writing value in CONFIG Register
	SS_HIGH;													// Make SS line High
}

uint8_t nrf_read_config(){
	uint8_t value;
	SS_LOW;														// Make SS line Low
	nrf_read_register(NRF_CONFIG_REG);							// Send Read Command for CONFIG Register
	value = SPI_write_byte(DUMMY_BYTE);							// Send Dummy Byte
	SS_HIGH;													// Make SS line High
	return value;
}

uint8_t nrf_read_rf_setup(){
	uint8_t value;
	SS_LOW;														// Make SS line Low
	nrf_read_register(NRF_RF_SETUP_REG);						// Send Read Command for RF_SETUP Register
	value = SPI_write_byte(DUMMY_BYTE);							// Send Dummy Byte
	SS_HIGH;													// Make SS line High
	return value;
}

void nrf_write_rf_setup(uint8_t value){
	SS_LOW;														// Make SS line Low
	nrf_write_register(NRF_RF_SETUP_REG);						// Send Write Command for RF_SETUP Register
	SPI_write_byte(value);										// Writing 0x02 in RF_SETUP Register
	SS_HIGH;													// Make SS line High
}

uint8_t nrf_read_rf_ch(){
	uint8_t value;
	SS_LOW;														// Make SS line Low
	nrf_read_register(NRF_RF_CH_REG);							// Send Read Command for RF_CH Register
	value = SPI_write_byte(DUMMY_BYTE);							// Send Dummy Byte
	SS_HIGH;													// Make SS line High
	return value;
}
void nrf_write_rf_ch(uint8_t value){
	SS_LOW;														// Make SS line Low
	nrf_write_register(NRF_RF_CH_REG);							// Send Write Command for RF_CH Register
	SPI_write_byte(value);										// Writing value in RF_SETUP Register
	SS_HIGH;													// Make SS line High
}

uint8_t* nrf_read_TX_ADDR(){
	SS_LOW;														// Make SS line Low
	nrf_read_register(NRF_TX_ADDR);								// Send Read Command for TX_ADDR Register
	for(uint8_t i=0; i<5; i++){
		tx_addr[i] = SPI_write_byte(DUMMY_BYTE);				// Send 5 Dummy Byte
	}
	SS_HIGH;												    // Make SS line High
 return tx_addr;
}

void nrf_write_TX_ADDR(){
	uint8_t p[5] = {0xA,0xB,0xC,0xD,0xE};
	SS_LOW;													    // Make SS line Low
	nrf_write_register(NRF_TX_ADDR);							// Send Write Command for TX_ADDR Register
	SPI_send_packet(p, 5);										// Read 5 bytes
	SS_HIGH;												    // Make SS line High
}

uint8_t nrf_read_fifo_status(){
	uint8_t value;
	SS_LOW;													    // Make SS line Low
	nrf_read_register(NRF_FIFO_STATUS_REG);						// Send Read Command for FIFO_STATUS Register
	value = SPI_write_byte(DUMMY_BYTE);						    // Send Dummy Byte
	SS_HIGH;												    // Make SS line High
	return value;
}

void nrf_flush_tx_fifo(){
	SS_LOW;														// Make SS line Low
	SPI_write_byte(NRF_FLUSH_TX_FIFO);							// Send Write Command for FLUSH_TX_FIFO
	SS_HIGH;												    // Make SS line High
}

void nrf_flush_rx_fifo(){
	SS_LOW;														// Make SS line Low
	SPI_write_byte(NRF_FLUSH_RX_FIFO);							// Send Read Command for FLUSH_TX_FIFO
	SS_HIGH;												    // Make SS line High
}





