/* Headers section */
#include "gpio.h"
#include <unistd.h>

uint8_t CSn = 117;				// GPIO pin on BBB for CSn

void GPIO_nrf_init(){

  	FILE *f;
	f = fopen("/sys/class/gpio/export", "w");
	fprintf(f, "%d\n", CSn);
	fclose(f);

	char file[128];
	sprintf(file, "/sys/class/gpio/gpio%d/direction", CSn);
	f = fopen(file, "w");
	fprintf(f, "out\n");
	fclose(f);
	
}

void nrf_cs_low(){
	
	FILE *cs_low;
	char s1[128];
	sprintf(s1, "/sys/class/gpio/gpio%d/value", CSn);
	cs_low = fopen(s1, "w");
	fprintf(cs_low, "0\n");
	fclose(cs_low);
}

void nrf_cs_high(){

	FILE *cs_high;
	char s2[128];
	sprintf(s2, "/sys/class/gpio/gpio%d/value", CSn);
	cs_high = fopen(s2, "w");
	fprintf(cs_high, "1\n");
	fclose(cs_high);

}
