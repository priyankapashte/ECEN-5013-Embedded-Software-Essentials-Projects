/*
 * led.c
 *
 *  Created on: Apr 29, 2017
 *      Author: Priyanka
 */

#include "led.h"

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

void led_control(LED_Colour_t LED_Colour, uint16_t brightness)
{
	if(LED_Colour == RED)
	{
		TPM2_BASE_PTR->CONTROLS[0].CnV = brightness; 	// Channel value for RED LEDColour with brightness value
		TPM2_BASE_PTR->CONTROLS[1].CnV = 0;				// Channel value for GREEN LEDColour with brightness value as 0
		TPM0_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for BLUE LEDColour with brightness value as 0
	}
	else if(LED_Colour == GREEN)
	{
		TPM2_BASE_PTR->CONTROLS[1].CnV = brightness; 	// Channel value for GREEN LEDColour with brightness value
		TPM2_BASE_PTR->CONTROLS[0].CnV = 0; 			// Channel value for RED LEDColour with brightness value as 0
		TPM0_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for BLUE LEDColour with brightness value as 0
	}
	else if(LED_Colour == BLUE)
	{
		TPM0_BASE_PTR->CONTROLS[1].CnV = brightness; 	// Channel value for BLUE LEDColour with brightness value
		TPM2_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for GREEN LEDColour with brightness value as 0
		TPM2_BASE_PTR->CONTROLS[0].CnV = 0; 			// Channel value for RED LEDColour with brightness value as 0
	}
	else if(LED_Colour == OFF)
	{
		TPM0_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for BLUE LEDColour with brightness value
		TPM2_BASE_PTR->CONTROLS[1].CnV = 0; 			// Channel value for GREEN LEDColour with brightness value as 0
		TPM2_BASE_PTR->CONTROLS[0].CnV = 0; 			// Channel value for RED LEDColour with brightness value as 0
	}
}

void system_reset(){

	NVIC_SystemReset();																	/* Software Reset */

}

