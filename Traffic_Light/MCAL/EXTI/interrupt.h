/*
 * interrupt.h
 *
 *  Created on: Feb 6, 2024
 *      Author: METRA
 */

#ifndef HAL_EXTI_INTERRUPT_H_
#define HAL_EXTI_INTERRUPT_H_

#define ISR(VECTNUM)              void VECTNUM(void)__attribute__((signal));\
	                              void VECTNUM(void)

#define VECT_INT0                     __vector_1
#define VECT_INT1                     __vector_2

#define VECT_TIMER_OVF                 __vector_11

#define VECT_TIMER_CTC                __vector_10


#endif /* HAL_EXTI_INTERRUPT_H_ */
