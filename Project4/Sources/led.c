/*
 * led.c
 *
 *  Created on: Apr 29, 2017
 *      Author: Priyanka
 */

/*******************************************************************************************
 *  AUTHOR : Akshitha Chanda and Priyanka Pashte
 *  FILE NAME : LED.c
 *  FILE DESCRIPTION : This file consists of the led_init(), led_setup(), led_control(),
 *  system_reset(), led_control_red(), led_control_blue(), led_cotrol_green(), led_off().
 *******************************************************************************************/
#include "led.h"

/*********************************************************************************************
 * FILE DESCRIPTION : led_init() function enables ports PORTB, PORTD and sets pins for Red, Blue, Green LED
 * and setting mode selection to edge aligned PWM
 *********************************************************************************************/

void led_init()
{
	SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTB_MASK;				// Clock select for PORTB, Enables PORTB
	SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTD_MASK;				// Clock select for PORTD, Enables PORTD

	PORTB_BASE_PTR->PCR[18]=PORT_PCR_MUX(3);				// Setting RED LED PTB18
	PORTB_BASE_PTR->PCR[19]=PORT_PCR_MUX(3);				// Setting GREEN LED PTB19
	PORTD_BASE_PTR->PCR[1] =PORT_PCR_MUX(4);				// Setting BLUE LED PTD1

	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM0_MASK; 			// Setting clock for TPM0
	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK; 			// Setting clock for TPM2
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);           			// Selecting MCGFLLCLK/2 as counter timer clock  Up to 48 MHz

	TPM0_SC = TPM_SC_CMOD(1) |TPM_SC_PS(7); 				// CMOD is clock mode selection to 1 amd prescalar to 1 i.e 128 for TPM0
	TPM2_SC = TPM_SC_CMOD(1) |TPM_SC_PS(7); 				// CMOD is clock mode selection to 1 amd prescalar to 1 i.e 128 for TPM2

	TPM0_MOD = 1875;										// Setting MOD value 1875, timer counter is set to MOD value when reaches 0
	TPM2_MOD = 1875;                                        // Setting MOD value 1875, timer counter is set to MOD value when reaches 0

    // Set mode selection to edge aligned PWM
    TPM2_BASE_PTR->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK;
    TPM2_BASE_PTR->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK;
    TPM0_BASE_PTR->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK;
}

/*********************************************************************************************
 * FILE DESCRIPTION : led_setup() take input character + and - to increase and decrease brightness
 * 1,2,3 character inputs are or Red, Blue and Green color
 *********************************************************************************************/

void led_setup(uint8_t character)
{
    if(character == '+' && brightness < 1875)
    {
    	brightness += 100;
    }
    else if(character=='-' && brightness > 0)
    {
        brightness -= 100;
    }
    else if(character == '1')
    {
    	LED_Colour = RED;
    }
    else if(character == '2')
    {
    	LED_Colour = GREEN;
    }
    else if(character == '3')
	{
		LED_Colour = BLUE;
	}
    led_control(LED_Colour, brightness); // Call to LED function
}

/*********************************************************************************************
 * FILE DESCRIPTION : led_control() take input color and brightness
 *
 *********************************************************************************************/

void led_control(LED_Colour_t LED_Colour, uint16_t brightness)
{
	if(LED_Colour == RED)
	{
		 (*led_func_ptr[0])(brightness);
	}
	else if(LED_Colour == GREEN)
	{
		(*led_func_ptr[1])(brightness);
	}
	else if(LED_Colour == BLUE)
	{
		(*led_func_ptr[2])(brightness);
	}
	else if(LED_Colour == OFF)
	{
		Led_Off();
	}
}

/*********************************************************************************************
 * FILE DESCRIPTION : system_reset() : It resets all registers
 *
 *********************************************************************************************/

void system_reset(){

	NVIC_SystemReset();																	/* Software Reset */

}

void Red_Led_Control(uint16_t brightness)
{
	TPM2_BASE_PTR->CONTROLS[0].CnV = brightness; 	// Channel value for RED LEDColour with brightness value
	TPM2_BASE_PTR->CONTROLS[1].CnV = 0;				// Channel value for GREEN LEDColour with brightness value as 0
	TPM0_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for BLUE LEDColour with brightness value as 0
}

void Green_Led_Control(uint16_t brightness)
{
	TPM2_BASE_PTR->CONTROLS[1].CnV = brightness; 	// Channel value for GREEN LEDColour with brightness value
	TPM2_BASE_PTR->CONTROLS[0].CnV = 0; 			// Channel value for RED LEDColour with brightness value as 0
	TPM0_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for BLUE LEDColour with brightness value as 0
}

void Blue_Led_Control(uint16_t brightness)
{
	TPM0_BASE_PTR->CONTROLS[1].CnV = brightness; 	// Channel value for BLUE LEDColour with brightness value
	TPM2_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for GREEN LEDColour with brightness value as 0
	TPM2_BASE_PTR->CONTROLS[0].CnV = 0; 			// Channel value for RED LEDColour with brightness value as 0
}

void Led_Off()
{
	TPM0_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for BLUE LEDColour with brightness value
	TPM2_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for GREEN LEDColour with brightness value as 0
	TPM2_BASE_PTR->CONTROLS[0].CnV = 0; 			// Channel value for RED LEDColour with brightness value as 0
}

