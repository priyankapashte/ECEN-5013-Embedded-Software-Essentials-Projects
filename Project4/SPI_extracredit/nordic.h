/**********************************************************
* FILE NAME : nordic.h
* FILE DESCRIPTION : 
* AUTHOR : Priyanka Pashte and Akshitha Chanda
*
************************************************************/


#ifndef _NORDIC_H
#define _NORDIC_H

/* Inclu*/
#include <stdio.h>
#include <stdint.h>
#include "unistd.h"
#include "spi.h"
#include "gpio.h"

/* Macros */
#define NRF_CONFIG_REG			(0x00)
#define NRF_TXADDR_REG			(0x10)
#define NRF_EN_AA_REG			(0x01)
#define NRF_EN_RXADDR_REG		(0x02)
#define NRF_SETUP_AW_REG		(0x03)
#define NRF_SETUP_RETR_REG		(0x04)
#define NRF_RF_CH_REG			(0x05)
#define NRF_RF_SETUP_REG		(0x06)
#define NRF_STATUS_REG			(0x07)
#define RX_ADDR_P0_REG			(0x0A)
#define NRF_TX_ADDR				(0x10)
#define NRF_FIFO_STATUS_REG		(0x17)
#define NRF_PIPESIZE			(0X11)
#define NRF_ENRXADDR			(0x02)
#define W_TXPAYLOAD				(0xA0)
#define R_RXPAYLOAD				(0x61)

#define NRF_R_REGISTER			(0x00)		
#define NRF_W_REGISTER			(0x20) 
#define DUMMY_BYTE				(0xFF) 
#define NRF_FLUSH_TX			(0xE1)
#define NRF_FLUSH_RX			(0xE2)

/* Function Prototype Section */

/*****************************************************************************
* nrf_read_register
* Function reads the value of given input register.
* @param registerAddr: Register address value.
*
******************************************************************************/
uint8_t nrf_read_register(uint8_t registerAddr);

/*****************************************************************************
* nrf_write_register
* Function writes the value to the given input register.
* @param registerAddr: Register address value.
* @param value: Input value to be written into the given register.
*
******************************************************************************/
void nrf_write_register(uint8_t registerAddr, uint8_t value);

/*****************************************************************************
* nrf_read_status
* Function for reading the status register value.
*
******************************************************************************/
uint8_t nrf_read_status();

/*****************************************************************************
* nrf_write_config
* Function writes the value to the config register.
* @param configValue: Input value to be written into the config register.
*
******************************************************************************/
void nrf_write_config(uint8_t configValue);

/*****************************************************************************
* nrf_read_config
* Function for reading the config register value.
*
******************************************************************************/
uint8_t nrf_read_config();

/*****************************************************************************
* nrf_read_rf_setup
* Function for reading the RF setup register value.
*
******************************************************************************/
uint8_t nrf_read_rf_setup();

/*****************************************************************************
* nrf_write_rf_setup
* Function writes the value to the RF setup register.
* @param config: Input value to be written into the RF setup register.
*
******************************************************************************/
void nrf_write_rf_setup(uint8_t config);

/*****************************************************************************
* nrf_read_rf_ch
* Function for reading the RF channel value.
*
******************************************************************************/
uint8_t nrf_read_rf_ch();

/*****************************************************************************
* nrf_write_rf_ch
* Function writes the channel value to the RF channel register.
* @param channel: Input value for RF channel.
*
******************************************************************************/
void nrf_write_rf_ch(uint8_t channel);

/*****************************************************************************
* nrf_read_TX_ADDR
* Function reads the values of TX_ADDR register.
* @param data: Pointer storing the received value from TX_ADDR register.
*
******************************************************************************/
void nrf_read_TX_ADDR(uint8_t * data);

/*****************************************************************************
* nrf_write_TX_ADDR
* Function writes the input data into the TX_ADDR register.
* @param tx_ADDR: Pointer storing the input data to be written into TX_ADDR register
*
******************************************************************************/
void nrf_write_TX_ADDR(uint8_t * tx_addr);

/*****************************************************************************
* nrf_read_fifo_status
* Function for reading FIFO status.
*
******************************************************************************/
uint8_t nrf_read_fifo_status();

/*****************************************************************************
* nrf_flush_tx_fifo
* Function for flushing out the TX_FIFO register.
*
******************************************************************************/
void nrf_flush_tx_fifo();

/*****************************************************************************
* nrf_flush_rx_fifo
* Function for flushing out the RX_FIFO register.
*
******************************************************************************/
void nrf_flush_rx_fifo();

#endif
