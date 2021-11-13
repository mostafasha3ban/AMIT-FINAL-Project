
#include "KEY_PAD_CFG.h"
#include "DIO.h"
#include "KEY_PAD.h"
#define  F_CPU 16000000UL
#include "util/delay.h"

#define PRESSED      0

   u8 arr [4][4] = {{ '1' , '2' , '3' , 'A' },
					{ '4' , '5' , '6' , 'B' },
					{ '7' , '8' , '9' , 'C' },
					{ '*' , '0' , '#' , 'D' }};

void  KEY_PAD_INIT (void)
{
	/***_ALL_ROWS_PINS_ARE_OUTPUT_****************/
	PIN_MODE(KEY_PAD_R0_PIN,OUTPUT);
	PIN_MODE(KEY_PAD_R1_PIN,OUTPUT);
	PIN_MODE(KEY_PAD_R2_PIN,OUTPUT);
	PIN_MODE(KEY_PAD_R3_PIN,OUTPUT);
	/***_ALL_OUTPUT_PINS_ARE_HIGH_****************/
	PIN_WRITE(KEY_PAD_R0_PIN,HIGH);
	PIN_WRITE(KEY_PAD_R1_PIN,HIGH);
	PIN_WRITE(KEY_PAD_R2_PIN,HIGH);
	PIN_WRITE(KEY_PAD_R3_PIN,HIGH);
	/***_ALL_COULMNS_PINS_ARE_INPUT_**************/
	PIN_MODE(KEY_PAD_C0_PIN,INPUT);
	PIN_MODE(KEY_PAD_C1_PIN,INPUT);
	PIN_MODE(KEY_PAD_C2_PIN,INPUT);
	PIN_MODE(KEY_PAD_C3_PIN,INPUT);
	/***_ACTIVE_PULL_UP_RES_FOR_ALL_INPUT_PINS_***/
	PIN_PULL_UP(KEY_PAD_C0_PIN,ENABLE);
	PIN_PULL_UP(KEY_PAD_C1_PIN,ENABLE);
	PIN_PULL_UP(KEY_PAD_C2_PIN,ENABLE);
	PIN_PULL_UP(KEY_PAD_C3_PIN,ENABLE);
}
u8    KEY_PAD_READ (void)
{
	u8 r,c;
	u8 temp,value = 0;
	for(r = KEY_PAD_R0_PIN ; r <= KEY_PAD_R3_PIN ; r++)
	{
		PIN_WRITE(r,LOW);
		for(c = KEY_PAD_C0_PIN ; c <= KEY_PAD_C3_PIN ; c++)
		{
			temp = PIN_READ(c);
			if (temp == PRESSED)
			{
				value = arr[r - KEY_PAD_R0_PIN][c - KEY_PAD_C0_PIN];
				while(temp == PRESSED)
				{
					temp = PIN_READ(c);
				}
				_delay_ms(10);
			}
		}
		PIN_WRITE(r,HIGH);
	}
	return value;
}
