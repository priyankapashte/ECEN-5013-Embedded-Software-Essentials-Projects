/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MKL25Z4.h"
#include "uart.h"
#include "log.h"
#include "analysis.h"
#include "string.h"
#include "rtc.h"
#include "spi.h"
#include "nordic.h"
#include "led.h"
#include "message.h"

#define FRDM

#define NUM_CHAR_RECV 16

b_logger *log;
CI_Msg_t *CI_Msg;



int main(void)
{
	CB_e error_code;

	LED_Colour = RED;
	brightness = 100;
	uint8_t x, checksum=0;
	uint8_t char_recv[NUM_CHAR_RECV];
	uint8_t data;
	analysis_t *analysis;
  	char error_message1[100] = "Malloc failed";
 	uint8_t config_val, status_val, *tx_addr_val, rf_setup_val, rf_ch_val, fifo_status_val, tx_addr[5];
 	led_func_ptr[0] = Red_Led_Control;
 	led_func_ptr[1] = Green_Led_Control;
 	led_func_ptr[2] = Blue_Led_Control;
 	led_control_ptr = &led_control;

	CI_Msg = (CI_Msg_t*)malloc(sizeof(CI_Msg_t));
	log = (b_logger*)malloc(sizeof(b_logger));

	log_initialize();

	b_logger *log2 = NULL;

 	led_init();

 	LOG_ITEM(log,LOGGER_INITIALIZED,0,0,0);

 	LOG_ITEM(log, GPIO_INITIALIZED, 0, 0, 0);

 	LOG_ITEM(log, SYSTEM_INITIALIZED, 0, 0, 0);

 	while(1)
 	{
/* 		error_code = CB_IsBufferEmpty(&rx_buf);
 		if(error_code == CB_Not_Empty)
 		{
 			data = CB_RemoveItem(&rx_buf);
 			led_setup(data);
 		}*/
		error_code = CB_IsBufferEmpty(&rx_buf);
		if(error_code == CB_Not_Empty && rx_buf.count == 2)
		{
			CI_Msg->command = CB_RemoveItem(&rx_buf);
			checksum ^= CI_Msg->command;
			CI_Msg->length = CB_RemoveItem(&rx_buf);
			checksum ^= CI_Msg->length;
			while(1)
			{
				error_code = CB_IsBufferEmpty(&rx_buf);
				if(error_code == CB_Not_Empty && rx_buf.count == CI_Msg->length+1)
				{
					for(int i=0; i<CI_Msg->length; i++)
					{
						CI_Msg->data[i] = CB_RemoveItem(&rx_buf);
						checksum ^= CI_Msg->data[i];
					}
					CI_Msg->checksum = CB_RemoveItem(&rx_buf);
					break;
				}

			}
			LOG_RAW_INTR(CI_Msg->command);
			LOG_RAW_INTR(CI_Msg->length);
			for(int i=0; i<CI_Msg->length; i++)
				LOG_RAW_INTR(CI_Msg->data[i]);
			LOG_RAW_INTR(CI_Msg->checksum);
			if(checksum == CI_Msg->checksum)
			{
				Decode_CI_Msg(CI_Msg);
			}
			else
			{
				LOG_RAW_STRING("Checksum does not match. Enter the command again.\n");
			}
			checksum = 0;
		}
 	}


/* 	SPI_init();


	status_val = nrf_read_status();

	nrf_write_rf_setup(0x02);
	rf_setup_val = nrf_read_rf_setup();
	nrf_write_config(0x04);
		config_val = nrf_read_config();
	nrf_write_rf_ch(0x05);
	rf_ch_val = nrf_read_rf_ch();
	fifo_status_val = nrf_read_fifo_status();
	nrf_write_TX_ADDR();
	tx_addr_val = nrf_read_TX_ADDR();

	for(uint8_t i=0; i<5; i++)
	{
		tx_addr[i] = *tx_addr_val;
		tx_addr_val++;
	}
	


/*	if(log2 == NULL){
		//create_log_item(&log,LOG_ERROR,strlen(error_message1),&error_message1);
		//log_item(&log,1);
		LOG_ITEM(log, LOG_ERROR, strlen(error_message1), &error_message1, 1);

	}*/
/*	LOG_ITEM(log, LOGGER_INITIALIZED, 0, 0, 0 );

	//clock_config();
	rtc_init();

	while(1)
	{

	}

	//create_log_item(&log,GPIO_INITIALIZED,0,0);
	//log_item(&log);
	LOG_ITEM(log, GPIO_INITIALIZED, 0, 0, 0);

	//log = (b_logger*)malloc(sizeof(b_logger));
	//create_log_item(&log,SYSTEM_INITIALIZED,0,0);
	//log_item(&log);
	LOG_ITEM(log, SYSTEM_INITIALIZED, 0, 0, 0);


	while(1){

		/*if (interrupt){
					LOG_RAW_INTR(seconds);
					interrupt = 0;
				}*/

/*		error_code = CB_IsBufferEmpty(&rx_buf);
		if(error_code==CB_Not_Empty && rx_buf.count == NUM_CHAR_RECV){

			analysis = (analysis_t *)malloc(sizeof(analysis_t));
			analyze_bytes(&rx_buf, analysis, NUM_CHAR_RECV);

			LOG_ITEM(log, DATA_ANALYSIS_STARTED, 0, 0, 0);

			for(uint8_t i=0; i<16; i++){
				data = CB_RemoveItem(&rx_buf);
				char_recv[i] = data;
			}

			//create_log_item(&log,DATA_RECEIVED,16,&char_recv);
			//log_item(&log);
			LOG_ITEM(log, DATA_RECEIVED, NUM_CHAR_RECV, &char_recv, 1);

			//create_log_item(&log,DATA_ALPHA_COUNT,1,&analysis->alpha);
			//log_item(&log);
			LOG_ITEM(log, DATA_ALPHA_COUNT, 1, &analysis->alpha, 0);

			//create_log_item(&log,DATA_NUMERIC_COUNT,1,&analysis->num);
			//log_item(&log);
			LOG_ITEM(log, DATA_NUMERIC_COUNT, 1, &analysis->num, 0);

			//create_log_item(&log,DATA_PUNCTUATION_COUNT,1,&analysis->punc);
			//log_item(&log);
			LOG_ITEM(log, DATA_PUNCTUATION_COUNT, 1, &analysis->punc, 0);

			//create_log_item(&log,DATA_MISC_COUNT,1,&analysis->misc);
			//log_item(&log);
			LOG_ITEM(log, DATA_MISC_COUNT, 1, &analysis->misc, 0);

			//create_log_item(&log,DATA_ANALYSIS_COMPLETED,0,0);
			//log_item(&log,0);
			LOG_ITEM(log, DATA_ANALYSIS_COMPLETED, 0, 0, 0);
		}
	}

	destroy_log_item(&log);*/

    /* This for loop should be replaced. By default this loop allows a single stepping. */
	// for (;;) {
    // uart_send_byte('P');
    // x = uart_receive_byte();
    // uart_send_byte(x);
	//}
    return 0;
}

void RTC_Seconds_IRQHandler()
{
	START_CRITICAL();
	uint32_t time = RTC_TSR;
	LOG_ITEM(log, HEARTBEAT, 1, &time, 0);
	time_calc();
	LOG_RAW_STRING(" Date: ");
	LOG_RAW_INTR(myrtc.day);
	LOG_RAW_STRING("/");
	LOG_RAW_INTR(myrtc.month);
	LOG_RAW_STRING("/");
	LOG_RAW_INTR(myrtc.year);
	LOG_RAW_STRING(" Time: ");
	LOG_RAW_INTR(myrtc.hours);
	LOG_RAW_STRING(":");
	LOG_RAW_INTR(myrtc.minutes);
	LOG_RAW_STRING(":");
	LOG_RAW_INTR(myrtc.seconds);
	STOP_CRITICAL();
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
