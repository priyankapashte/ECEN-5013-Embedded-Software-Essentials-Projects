#include "message.h"
#include "led.h"

CI_Msg_Error_t Decode_CI_Msg(CI_Msg_t *message){

	if(message->command == LED){                                  		  /* Message command is lED*/
		if(message->data[0] == LED_ON){
			if(message->data[1] == RED || message->data[1] == GREEN || message->data[1] == BLUE){
				(*led_control_ptr)(message->data[1],HUNDRED_PERCENT);
			}
		}
		else if(message->data[0] == LED_OFF){							  /* Message command is lED_OFF */
			led_control(OFF,ZERO_PERCENT);
		}
	}
	else if(message->command == BRIGHTNESS){							 /* Message command is brightness */
		if(message->data[0] == LED_BRIGHTNESS_RED){
			if(message->data[1] >= ZERO_PERCENT && message->data[1] <= HUNDRED_PERCENT){
				switch(message->data[1])
				{
				case 0: (*led_control_ptr)(RED,ZERO_PERCENT);              /* Set brightness of red led to zero percent */
						break;
				case 1: (*led_control_ptr)(RED,TEN_PERCENT);			   /* Set brightness of red led to ten percent */
						break;
				case 2: (*led_control_ptr)(RED,TWENTY_PERCENT);				/* Set brightness of red led to twenty percent */
						break;
				case 3: (*led_control_ptr)(RED,THIRTY_PERCENT);				/* Set brightness of red led to thirty percent */
						break;
				case 4: (*led_control_ptr)(RED,FORTY_PERCENT);				/* Set brightness of red led to forty percent */
						break;
				case 5: (*led_control_ptr)(RED,FIFTY_PERCENT);				/* Set brightness of red led to fifty percent */
						break;
				case 6: (*led_control_ptr)(RED,SIXTY_PERCENT);				/* Set brightness of red led to sixty percent */
						break;
				case 7: (*led_control_ptr)(RED,SEVENTY_PERCENT);			/* Set brightness of red led to seventy percent */
						break;
				case 8: (*led_control_ptr)(RED,EIGHTY_PERCENT);				/* Set brightness of red led to eighty percent */
						break;
				case 9: (*led_control_ptr)(RED,NINTY_PERCENT);				/* Set brightness of red led to ninty percent */
						break;
				case 10: (*led_control_ptr)(RED,HUNDRED_PERCENT);			/* Set brightness of red led to hundred percent */
						break;
				}
			}
		}
		else if(message->data[0] == LED_BRIGHTNESS_GREEN){
			if(message->data[1] >= ZERO_PERCENT && message->data[1] <= HUNDRED_PERCENT){
				switch(message->data[1])
				{
				case 0: (*led_control_ptr)(GREEN,ZERO_PERCENT);			/* Set brightness of green led to zero percent */
						break;
				case 1: (*led_control_ptr)(GREEN,TEN_PERCENT);			/* Set brightness of green led to ten percent */
						break;
				case 2: (*led_control_ptr)(GREEN,TWENTY_PERCENT);		/* Set brightness of green led to twenty percent */
						break;
				case 3: (*led_control_ptr)(GREEN,THIRTY_PERCENT);		/* Set brightness of green led to thirty percent */
						break;
				case 4: (*led_control_ptr)(GREEN,FORTY_PERCENT);		/* Set brightness of green led to forty percent */
						break;
				case 5: (*led_control_ptr)(GREEN,FIFTY_PERCENT);		/* Set brightness of green led to fifty percent */
						break;
				case 6: (*led_control_ptr)(GREEN,SIXTY_PERCENT);		/* Set brightness of green led to sixty percent */
						break;
				case 7: (*led_control_ptr)(GREEN,SEVENTY_PERCENT);		/* Set brightness of green led to seventy percent */
						break;
				case 8: (*led_control_ptr)(GREEN,EIGHTY_PERCENT);		/* Set brightness of green led to eighty percent */
						break;
				case 9: (*led_control_ptr)(GREEN,NINTY_PERCENT);		/* Set brightness of green led to ninty percent */
						break;
				case 10: (*led_control_ptr)(GREEN,HUNDRED_PERCENT);		/* Set brightness of green led to hundred percent */
						break;
				}
			}
		}
		else if(message->data[0] == LED_BRIGHTNESS_BLUE){
			if(message->data[1] >= ZERO_PERCENT && message->data[1]<=HUNDRED_PERCENT){
				switch(message->data[1])
				{
				case 0: (*led_control_ptr)(BLUE,ZERO_PERCENT);				/* Set brightness of blue led to zero percent */
						break;
				case 1: (*led_control_ptr)(BLUE,TEN_PERCENT);				/* Set brightness of blue led to ten percent */
						break;
				case 2: (*led_control_ptr)(BLUE,TWENTY_PERCENT);			/* Set brightness of blue led to twenty percent */
						break;
				case 3: (*led_control_ptr)(BLUE,THIRTY_PERCENT);			/* Set brightness of blue led to thirty percent */
						break;
				case 4: (*led_control_ptr)(BLUE,FORTY_PERCENT);				/* Set brightness of blue led to forty percent */
						break;
				case 5: (*led_control_ptr)(BLUE,FIFTY_PERCENT);				/* Set brightness of blue led to fifty percent */
						break;
				case 6: (*led_control_ptr)(BLUE,SIXTY_PERCENT);				/* Set brightness of blue led to sixty percent */
						break;
				case 7: (*led_control_ptr)(BLUE,SEVENTY_PERCENT);			/* Set brightness of blue led to seventy percent */
						break;
				case 8: (*led_control_ptr)(BLUE,EIGHTY_PERCENT);			/* Set brightness of blue led to eighty percent */
						break;
				case 9: (*led_control_ptr)(BLUE,NINTY_PERCENT);				/* Set brightness of blue led to ninety percent */
						break;
				case 10: (*led_control_ptr)(BLUE,HUNDRED_PERCENT);			/* Set brightness of blue led to hundred percent */
						break;
				}
			}
		}
	}
	else if(message->command == SYSTEM_RST){                               /* Message command  System Reset */
		system_reset();
	}
	else if(message->command == RTC_TIMESTAMP)								/* Message command  RTC Timestamp */
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


