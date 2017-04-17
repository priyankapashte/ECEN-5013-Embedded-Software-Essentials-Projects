#include "log.h"

#ifdef FRDMWITHCIRC

/********************************************************************************
* FUNCTION DESCRIPTION : Takes a pointer to sequence of bytes and length of bytes 
*********************************************************************************/

logger log_data(CircBuf *buf,uint8_t* data, uint32_t length) {
		for(uint8_t count=0; count<length; count++){
			CB_AddItem(buf,*data);
			data++;
	}
	UART0_C2 |= UART0_C2_TIE_MASK;
		
}

/********************************************************************************
* FUNCTION DESCRIPTION :  Takes a c-string and logs that to the terminal
*********************************************************************************/

logger log_string(CircBuf *buf,uint8_t * string){
		while(*string != '\0'){
			CB_AddItem(buf,*string);
			string++;

		}
		UART0_C2 |= UART0_C2_TIE_MASK;
}

/********************************************************************************
* FUNCTION DESCRIPTION :  Takes a c-string and logs that to the terminal
*********************************************************************************/

logger log_integer(CircBuf *buf,uint8_t num){
		int8_t string_1[32];
		int8_t *temp_1=string_1;
		/* Converting Integer to Ascii */
		my_itoa(temp_1,num,10);
		LOG_RAW_STRING(buf,temp_1);
		
}
#endif
#ifdef FRDMWITHCIRC
logger log_flush(CircBuf *buf){

	/*#ifdef DEBUG
	UART0_C2 = UART0_C2_TIE_MASK;
	#endif*/
	/*uint8_t string_1[32];
	uint8_t *temp;
	temp = string_1;
	while(buf->count != 0){
		CB_RemoveItem(buf,temp);
	}*/

}
#else
logger log_flush(){

	/*#ifdef DEBUG
	UART0_C2 = UART0_C2_TIE_MASK;
	#endif*/
	/*uint8_t string_1[32];
	uint8_t *temp;
	temp = string_1;
	while(buf->count != 0){
		CB_RemoveItem(buf,temp);
	}*/

}
#endif



Binary_logger_e create_log_item(BinaryLogger *log, BinaryLogger_e index,size_t length, uint8_t *payLoad){


	log->logID = index;
	log->logLength = length;
	if(length != 0){
		log->payLoad=(uint8_t *)malloc(length*sizeof(uint8_t));
		uint8_t * temp = log->payLoad;
		if(log->payLoad != 0){

			for(uint8_t count =0; count < length; count++){
				*(temp) = *payLoad;
				payLoad++;
				temp++;
			}
		}
	}
	else{
		*(log->payLoad) = *payLoad;
	}
}


#ifdef FRDMWITHCIRC
Binary_logger_e log_item(CircBuf *buf,BinaryLogger * log){


				LOG_RAW_STRING(buf,"||");
				LOG_RAW_STRING(buf,"Logger ID :");
				LOG_RAW_STRING(buf,log->logID);
				LOG_RAW_STRING(buf,"||");
				LOG_RAW_STRING(buf,"Logger PayLoad :");
				LOG_RAW_STRING(buf,"||");
				if((log->logLength) != 0){

					for(uint8_t count =0; count < log->logLength; count++){
						LOG_RAW_INTR(buf,*(log->payLoad));
						log->payLoad++;
						}
				}
				else{
					LOG_RAW_INTR(buf,*(log->payLoad));
				}
				LOG_RAW_STRING(buf,"||");

}
#else
Binary_logger_e log_item(BinaryLogger * log,Payload_e payload){
				LOG_RAW_STRING("||");
				LOG_RAW_STRING("Logger ID :");
				log_integer(log->logID);
				LOG_RAW_STRING("||");
				LOG_RAW_STRING("Logger PayLoad :");
				LOG_RAW_STRING("||");
				if(payload ==PAYLOAD){
					LOG_RAW_DATA(log->payLoad,log->logLength);
				}
				else{
					LOG_RAW_STRING("0");
				}

				LOG_RAW_STRING("||");
}
#endif



#ifdef  FRDMWITHCIRC
Binary_logger_e destroy_log_item(CircBuf *buf,BinaryLogger * log){

	log->logID =0;
	log->logLength = 0;
	//free(log->payLoad);
	free(log);
	//log_flush(buf);
}
#else
Binary_logger_e destroy_log_item(BinaryLogger * log){

	log->logID =0;
	log->logLength = 0;
	free(log->payLoad);
	free(log);
}
#endif



#ifdef  FRDMWITHOUTCIRC
logger log_data(uint8_t* data, uint32_t length){
	uart_send_n_bytes(data,length);
}

logger log_string(uint8_t * string){
	while(*string != '\0'){
		uart_send_byte(*string);
		string++;
	}
}
	
logger log_integer(uint8_t num){
	int8_t string_1[32];
	int8_t *temp_1=string_1;
	/* Converting Integer to Ascii */
	my_itoa(temp_1,num,10);
	while(*temp_1 != '\0'){
		uart_send_byte(*temp_1);
		temp_1++;
	}
}
#endif


#ifdef HOSTBEAGLE
logger log_data(uint8_t* data, uint32_t length){
		for(uint8_t index=0; index<length; index++){
			printf("%d",data++);
		}
}

logger log_string(uint8_t * string){
	while(*string_1 != '\0'){
			printf("%d",*string_1);
			string_1++;
		}
}
logger log_integer(uint8_t num){
		printf("%d",num);
}
#endif
