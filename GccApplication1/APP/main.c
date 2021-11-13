#include "P_B.h"
#include "STD_TYPES.h"
#include "S_SEG.h"
#include "LED.h"
#include "EX_INT.h"
#include "REG.h"
#include "TEMP_S.h"
#include "TIMER.h"
#include "EEPROM_24C16.h"
#include <avr/interrupt.h>
#define  F_CPU 16000000UL
#include "util/delay.h"

#define ON 1	// State of heater
#define OFF 0	// State of heater

u8 On_Off = OFF;  // flag to know the state of the heater
u8 Set_Temp;
u8 Set_Temp_State = OFF;
s8 Current_Temp = 45;
s8 Temp_Arr[10];
u8 address = 0;


extern u32 num_of_ov;
extern u32 num_of_ov_2;

void Led_Fun(void);

int main(void)
{
	EXTERNAL_INT_0_INIT();
	S_SEG_INIT();
	LED_INIT(L_LED);  // Cooling element ON indicator
	LED_INIT(M_LED);  // Heating element ON indicator
	LED_INIT(R_LED);  // Heating element LED blinks when heating is on and solid light when cooling is on
	P_B_INIT(P_B_0);  // P_B for decreasing temperature
	P_B_INIT(P_B_1);  // P_B for increasing temperature
	TEMP_S_INIT();	  
	TIMER_1_INIT();
	TIMER_1_SET_TIME(4000);
	TIMER_0_INIT();
	TIMER_0_SET_TIME(750);
	TIMER_2_INIT();
	TIMER_2_SET_TIME(100);
	TIMER_2_START();
	Set_Temp = 60;
    while(1)
    {	if(On_Off == OFF){
			S_SEG_OFF();
			LEDS_OFF();
		}	
		else{
			Led_Fun();
			if(Set_Temp_State){
				S_SEG_DISPLAY(Set_Temp);
				if(P_B_READ(P_B_0)){
					_delay_ms(100);
					TIMER_1_RESET();
					while(P_B_READ(P_B_0)){
						S_SEG_DISPLAY(Set_Temp);
						Led_Fun();}
					if(Set_Temp >35)
						Set_Temp-=5;
					}
				if(P_B_READ(P_B_1)){
					_delay_ms(100);
					TIMER_1_RESET();
					while(P_B_READ(P_B_1)){
						S_SEG_DISPLAY(Set_Temp);
						Led_Fun();}
					if(Set_Temp<75)
						Set_Temp+=5;
				}
			}
			else {
				S_SEG_DISPLAY(Current_Temp);
				if(P_B_READ(P_B_1) || P_B_READ(P_B_0))
				{
					_delay_ms(100);
					while(P_B_READ(P_B_0)||P_B_READ(P_B_1)){
						S_SEG_DISPLAY(Set_Temp);
						Led_Fun();
						Set_Temp_State = ON;
						TIMER_1_START();
						TIMER_0_START();
						}
				}
			}
			}
		}
	}

ISR(INT0_vect)			//Uses push button 2 as interrupt button to turn heater ON/OFF
{	if(On_Off == ON)
		On_Off = OFF;
	else{
		On_Off = ON;
	}
}

ISR(TIMER0_OVF_vect){		//timer 0 flashes the seven segment every 1 second if set state is on
	static u32 x;
	x++;
	if(x == num_of_ov){
	S_SEG_OFF();
	_delay_ms(50);
	x = 0;	
	}
}

ISR(TIMER1_COMPA_vect){		//timer 1 turns the set state off after 5 seconds of inactivity
	TIMER_1_STOP();
	TIMER_0_STOP();
	Set_Temp_State = OFF;
}

ISR(TIMER2_OVF_vect){		// timer 2 measure the temperature every 100 ms and find the average
	static u32 y;
	y++;
	if(y == num_of_ov_2){
		for(int count=0;count<9;count++)
			Temp_Arr[count] = Temp_Arr[count+1];
		Temp_Arr[9] = TEMP_S_READ();
		s16 sum = 0;
		for(int count =0;count<10;count++)
			sum+=Temp_Arr[count];
		Current_Temp = sum/10;
		if(Current_Temp>99)
			Current_Temp = 99;
		if(Current_Temp<0)
			Current_Temp = 0;
		y=0;
	}
}

void Led_Fun(void){				// this function turn on the appropriate LED in case of cooling or heating
	if(Current_Temp<Set_Temp-5){
		LED_TOGGLE(R_LED);
		LED_ON(M_LED);
		LED_OFF(L_LED);
	}
	else{ if(Current_Temp>Set_Temp+5){
			LED_ON(R_LED);
			LED_OFF(M_LED);
			LED_ON(L_LED);
			}
			else
				LEDS_OFF();
	}
}