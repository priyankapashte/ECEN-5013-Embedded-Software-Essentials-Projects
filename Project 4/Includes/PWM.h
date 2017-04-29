#ifndef _PWM_H
#define _PWM_H

#include "MKL25Z4.h"


void RED_BLUE_GREEN_LED_INIT();

void RED_INIT();

void GREEN_INIT();

void BLUE_INIT();

void LED_ON(int LED_color);

void LED_OFF(int LED_color);

void LED_BRIGHTNESS_CONTROL_RED(int brightness);

void LED_BRIGHTNESS_CONTROL_GREEN(int brightness);

void LED_BRIGHTNESS_CONTROL_BLUE(int brightness);

void SYSTEM_RESET(void);

void RTC_TIMESTAMP(void);


#endif




