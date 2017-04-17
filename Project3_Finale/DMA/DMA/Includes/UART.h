/***************************************************************************************
* FILENAME: UART.h                                                                     
* OWNER: Akshitha Chanda.							       
* FILE DESCRIPTION: This file is the header file for the function's defined in UART.c  
***************************************************************************************/
#ifndef __UART_H__
#define __UART_H__


#include <stdio.h>
#include <stdint.h>
#include "circbuf.h"
#include "MKL25Z4.h"
#include "log.h"

#define TXBUF_LENGTH 500
#define RXBUF_LENGTH 16

CircBuf *tx_buf,*rx_buf;


#define OVER_SAMPLING_RATIO 16
#define BAUD_RATE 57600

/* Defining macros */
#define UART_NUM_ZERO (0)
#define UART_NUM_ONE (1)
#define UART_NUM_TWO (2)
#define UART_NUM_EIGHT (8)

/*
* UART_e : This enum defines the enum cases for UART operations.
*/
typedef enum {

	eUART_SUCCESS,									/* Successful operation */
	eUART_FAILURE										/* UnSuccessful operation */

}UART_e;


/* Function Prototype Section */

/****************************************************************************
* uart0_config
* Function configures the UART0.

*****************************************************************************/
void uart0_config();


/****************************************************************************
* uart_send_byte
* Function sends the byte through UART.
* @param buf : valid pointer to circular buffer
* @param item : value/item to be added to the circular buffer
* @return_value UART_e : Return's the success and failure case of UART operation 

*****************************************************************************/
UART_e uart_send_byte(uint8_t item);


/****************************************************************************
* uart_send_n_bytes
* Function sends the n byte sequence through UART.
* @param buf : valid pointer to circular buffer
* @param length : number of bytes to be sent through UART
* @return_value UART_e : Return's the success and failure case of UART operation  

*****************************************************************************/
UART_e uart_send_n_bytes(uint8_t* item, uint32_t length);

/****************************************************************************
* uart_receive_byte
* Function receives the byte through UART.
* @param buffer : pointer buffer to store the byte received through UART
* @return_value UART_e : Return's the success and failure case of UART operation  

*****************************************************************************/
UART_e uart_receive_byte();
#endif
