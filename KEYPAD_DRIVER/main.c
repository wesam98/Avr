/*
' * main.c
 *
 *  Created on: Nov 28, 2023
 *      Author: METRA
 */


#include "StdTypes.h"
#include "ErrorStates.h"

#include "DIO_Int.h"
#include "Keypad_Int.h"
#include "Keypad_Config.h"
 void main(void)
 {
	 u8 Local_u8Key;
	 DIO_enuInit();
	 Keypad_enuInit();
	 while(1)
	 {
		 do
		 {
			 Local_u8Key = Keypad_u8GetPressedkey();
		 }while( Local_u8Key == NOT_PRESSED );
	 }

 }
