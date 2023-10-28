/*
 * main.c
 *
 *  Created on: Oct 27, 2023
 *      Author: METRA
 */

#include "Error_States.h"
#include "StdTypes.h"
#include "DIO_Int.h"
#include "LED_Config.h"
#include "LED_Int.h"
#include "Switch_Cinfig.h"
#include "Switch_Int.h"
#include <util/delay.h>

extern LED_t LED_AstrLedConfig [LED_NUM];
extern SW_t SWITCH_AstrSWStatus [SW_NUM];
int main (void)
{
    SWITCH_enuSwInit(SWITCH_AstrSWStatus);
	LED_enuInit(LED_AstrLedConfig);
	u8 pinState;
	while(1)
	{ SWITCH_enuSwState(&SWITCH_AstrSWStatus[0], &pinState);
       if(pinState == 1)
       {
		LED_enuLedON(&LED_AstrLedConfig[0]);
       }
       else
       {
		LED_enuLedOFF(&LED_AstrLedConfig[0]);

       }


	}
	return 0;
}
