/*
 * LCD.c
 * Created: 8/31/2021 12:58:19 PM
 *  Author: MOHAMED_HELMY
 */ 
#include "LCD_CFG.h"
#include "DIO.h"
#include "LCD.h"
#define  F_CPU 16000000UL
#include "util/delay.h"

void LCD_INIT      (void)
{
	PIN_MODE(LCD_RS_PIN,OUTPUT);
	PIN_MODE(LCD_RW_PIN,OUTPUT);
	PIN_MODE(LCD_EN_PIN,OUTPUT);
	PIN_MODE(LCD_D4_PIN,OUTPUT);
	PIN_MODE(LCD_D5_PIN,OUTPUT);
	PIN_MODE(LCD_D6_PIN,OUTPUT);
	PIN_MODE(LCD_D7_PIN,OUTPUT);
	_delay_ms(100);
	/***_THIS_3_COMMANDS_TO_ACTIVE_4_BIT_MODE_***/
    LCD_WRITE_CMD(0X33);
    LCD_WRITE_CMD(0X32);
    LCD_WRITE_CMD(0X28);

    LCD_WRITE_CMD(0X0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
    LCD_WRITE_CMD(0X01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
    LCD_WRITE_CMD(0X06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
    LCD_WRITE_CMD(0X02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
}
void LCD_WRITE_CMD (u8 command)
{
	PIN_WRITE(LCD_RS_PIN,LOW);   /***_TO_SELECT_THE_COMMAND_REGISTER_******************/
	PIN_WRITE(LCD_EN_PIN,LOW);   /***_TO_WRITE_0_ON_ENABLE_PIN_************************/
	
	/***SEND_HIGH_PART***/
	PORT_WRITE(A,(command & 0xf0) | (A & 0x0f));
	PIN_WRITE(LCD_EN_PIN,HIGH);   /***_NOW_LCD_WILL_RECEIVE_THE_DATA_******************/
	_delay_ms(1);                 /***_WAIT_FOR_1_MILLI_SECOND_************************/
	PIN_WRITE(LCD_EN_PIN,LOW);    /***_TO_WRITE_0_ON_ENABLE_PIN_***********************/
		
	/***SEND_LOW_PART***/
	PORT_WRITE(A,(command << 4) | (A & 0x0f));
	PIN_WRITE(LCD_EN_PIN,HIGH);   /***_NOW_LCD_WILL_RECEIVE_THE_DATA_******************/
	_delay_ms(1);                 /***_WAIT_FOR_1_MILLI_SECOND_************************/
	PIN_WRITE(LCD_EN_PIN,LOW);    /***_TO_WRITE_0_ON_ENABLE_PIN_***********************/
	_delay_ms(5);                 /***_DELAY_5_MILLI_SECOND_EACH_TIME_YOU_CALL_THE_FUNCTION_***/
}
void LCD_WRITE_CHR (u8 character)
{
	PIN_WRITE(LCD_RS_PIN,HIGH);   /***_TO_SELECT_THE_DATA_REGISTER_********************/
	PIN_WRITE(LCD_EN_PIN,LOW);    /***_TO_WRITE_0_ON_ENABLE_PIN_***********************/
	
	/***SEND_HIGH_PART***/
	PORT_WRITE(A,(character & 0xf0) | (A & 0x0f));
	PIN_WRITE(LCD_EN_PIN,HIGH);   /***_NOW_LCD_WILL_RECEIVE_THE_DATA_******************/
	_delay_ms(1);                 /***_WAIT_FOR_1_MILLI_SECOND_************************/
	PIN_WRITE(LCD_EN_PIN,LOW);    /***_TO_WRITE_0_ON_ENABLE_PIN_***********************/
	
	/***SEND_LOW_PART***/
	PORT_WRITE(A,(character << 4) | (A & 0x0f));
	PIN_WRITE(LCD_EN_PIN,HIGH);   /***_NOW_LCD_WILL_RECEIVE_THE_DATA_******************/
	_delay_ms(1);                 /***_WAIT_FOR_1_MILLI_SECOND_************************/
	PIN_WRITE(LCD_EN_PIN,LOW);    /***_TO_WRITE_0_ON_ENABLE_PIN_***********************/
	_delay_ms(5);                 /***_DELAY_5_MILLI_SECOND_EACH_TIME_YOU_CALL_THE_FUNCTION_***/
}
void LCD_WRITE_STR (u8*p)
{
	u8 i = 0;
	while (p[i] != '\0')
	{
		LCD_WRITE_CHR(p[i]);
		i++;
	}
}
void LCD_WRITE_INT (u32 num){
		u32 rem = 0;
		u8 arr [16];
		s8 i = 0;
		while(num != 0)
		{
			rem = num % 10;
			arr[i] = rem + 48;
			i++;
			num = num / 10;
		}
		i--;
		while(i > -1)
		{
			LCD_WRITE_CHR(arr[i]);
			i--;
	}
}
void LCD_GO_TO     (u8 x,u8 y){
	int i;
	if(x==1)
		LCD_WRITE_CMD(0X80);
	else
		LCD_WRITE_CMD(0XC0);
	for(i=0;i<y;i++)
		LCD_WRITE_CMD(0X14);
	
}
void LCD_CLR       (void){
	LCD_WRITE_CMD(0X01);
}

