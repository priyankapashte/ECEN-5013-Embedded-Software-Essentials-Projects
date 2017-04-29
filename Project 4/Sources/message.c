#include "message.h"

CI_Msg_Error Decode_CI_Msg(CI_Msg * message){

	if(message->command  == LED){

		if(message->data[0]==LED_ON){
			if(message->data[1]==RED || message->data[1]==GREEN || message->data[1]==BLUE){
				LED_ON(message->data[1]);
			}
		}
	
		else{
				return ERROR;
			}
		}

		else if(message->command == LED){
			if(message->data[0]==LED_OFF){
				if(message->data[1]==RED || message->data[1]==GREEN || message->data[1]==BLUE){
					LED_OFF(message->data[1]);

				}
			}

			else{

				return ERROR;
			}
		}

		else if(message->command == BRIGHTNESS){
			if(message->data[0]==LED_BRIGHTNESS_CONTROL_RED){
				if(message->data[1] >= TEN_PERCENT && message->data[1]<=HUNDRED_PERCENT){
					LED_BRIGHTNESS_CONTROL_RED(message->data[1]);
				}
			}

			else{

				return ERROR;
			}
		}

		else if(message->command == BRIGHTNESS){
			if(message->data[0]==LED_BRIGHTNESS_CONTROL_GREEN){
				if(message->data[1] >= TEN_PERCENT && message->data[1]<=HUNDRED_PERCENT){
					LED_BRIGHTNESS_CONTROL_GREEN(message->data[1]);
				}
			}

			else{
					return ERROR;
			}

		}

		else if(message->command == BRIGHTNESS){
			if(message->data[0]==LED_BRIGHTNESS_CONTROL_BLUE){
				if(message->data[1] >= TEN_PERCENT && message->data[1]<=HUNDRED_PERCENT){
					LED_BRIGHTNESS_CONTROL_BLUE(message->data[1]);
				}
			}

			else{

				return ERROR;
			}

		}

		else if(message->command == SYSTEM_RST){
			if(message->data[0] == SYSTEM_RESET){
				SYSTEM_RESET();
			}

			else{
					return ERROR;
			}
		}

		else(message->command == TIME_STMP){
			if(message->data[0] == RTC_TIMESTAMP){
				RTC_TIMESTAMP();
			}

			else{

				return ERROR;
			}
		}
}


