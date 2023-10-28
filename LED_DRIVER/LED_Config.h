/*
 * LED_Config.h
 *
 *  Created on: Oct 27, 2023
 *      Author: METRA
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_NUM 3
typedef struct
{
	u8 LED_u8PORTID;
	u8 LED_u8PINID;
	u8 LED_u8CONNECTION;
	u8 LED_u8InitialState;

}LED_t;




#endif /* LED_CONFIG_H_ */
