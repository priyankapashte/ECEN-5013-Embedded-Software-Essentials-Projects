#include <stdint.h>
#include <stdio.h>
#include "nordic.h"
#include "spi.h"
#include "gpio.h"
#include <unistd.h>


int main(){ 

  uint8_t tx_addr_val[5]={1,2,3,4,5};

  fd = SPI_open(1,0);
  SPI_setMaxFrequency(fd,1000000);
  SPI_setClockMode(fd,0);
  SPI_disableCS(fd);
  SPI_enable3Wire(fd);
  SPI_setBitOrder(fd,0);
  SPI_setBitsPerWord(fd,8);

  GPIO_nrf_init();                   
  uint8_t config_val, status_val, rf_setup_val, rf_ch_val, fifo_status_val, tx_addr[5];

  nrf_write_rf_setup(0x02);
  rf_setup_val = nrf_read_rf_setup();
  printf("NRF RF Setup Register: %x \n",rf_setup_val);

  status_val = nrf_read_status();
  printf("NRF Status Register: %x \n",status_val);

  nrf_write_config(0x03);
  config_val = nrf_read_config();
  printf("NRF Config Register: %x \n",config_val);

  nrf_write_rf_ch(0x5);
  rf_ch_val = nrf_read_rf_ch();
  printf("NRF RF Channel Register: %x \n",rf_ch_val);
  
  uint8_t *src = tx_addr_val; 
  uint8_t *dst = tx_addr;
  nrf_write_TX_ADDR(src);
  nrf_read_TX_ADDR(dst);

  for(uint8_t i=0; i<5; i++){
    printf("TX_ADDR[%d] %x \n",i,tx_addr[i]);
  }
  
  fifo_status_val = nrf_read_fifo_status();
  printf("fifostatus_value:: %x \n",fifo_status_val);
  
  return 0;

}
