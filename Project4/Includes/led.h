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

/**************************************************************************************
* led_init
* Initializes led ports and sets clocks
*
**************************************************************************************/

void led_init();

/**************************************************************************************
* led_setup()
* takes input  character + and - to increase and decrease brightness
 * 1,2,3 character inputs are or Red, Blue and Green color
* @param character - character input

**************************************************************************************/

void led_setup(uint8_t character);

/**************************************************************************************
* led_control()
* takes inputs enum LED_Colour_t and uint16_t brightness
* 1,2,3 character inputs are or Red, Blue and Green color
* @param character - character input

**************************************************************************************/

void led_control(LED_Colour_t LED_Colour, uint16_t brightness);

/**************************************************************************************
* system_reset()
* Resets the system
*
**************************************************************************************/

void system_reset();

/**************************************************************************************
* Function Pointer
*
**************************************************************************************/

void (*led_control_ptr)(LED_Colour_t, uint16_t);

/**************************************************************************************
* Red_Led_Control()
* Function controls the brightness of the red led taking input as brightness
* @param brightness : Input brightness
**************************************************************************************/

void Red_Led_Control(uint16_t brightness);

/**************************************************************************************
* Green_Led_Control()
* Function controls the brightness of the green led taking input as brightness
* @param brightness : Input brightness
**************************************************************************************/

void Green_Led_Control(uint16_t brightness);

/**************************************************************************************
* Blue_Led_Control()
* Function controls the brightness of the blue led taking input as brightness
* @param brightness : Input brightness
**************************************************************************************/

void Blue_Led_Control(uint16_t brightness);

/**************************************************************************************
* Led_off()
* Function to switch off the LED
*
**************************************************************************************/

void Led_Off();

/**************************************************************************************
*
* Function pointer for led control
*
**************************************************************************************/
void (*led_func_ptr[3])(int);

#endif /* INCLUDES_LED_H_ */
