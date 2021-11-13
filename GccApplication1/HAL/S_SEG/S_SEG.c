
#include "S_SEG_CFG.h"
#include "DIO.h"
#define  F_CPU 16000000UL
#include "util/delay.h"

void S_SEG_INIT        (void)
{
	PIN_MODE(S_SEG_EN_2_PIN,OUTPUT);
	PIN_MODE(S_SEG_EN_1_PIN,OUTPUT);
	PIN_MODE(S_SEG_DIP_PIN,OUTPUT);
	PIN_MODE(S_SEG_A_PIN,OUTPUT);
	PIN_MODE(S_SEG_B_PIN,OUTPUT);
	PIN_MODE(S_SEG_C_PIN,OUTPUT);
	PIN_MODE(S_SEG_D_PIN,OUTPUT);
}

void S_SEG_OFF		   (void){
	PIN_WRITE(S_SEG_A_PIN,HIGH);
	PIN_WRITE(S_SEG_B_PIN,HIGH);
	PIN_WRITE(S_SEG_C_PIN,HIGH);
	PIN_WRITE(S_SEG_D_PIN,HIGH);
}


void S_SEG_DISPLAY     (u8 full_number)
{
	u16 i;
	for(i=0;i<50;i++)
	{
		u8 l_part = (full_number / 10);
		u8 r_part = (full_number % 10);
		PIN_WRITE(S_SEG_EN_1_PIN,HIGH);
		PIN_WRITE(S_SEG_EN_2_PIN,LOW);
		switch(l_part)
		{
			case 0:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 1:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 2:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,HIGH);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 3:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,HIGH);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 4:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,HIGH);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 5:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,HIGH);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 6:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,HIGH);
			PIN_WRITE(S_SEG_C_PIN,HIGH);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 7:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,HIGH);
			PIN_WRITE(S_SEG_C_PIN,HIGH);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 8:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,HIGH);
			break;
			case 9:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,HIGH);
			break;
		}
		_delay_ms(1);
		PIN_WRITE(S_SEG_EN_1_PIN,LOW);
		PIN_WRITE(S_SEG_EN_2_PIN,HIGH);
		switch(r_part)
		{
			case 0:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 1:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 2:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,HIGH);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 3:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,HIGH);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 4:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,HIGH);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 5:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,HIGH);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 6:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,HIGH);
			PIN_WRITE(S_SEG_C_PIN,HIGH);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 7:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,HIGH);
			PIN_WRITE(S_SEG_C_PIN,HIGH);
			PIN_WRITE(S_SEG_D_PIN,LOW);
			break;
			case 8:
			PIN_WRITE(S_SEG_A_PIN,LOW);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,HIGH);
			break;
			case 9:
			PIN_WRITE(S_SEG_A_PIN,HIGH);
			PIN_WRITE(S_SEG_B_PIN,LOW);
			PIN_WRITE(S_SEG_C_PIN,LOW);
			PIN_WRITE(S_SEG_D_PIN,HIGH);
			break;
		}
		_delay_ms(1);
		PIN_WRITE(S_SEG_EN_2_PIN,LOW);
	}
}

void S_SEG_COUNT_DOWN  (s8 full_number)
{
	
	for(;full_number>=0;full_number--)
	{
		u16 i;
		for(i=0;i<50;i++)
		{
			u8 l_part = (full_number / 10);
			u8 r_part = (full_number % 10);
			PIN_WRITE(S_SEG_EN_1_PIN,HIGH);
			PIN_WRITE(S_SEG_EN_2_PIN,LOW);
			switch(l_part)
			{
				case 0:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 1:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 2:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 3:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 4:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 5:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 6:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 7:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 8:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,HIGH);
				break;
				case 9:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,HIGH);
				break;
			}
			_delay_ms(10);
			PIN_WRITE(S_SEG_EN_1_PIN,LOW);
			PIN_WRITE(S_SEG_EN_2_PIN,HIGH);
			switch(r_part)
			{
				case 0:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 1:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 2:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 3:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 4:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 5:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 6:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 7:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 8:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,HIGH);
				break;
				case 9:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,HIGH);
				break;
			}
			_delay_ms(10);
			PIN_WRITE(S_SEG_EN_2_PIN,LOW);
		}
	}
}

void S_SEG_TIMER       (u8 full_number)
{
	u16 j;
	for(j=0;j<=full_number;j++)
	{
		u16 i;
		for(i=0;i<50;i++)
		{
			u8 l_part = (j / 10);
			u8 r_part = (j % 10);
			PIN_WRITE(S_SEG_EN_1_PIN,HIGH);
			PIN_WRITE(S_SEG_EN_2_PIN,LOW);
			switch(l_part)
			{
				case 0:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 1:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 2:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 3:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 4:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 5:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 6:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 7:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 8:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,HIGH);
				break;
				case 9:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,HIGH);
				break;
			}
			_delay_ms(10);
			PIN_WRITE(S_SEG_EN_1_PIN,LOW);
			PIN_WRITE(S_SEG_EN_2_PIN,HIGH);
			switch(r_part)
			{
				case 0:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 1:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 2:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 3:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 4:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 5:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 6:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 7:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,HIGH);
				PIN_WRITE(S_SEG_C_PIN,HIGH);
				PIN_WRITE(S_SEG_D_PIN,LOW);
				break;
				case 8:
				PIN_WRITE(S_SEG_A_PIN,LOW);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,HIGH);
				break;
				case 9:
				PIN_WRITE(S_SEG_A_PIN,HIGH);
				PIN_WRITE(S_SEG_B_PIN,LOW);
				PIN_WRITE(S_SEG_C_PIN,LOW);
				PIN_WRITE(S_SEG_D_PIN,HIGH);
				break;
			}
			_delay_ms(10);
			PIN_WRITE(S_SEG_EN_2_PIN,LOW);
		}
	}
}
