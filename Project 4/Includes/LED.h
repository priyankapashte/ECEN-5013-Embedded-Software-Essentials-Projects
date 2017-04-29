#ifndef _LED_H
#define _LED_H

#include "MKL25Z4.h"

#define OFF    0
#define BLUE   1
#define GREEN  2
#define RED    3


void LED_Initialization(void);

void LED_COLOR_SET(int color);

void LED_BRIGHTNESS_SET(int brightness);


#endif

