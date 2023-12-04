/*
 * Keypad_Int.h
 *
 *  Created on: Nov 27, 2023
 *      Author: METRA
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_
#include "ErrorStates.h"
#include "StdTypes.h"

ES_t Keypad_enuInit(void);
u8 Keypad_u8GetPressedkey(void);


#endif /* KEYPAD_INT_H_ */
