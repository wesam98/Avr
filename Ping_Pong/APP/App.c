/* * App.c
 *
 *  Created on: Feb 6, 2024
 *      Author: METRA
 */

#include "../MCAL/DIO_Int.h"
#include "../HAL/LCD/LCD_Int.h"
#include "App.h"
#include "util/delay.h"
u8 win1 = 0,win2 = 0,score1 = 0,score2 = 0,turns=5;
u8 row_ball=2,col_ball=2;

void Ping_PongInit()
{
	LCD_GOTO(0,1);
	LCD_enuWriteString("p1 ");
	LCD_enuDisplayIntegerNum(score1);
	LCD_GOTO(0,10);
	LCD_enuWriteString("p2 ");
	LCD_enuDisplayIntegerNum(score2);
	LCD_GOTO(2,15);
	LCD_enuDisplayChar('|');

	LCD_GOTO(2,0);
	LCD_enuDisplayChar('|');

	LCD_GOTO(2,1);
	LCD_enuDisplayChar('O');
	_delay_ms(50);
	LCD_GOTO(2,1);
	LCD_enuDisplayChar(' ');


}

/*  function to Display a ball moving on LCD from one end to the other
void Ping_PongStart()
{
	for( ;col_ball<14;col_ball++){
		row_ball=((col_ball<<0)&1)+2;

		LCD_GOTO(row_ball,col_ball);
		LCD_enuDisplayChar('O');
		_delay_ms(50);
		LCD_GOTO(row_ball,col_ball);
		LCD_enuDisplayChar(' ');
	}
	for( ;col_ball>1;col_ball--){
		row_ball=((col_ball<<0)&1)+2;

		LCD_GOTO(row_ball,col_ball);
		LCD_enuDisplayChar('O');
		_delay_ms(50);
		LCD_GOTO(row_ball,col_ball);
		LCD_enuDisplayChar(' ');
	}
}*/
void handling()
{
	_delay_ms(600);

	if(win1 == win2 )
	{

	}

	else if(win1>win2)
	{
		LCD_ClearDisp();
		LCD_GOTO(1,1);
		LCD_enuWriteString("Player 1 Won...");
		score1++;
		_delay_ms(500);
		LCD_ClearDisp();
		Ping_PongInit();
		row_ball=2;
		col_ball =2;
	}
	else if(win2>win1 )
	{
		LCD_ClearDisp();
		LCD_GOTO(1,1);
		LCD_enuWriteString("Player 2 Won...");
		score2++;
		_delay_ms(500);
		LCD_ClearDisp();
		Ping_PongInit();
		row_ball=3;
		col_ball =2;

	}
	win1=0,win2=0;


}


/*  Use external interrupt to indicate If the player press the button, so the ball should bounce to the other side
    and If not pressed the opposite player wins the game */
void ISR_INT0()
{
	win1+=1;
	for( col_ball=1;col_ball<14;col_ball++){
		row_ball=((col_ball<<0)&1)+2;

		LCD_GOTO(row_ball,col_ball);
		LCD_enuDisplayChar('O');
		_delay_ms(50);
		LCD_GOTO(row_ball,col_ball);
		LCD_enuDisplayChar(' ');
	}
}


void ISR_INT1()
{
	win2+=1;
	for(col_ball=14;col_ball>1;col_ball--){
		row_ball=((col_ball<<0)&1)+2;

		LCD_GOTO(row_ball,col_ball);
		LCD_enuDisplayChar('O');
		_delay_ms(50);
		LCD_GOTO(row_ball,col_ball);
		LCD_enuDisplayChar(' ');
	}

}
