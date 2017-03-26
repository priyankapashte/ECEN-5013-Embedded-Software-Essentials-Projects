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
	SPI_write_byte(R_REG | reg); 		// Write Command
}
void nrf_write_register(uint8_t reg){
	SPI_write_byte(W_REG | reg);		// Read Command
}

uint8_t nrf_read_status(){
	uint8_t value;
	SS_LOW;
	nrf_read_register(NRF_STATUS_REG);
	SPI_write_byte(0xFF);
	value = SPI_read_byte();
	SS_HIGH;
	return value;
}

void nrf_write_config(){
	SS_LOW;
	nrf_write_register(NRF_CONFIG_REG);
	SPI_write_byte(NRF_CONFIG_PRIM_RX | NRF_CONFIG_PWR_UP);    // Writing 0x03 in CONFIG Register
	SS_HIGH;
}
uint8_t nrf_read_config(){
	uint8_t value;
	SS_LOW;
	nrf_read_register(NRF_CONFIG_REG);
	SPI_write_byte(0xFF);
	value = SPI_read_byte();
	SS_HIGH;
	return value;
}

uint8_t nrf_read_rf_setup(){
	uint8_t value;
	SS_LOW;
	nrf_read_register(NRF_RF_SETUP_REG);
	SPI_write_byte(0xFF);
	value = SPI_read_byte();
	SS_HIGH;
	return value;
}

void nrf_write_rf_setup(uint8_t config){
	SS_LOW;
	nrf_write_register(NRF_RF_SETUP_REG);
	SPI_write_byte(0x02);
	SS_HIGH;
}

uint8_t nrf_read_rf_ch(){
	uint8_t value;
	SS_LOW;
	nrf_read_register(NRF_RF_CH_REG);
	SPI_write_byte(0xFF);
	value = SPI_read_byte();
	SS_HIGH;
	return value;
}
void nrf_write_rf_ch(uint8_t channel){
	SS_LOW;
	nrf_write_register(NRF_RF_CH_REG);
	SPI_write_byte(0x05);
	SS_HIGH;
}

uint8_t* nrf_read_TX_ADDR(){
	SS_LOW;
	nrf_read_register(NRF_TX_ADDR);
	for(uint8_t i=0; i<5; i++)
	{
		SPI_write_byte(0xFF);
		tx_addr[i] = SPI_read_byte();
	}
	SS_HIGH;
 return tx_addr;
}

void nrf_write_TX_ADDR(uint8_t * tx_addr){
	SS_LOW;
	nrf_write_register(NRF_TX_ADDR);
	for(uint8_t i=0; i<5; i++)
	{
		SPI_write_byte(0xBB);
	}
	SS_HIGH;
}

uint8_t nrf_read_fifo_status(){
	uint8_t value;
	SS_LOW;
	nrf_read_register(NRF_FIFO_STATUS_REG);
	SPI_write_byte(0xFF);
	value = SPI_read_byte();
	SS_HIGH;
	return value;
}

void nrf_flush_tx_fifo(){
	SS_LOW;
	SPI_write_byte(NRF_FLUSH_TX_FIFO);
	SS_HIGH;
}

void nrf_flush_rx_fifo(){
	SS_LOW;
	SPI_write_byte(NRF_FLUSH_RX_FIFO);
	SS_HIGH;
}





