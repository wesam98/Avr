/*
 * LCD_Int.h
 *
 *  Created on: Nov 28, 2023
 *      Author: METRA
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "../../Libirarys/ErrorStates.h"
#include "../../Libirarys/StdTypes.h"

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);


ES_t LCD_enuDisplayExtraChar(u8* Copy_pu8Character,u8 Copy_u8CharNum ,u8 Copy_u8Position , u8 Copy_u8Entry);

ES_t LCD_enuWriteString(u8 *Copy_PArrchars);

void LCD_GOTO(u8 Row,u8 Col);

void LCD_ClearDisp();

ES_t LCD_enuCreatChar(u8* Copy_Au8NewChar, u8 Copy_u8Size, u8 Copy_u8StartPattern );

ES_t LCD_enuDisplayIntegerNum(s32 Copy_s32Num);

#endif /* LCD_INT_H_ */
