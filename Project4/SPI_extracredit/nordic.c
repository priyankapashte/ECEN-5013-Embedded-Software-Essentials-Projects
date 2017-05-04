/* Included Header Files */
#include "nordic.h"

/* Macros definition */
#define TX_ADDR_SIZE (5)


void nrf_write_config(uint8_t value){

	nrf_cs_low();
	nrf_write_register(NRF_CONFIG_REG,value);  
	nrf_cs_high();
}

uint8_t nrf_read_config(){

	uint8_t value;
	nrf_cs_low();
	value = nrf_read_register(NRF_CONFIG_REG); 
	nrf_cs_high();
	return value;
}

void nrf_write_register(uint8_t reg, uint8_t value){

	uint8_t temp = (NRF_W_REGISTER|reg);
	write(fd,&temp,sizeof(temp)/sizeof(uint8_t));
	write(fd,&value,sizeof(value)/sizeof(uint8_t));

}

uint8_t nrf_read_register(uint8_t registerAddr){

	uint8_t value;
	uint8_t dummy = DUMMY_BYTE;
	uint8_t temp = (NRF_R_REGISTER|registerAddr);
	write(fd,&temp,sizeof(temp)/sizeof(uint8_t));
	write(fd,&dummy,sizeof(dummy)/sizeof(uint8_t));
	read(fd,&value,1);						
	return value;
}

uint8_t nrf_read_rf_setup(){

	uint8_t value;
	nrf_cs_low();
	value = nrf_read_register(NRF_RF_SETUP_REG);
	nrf_cs_high();
	return value;
}

void nrf_write_rf_setup(uint8_t value){
	nrf_cs_low();
	nrf_write_register(NRF_RF_SETUP_REG,value); /* config value NORDIC_RF_DR_ONE | NORDIC_RF_PWR_ZERO | NORDIC_LNA_HCURR(1)-Setting a data rate of 1 Mbps, transmit power of 0dBm and the low power gain */
	nrf_cs_high();
}

uint8_t nrf_read_rf_ch(){
	uint8_t value;
	nrf_cs_low();
	value = nrf_read_register(NRF_RF_CH_REG);
	nrf_cs_high();
	return value;
}

void nrf_write_rf_ch(uint8_t value){
	nrf_cs_low();
	nrf_write_register(NRF_RF_CH_REG,value);			 /* config value channel is RF_CHANNEL=2 */
	nrf_cs_high();
}

void nrf_read_TX_ADDR(uint8_t *value){

	uint8_t dummy = DUMMY_BYTE;
	uint8_t temp = (NRF_R_REGISTER|NRF_TX_ADDR);
	nrf_cs_low();
	write(fd,&temp,sizeof(temp)/sizeof(uint8_t));
	for(uint8_t i=0; i<TX_ADDR_SIZE; i++){
		write(fd,&dummy,sizeof(dummy)/sizeof(uint8_t));
		read(fd,value,1);				/* To read the value, NOP command or 0xFF has to be sent */
		value++;
	}
	nrf_cs_high();
}

void nrf_write_TX_ADDR(uint8_t *value){

	uint8_t temp = (NRF_W_REGISTER|NRF_TX_ADDR);
	nrf_cs_low();
	write(fd,&temp,sizeof(temp)/sizeof(uint8_t));
	for(uint8_t i=0; i<TX_ADDR_SIZE; i++){
		write(fd,value,sizeof(*value)/sizeof(uint8_t));
		value++;
	}
	nrf_cs_high();
}


uint8_t nrf_read_status(){
	
	uint8_t value;
	nrf_cs_low();
	value = nrf_read_register(NRF_STATUS_REG);
	nrf_cs_high();
	return value;
}


uint8_t nrf_read_fifo_status(){
	
	uint8_t value;
	nrf_cs_low();
	value = nrf_read_register(NRF_FIFO_STATUS_REG);
	nrf_cs_high();
	return value;
}


