#ifndef _MESSAGE_H
#define _MESSAGE_H


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "PWM.h"
#include "LED.h"
#include "UART.h"
#include "log.h"

#define MAX_DATA_SIZE 20



typedef enum {

	LED  = 1 ,
	BRIGHTNESS = 2 ,
	SYSTEM_RST = 3 ,              		   // command
	RTC_TIMESTMP = 4

}Cmds;

typedef struct{

	Cmds command;
	uint8_t length;
	uint8_t data[MAX_DATA_SIZE];
	uint16_t checksum;

}CI_Msg;

typedef enum {
	ERROR,
	SUCCESS,
	NULLPOINTER_ERROR
}CI_Msg_Error;

typedef enum{

	LED_ON = 1,
	LED_OFF = 2,
	LED_BRIGHTNESS_CONTROL_RED = 3,
	LED_BRIGHTNESS_CONTROL_GREEN = 4,
	LED_BRIGHTNESS_CONTROL_BLUE = 5,           // data[0]
	SYSTEM_RESET = 6,
	RTC_TIMESTAMP = 7

}LED_OPERATIONS;

typedef enum{

	CHECKSUM_SUCCESS,
	CHECKSUM_FAIL

}checksum_error;


#endif	

