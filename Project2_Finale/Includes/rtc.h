/*
 * rtc.h
 *
 *  Created on: Mar 28, 2017
 *      Author: Priyanka
 */

#ifndef INCLUDES_RTC_H_
#define INCLUDES_RTC_H_

/* Included libraries */
#include "MKL25Z4.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define START_CRITICAL() 	__disable_irq()
#define STOP_CRITICAL()  	__enable_irq()

typedef struct myrtc_t {
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    int16_t timezone;
}rtc;

struct myrtc_t myrtc;
uint32_t rtc_time;

void rtc_init();

uint32_t get_unix_time(void);

void calculate_date(void);

uint8_t get_rtc_seconds(void);

uint8_t get_rtc_minutes(void);

uint8_t get_rtc_hours(void);

uint16_t get_rtc_year(void);

uint8_t get_rtc_month(void);

uint8_t get_rtc_day(void);

void set_unix_time(uint32_t time);


#endif /* INCLUDES_RTC_H_ */
