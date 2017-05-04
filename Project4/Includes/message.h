#ifndef _MESSAGE_H
#define _MESSAGE_H

/* Including standard libraries */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "MKL25Z4.h"

#define MAX_DATA_SIZE 20

/* Enum defined for brightnrss percentage */

typedef enum{
	ZERO_PERCENT = 0,
	TEN_PERCENT = 188,
	TWENTY_PERCENT = 376,
	THIRTY_PERCENT = 564,
	FORTY_PERCENT = 752,
	FIFTY_PERCENT = 940,
	SIXTY_PERCENT = 1128,
	SEVENTY_PERCENT = 1316,
	EIGHTY_PERCENT = 1504,
	NINTY_PERCENT = 1692,
	HUNDRED_PERCENT = 1875
}Brightness_t;

/* Command enum defined*/

typedef enum{
	LED = 1 ,
	BRIGHTNESS = 2 ,
	SYSTEM_RST = 3 ,              		   // command
	RTC_TIMESTAMP = 4
}Cmds_t;

/* Structure of the command */

typedef struct{
	Cmds_t command;
	uint8_t length;
	uint8_t data[MAX_DATA_SIZE];
	uint16_t checksum;

}CI_Msg_t;

/* Enum for error handling */

typedef enum {
	ERROR,
	//SUCCESS,
	NULLPOINTER_ERROR
}CI_Msg_Error_t;

/* Enum for data[0] */

typedef enum{
	LED_ON = 1,
	LED_OFF = 2,
	LED_BRIGHTNESS_RED = 3,
	LED_BRIGHTNESS_GREEN = 4,
	LED_BRIGHTNESS_BLUE = 5,           // data[0]
	SYSTEM_RESET = 6,
	//RTC_TIMESTAMP = 7
}Led_Operations_t;

/* Enum for error handling of checksum */

typedef enum{
	CHECKSUM_SUCCESS,
	CHECKSUM_FAIL
}Checksum_Error_t;

CI_Msg_Error_t Decode_CI_Msg(CI_Msg_t *message);

#endif	

