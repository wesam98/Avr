/*
 * EXTI_Privte.h
 *
 *  Created on: Feb 5, 2024
 *      Author: METRA
 */

#ifndef HAL_EXTI_EXTI_PRIVTE_H_
#define HAL_EXTI_EXTI_PRIVTE_H_

#define  MCUCR      *((volatile u8*)0x55)
#define  MCUCSR     *((volatile u8*)0x54)

#define  GICR       *((volatile u8*)0x5B)
#define  GIFR       *((volatile u8*)0x5A)



#define Disabled         0
#define Enabled          1


#define LOW_LEVEL               0
#define ANY_LOGICAL_CHANGE      1
#define FALLING_EDGE            2
#define RISING_EDGE             3

#endif /* HAL_EXTI_EXTI_PRIVTE_H_ */
