#include "message.h"
#include "led.h"

CI_Msg_Error_t Decode_CI_Msg(CI_Msg_t *message){

	if(message->command == LED){
		if(message->data[0] == LED_ON){
			if(message->data[1] == RED || message->data[1] == GREEN || message->data[1] == BLUE){
				(*led_control_ptr)(message->data[1],HUNDRED_PERCENT);
			}
		}
		else if(message->data[0] == LED_OFF){
			led_control(OFF,ZERO_PERCENT);
		}
	}
	else if(message->command == BRIGHTNESS){
		if(message->data[0] == LED_BRIGHTNESS_RED){
			if(message->data[1] >= ZERO_PERCENT && message->data[1] <= HUNDRED_PERCENT){
				switch(message->data[1])
				{
				case 0: (*led_control_ptr)(BLUE,ZERO_PERCENT);
						break;
				case 1: (*led_control_ptr)(BLUE,TEN_PERCENT);
						break;
				case 2: (*led_control_ptr)(BLUE,TWENTY_PERCENT);
						break;
				case 3: (*led_control_ptr)(BLUE,THIRTY_PERCENT);
						break;
				case 4: (*led_control_ptr)(BLUE,FORTY_PERCENT);
						break;
				case 5: (*led_control_ptr)(BLUE,FIFTY_PERCENT);
						break;
				case 6: (*led_control_ptr)(BLUE,SIXTY_PERCENT);
						break;
				case 7: (*led_control_ptr)(BLUE,SEVENTY_PERCENT);
						break;
				case 8: (*led_control_ptr)(BLUE,EIGHTY_PERCENT);
						break;
				case 9: (*led_control_ptr)(BLUE,NINTY_PERCENT);
						break;
				case 10: (*led_control_ptr)(BLUE,HUNDRED_PERCENT);
						break;
				}
			}
		}
		else if(message->data[0] == LED_BRIGHTNESS_GREEN){
			if(message->data[1] >= ZERO_PERCENT && message->data[1] <= HUNDRED_PERCENT){
				switch(message->data[1])
				{
				case 0: (*led_control_ptr)(BLUE,ZERO_PERCENT);
						break;
				case 1: (*led_control_ptr)(BLUE,TEN_PERCENT);
						break;
				case 2: (*led_control_ptr)(BLUE,TWENTY_PERCENT);
						break;
				case 3: (*led_control_ptr)(BLUE,THIRTY_PERCENT);
						break;
				case 4: (*led_control_ptr)(BLUE,FORTY_PERCENT);
						break;
				case 5: (*led_control_ptr)(BLUE,FIFTY_PERCENT);
						break;
				case 6: (*led_control_ptr)(BLUE,SIXTY_PERCENT);
						break;
				case 7: (*led_control_ptr)(BLUE,SEVENTY_PERCENT);
						break;
				case 8: (*led_control_ptr)(BLUE,EIGHTY_PERCENT);
						break;
				case 9: (*led_control_ptr)(BLUE,NINTY_PERCENT);
						break;
				case 10: (*led_control_ptr)(BLUE,HUNDRED_PERCENT);
						break;
				}
			}
		}
		else if(message->data[0] == LED_BRIGHTNESS_BLUE){
			if(message->data[1] >= ZERO_PERCENT && message->data[1]<=HUNDRED_PERCENT){
				switch(message->data[1])
				{
				case 0: (*led_control_ptr)(BLUE,ZERO_PERCENT);
						break;
				case 1: (*led_control_ptr)(BLUE,TEN_PERCENT);
						break;
				case 2: (*led_control_ptr)(BLUE,TWENTY_PERCENT);
						break;
				case 3: (*led_control_ptr)(BLUE,THIRTY_PERCENT);
						break;
				case 4: (*led_control_ptr)(BLUE,FORTY_PERCENT);
						break;
				case 5: (*led_control_ptr)(BLUE,FIFTY_PERCENT);
						break;
				case 6: (*led_control_ptr)(BLUE,SIXTY_PERCENT);
						break;
				case 7: (*led_control_ptr)(BLUE,SEVENTY_PERCENT);
						break;
				case 8: (*led_control_ptr)(BLUE,EIGHTY_PERCENT);
						break;
				case 9: (*led_control_ptr)(BLUE,NINTY_PERCENT);
						break;
				case 10: (*led_control_ptr)(BLUE,HUNDRED_PERCENT);
						break;
				}
			}
		}
	}
	else if(message->command == SYSTEM_RST){
		system_reset();
	}
	else if(message->command == RTC_TIMESTAMP)
	{
		rtc_init();
	}
	else{
		return ERROR;
	}
		/*else if (message->command == RTC_TIMESTMP){
			if(message->data[0] == rtctimestamp){
				RTC_TIMESTAMP();
			}

			else{

				return ERROR;
			}
		} */
}


