/**********************************************************
* FILE NAME : timer.c
* FILE DESCRIPTION : 
* AUTHOR : Akshitha Chanda
*
************************************************************/

volatile uint32_t count = 0;


void start_timer(void){

	SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;			/* Enabling  TPM0 Clock  */
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);           /* Selecting MCGFLLCLK/2 as counter timer clock  Up to 48 MHz */ 

	TPM0_SC = 0;                                /* clearing out the  timer control registers */
	TPM0_SC = TPM_SC_PS(0);						/* Setting prescalar to one when counter is disabled */

	TPM0->MOD = 65535;                          /* Setting counter for 10us */

	TPM0_SC |= TPM_SC_TOIE_MASK;				/* Enabling Interrupt for Timer overflow */

	TPM0->CNT = 0;                              /* Reset the CNT register */

	TPM0->SC = 0X00000080;                      /* Enabling TPM counter */

	NVIC_EnableIRQ(TPM0_IRQn);                  /* Enabling interrupt register in NVIC */



}

void stop_timer(void){

	float time = 0.0;                           /* Defining time variable which accounts for time spent for clock cycles */
	uint32_t total_clock_cycles = 0; 
	uint32_t clock_cycles = TPM0->CNT;          /* Defining clock_cycles variable which is TPM0->CNT count over the overflow */

	total_clock_cycles = count*65535 + clock_cycles; /* Calculating the total number of clock cycles including overflow count and TPM0->CNT */

	time = total_clock_cycles/21;               /* We get time spent in micro seconds and 21 MHz is the clock frequency */

	TPM0->SC = 0;                               /* Clearing out control register */
	printf("%.8f\n", time);                     /* Printing time spent */


}

void TPM0_IRQHandler(void){

	count++;  									/* incrementing the overflow count */
	TPM0_SC |= TPM_SC_TOF_MASK;                 /* clearing the overflow mask */

}