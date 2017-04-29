#include "MKL25Z4.h"
#include "PWM.h"

typedef enum{

		RED,
		GREEN,
		BLUE

}LED_color,

typedef enum{

	TEN_PERCENT,
	TWENTY_PERCENT,
	THIRTY_PERCENT,
	FORTY_PERCENT,
	FIFTY_PERCENT,
	SIXTY_PERCENT,
	SEVENTY_PERCENT,
	EIGHT_PERCENT,
	NINTY_PERCENT,
	HUNDRED_PERCENT

}brightness,




void RED_BLUE_GREEN_LED_INIT(){

		SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTB_MASK;
	    PORTB_BASE_PTR->PCR[18]=PORT_PCR_MUX(3);											 /* setting RED LED PTB18 */ 

//	    GPIOB_PDDR= 1<<18;																	 /* Setting PTB18 as output pin */

		PORTB_BASE_PTR->PCR[19]=PORT_PCR_MUX(3);										     /* setting GREEN LED PTB19 */ 

//		GPIOB_PDDR= 1<<19;																	 /* Setting PTB19 as output pin */

		SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTD_MASK;
		PORTD_BASE_PTR->PCR[1] =PORT_PCR_MUX(4);											 /* Setting BLUE LED PTD1 */

//		GPIOB_PDDR= 1<<1;																	 /* Setting PTD1 as output pin */


}

void RED_INIT(){

	    SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK; 					                     /* Setting clock for TPM2 */
		SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);           					                     /* Selecting MCGFLLCLK/2 as counter timer clock  Up to 48 MHz */ 
		TPM2_BASE_PTR->SC = TPM_SC_CMOD(1)  						                         /* CMOD is clock mode selection to 1 */ 
		TPM2_BASE_PTR->SC = TPM_SC_PS(7);								                     /* prescalar to 7 which is  128 for TPM2 */
	    TPM2_BASE_PTR->C0V = 5242;                  										 /* Set PWM Duty Cycle to 50% default */
		TPM2_BASE_PTR->MOD = 10485;                                                          /* settting MOD value 10485 so that PWM set 2KHz  */
		TPM2_BASE_PTR->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK; 			 /* Settting edge selection  for PWM */


}


void GREEN_INIT(){

		SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK; 					                     /* Setting clock for TPM2 */
		SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);           					                     /* Selecting MCGFLLCLK/2 as counter timer clock  Up to 48 MHz */ 
		TPM2_BASE_PTR->SC = TPM_SC_CMOD(1)  						                         /* CMOD is clock mode selection to 1 */ 
		TPM2_BASE_PTR->SC = TPM_SC_PS(7);								                     /* prescalar to 7 which is  128 for TPM2 */
		TPM2_BASE_PTR->C1V = 5242;                  										 /* Set PWM Duty Cycle to 50% default */
		TPM2_BASE_PTR->MOD = 10485;                                                          /* settting MOD value 10485 so that PWM set 2KHz  */
		TPM2_BASE_PTR->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK; 			 /* Settting edge selection for PWM */


}

void BLUE_INIT(){

		SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM0_MASK; 					                     /* Setting clock for TPM2 */
		SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);           					                     /* Selecting MCGFLLCLK/2 as counter timer clock  Up to 48 MHz */ 
		TPM0_BASE_PTR->SC = TPM_SC_CMOD(1)  						                         /* CMOD is clock mode selection to 1 */ 
		TPM0_BASE_PTR->SC = TPM_SC_PS(7);								                     /* prescalar to 7 which is  128 for TPM2 */
		TPM0_BASE_PTR->C1V = 5242;                  										 /* Set PWM Duty Cycle to 50% default */
		TPM0_BASE_PTR->MOD = 10485 ;                                                         /* settting MOD value 10485 so that PWM set 2KHz  */
		TPM0_BASE_PTR->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK; 			 /* Settting edge selection for PWM */


}

void LED_ON(int LED_color){

		if(LED_color == RED)
		{
			    TPM2_BASE_PTR->C0V = 10485;                  								/* Set RED LED to Full brightness */
		}
			else if (LED_color == GREEN){

				TPM2_BASE_PTR->C1V = 10485;                  								/* Set GREEN LED to Full Brighness */

			}

			else if (LED_color == BLUE){

				TPM0_BASE_PTR->MOD = 10485 ;                                                 /*  Set BLUE LED to full brightness  */
			}

}

void LED_OFF(int LED_color){


		if(LED_color == RED)
		{
			    TPM2_BASE_PTR->C0V = 0;                  								/*  Set RED LED to Full brightness */
		}
			else if (LED_color == GREEN){

				TPM2_BASE_PTR->C1V = 0;                  								/*  Set GREEN LED to Full Brighness */

			}

			else if (LED_color == BLUE){

				TPM0_BASE_PTR->MOD = 0 ;                                                /*  Set BLUE LED to full brightness  */
			}


}

void LED_BRIGHTNESS_CONTROL_RED(int brightness){

		TPM2_BASE_PTR->C0V = 1048.5 * brightness;										/* Varying brightness level by selecting int values of brightness from 0 to 10 */

	}

void LED_BRIGHTNESS_CONTROL_GREEN(int brightness){

		TPM2_BASE_PTR->C1V = 1048.5 * brightness;                  						/* Varying brightness level by selecting int values of brightness from 0 to 10 */

}

void LED_BRIGHTNESS_CONTROL_BLUE(int brightness){

		TPM0_BASE_PTR->MOD = 1048.5 * brightness ;                                      /* Varying brightness level by selecting int values of brightness from 0 to 10 */
			
	}



void SYSTEM_RESET(){

	NVIC_SystemReset();																	/* Software Reset */

}

void RTC_TIMESTAMP(){																	/* RTC TimeStamp */

	rtc_init();
	LOG_RAW_INTR(RTC_TSR);

}

