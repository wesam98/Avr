/*
 * Timer_Config.h
 *
 *  Created on: Feb 22, 2024
 *      Author: METRA
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#include "../../Libirarys/StdTypes.h"

#define  Timer0_Prescaler     64

#define  Timer0_Mode         OVF_MODE
/* in case of you choose PWM choose between FAST PWM mode or PHASE_CORRECT */
#define  PWM_Phase           PHASE_CORRECT_NON_INVER
/* in case of CTC mode choose configuration of OC0 pin DiSCONNECTED or Toggle or Clear or Set */
#define  OC0_MODE           DISCONNECTED

 /* Frequency in KHZ */
#define  TIMER_F_CPU        (1000UL)


#endif /* TIMER_CONFIG_H_ */
