
#ifndef __LOG_H_
#define __LOG_H_

#include <stdint.h>
#include "UART.h"

#define FRDMWITHOUTCIRC


typedef struct BinaryLogger_t {

	uint8_t logID;
	size_t logLength;
	uint8_t * payLoad;

}BinaryLogger;

typedef enum {

	LOGGER_INITIALZED,
	GPIO_INITIALZED,
	SYSTEM_INITIALIZED,
	SYSTEM_HALTED,
	INFO,
	WARNING,
	ERROR,
	DATA_RECEIVED,
	DATA_ANALYSIS_STARTED,
	DATA_ALPHA_COUNT,
	DATA_NUMERIC_COUNT,
	DATA_PUNCTUATION_COUNT,
	DATA_MISC_COUNT,
	DATA_ANALYSIS_COMPLETED

}BinaryLogger_e;

typedef enum {

	NO_PAYLOAD,
	PAYLOAD

}Payload_e;

typedef enum {

	BINLOG_Success,
	BINLOG_Error

} Binary_logger_e;

typedef enum logger_t {

	LOG_Success,
	LOG_Error

} logger;
#ifdef FRDMWITHCIRC
#define LOG_RAW_DATA(buf,data, length) (log_data((CircBuf *)buf,(uint8_t *)data, length))
#define LOG_RAW_STRING(buf,string) (log_string((CircBuf *)buf,(uint8_t *)string))
#define LOG_RAW_INTR(buf,num) (log_integer((CircBuf *)buf,num))
#define LOG_RAW_FLUSH(buf) (log_flush((CircBuf *)buf))
#define LOG_ITEM(log, index, length, payLoad,buf) (create_log_item(log, index, length, (uint8_t*) payLoad)); (log_item((CircBuf *)buf,log)); destroy_log_item((CircBuf *)buf,log)
#endif

#ifdef FRDMWITHOUTCIRC
#define LOG_RAW_DATA(data, length) (log_data((uint8_t *)data, length))
#define LOG_RAW_STRING(string) (log_string((uint8_t *)string))
#define LOG_RAW_INTR(num) (log_integer(num))
#define LOG_RAW_FLUSH() (log_flush())
#define LOG_ITEM(log, index, length, payLoad, payLoadID) (create_log_item(log, index, length, (uint8_t*) payLoad)); (log_item(log,payLoadID)); destroy_log_item(log)
#endif

#ifdef HOSTBEAGLE
#define LOG_RAW_DATA(data, length) (log_data((uint8_t *)data, length))
#define LOG_RAW_STRING(string) (log_string((uint8_t *)string))
#define LOG_RAW_INTR(num) (log_integer(num))
#define LOG_RAW_FLUSH() (log_flush())
#define LOG_ITEM(log, index, length, payLoad, payLoadID) (create_log_item(log, index, length, (uint8_t*) payLoad)); (log_item(log,payLoadID)); destroy_log_item(log)
#endif

#ifdef FRDMWITHCIRC
Binary_logger_e create_log_item(BinaryLogger *log, BinaryLogger_e index, size_t length, uint8_t *payLoad);
Binary_logger_e log_item(CircBuf *buf,BinaryLogger * log);
Binary_logger_e destroy_log_item(CircBuf *buf,BinaryLogger * log);
logger log_data(CircBuf *buf,uint8_t* data, uint32_t length);
logger log_string(CircBuf *buf,uint8_t * string);
logger log_integer(CircBuf *buf,uint8_t num);
logger log_flush(CircBuf *buf);
#endif

#ifdef FRDMWITHOUTCIRC
Binary_logger_e create_log_item(BinaryLogger *log, BinaryLogger_e index, size_t length, uint8_t *payLoad);
Binary_logger_e log_item(BinaryLogger * log,Payload_e payload);
Binary_logger_e destroy_log_item(BinaryLogger * log);
logger log_data(uint8_t* data, uint32_t length);
logger log_string(uint8_t * string);
logger log_integer(uint8_t num);
logger log_flush();
#endif

#ifdef HOSTBEAGLE
Binary_logger_e create_log_item(BinaryLogger *log, BinaryLogger_e index, size_t length, uint8_t *payLoad);
Binary_logger_e log_item(BinaryLogger * log);
Binary_logger_e destroy_log_item(BinaryLogger * log);
logger log_data(uint8_t* data, uint32_t length);
logger log_string(uint8_t * string);
logger log_integer(uint8_t num);
logger log_flush();
#endif

#endif
