/*
 * led.h
 *
 *  Created on: Apr 29, 2017
 *      Author: Priyanka
 */

#ifndef INCLUDES_LED_H_
#define INCLUDES_LED_H_

#include "MKL25Z4.h"

typedef enum{
		OFF,
		RED,
		GREEN,
		BLUE
}LED_Colour_t;

LED_Colour_t LED_Colour; 			// Set initial color
uint16_t  brightness;				// Set initial brightness

void led_init();
void led_setup(uint8_t character);
void led_control(LED_Colour_t LED_Colour, uint16_t brightness);
void system_reset();

void (*led_control_ptr)(LED_Colour_t, uint16_t);

#endif /* INCLUDES_LED_H_ */
