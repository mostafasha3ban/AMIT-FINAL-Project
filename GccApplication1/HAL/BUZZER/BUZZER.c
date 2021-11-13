
#include "BUZZER_CFG.h"
#include "DIO.h"
#define  F_CPU 16000000UL
#include "util/delay.h"

void BUZZER_INIT      (void)
{
	PIN_MODE(BUZZER_PIN,OUTPUT);
}
void BUZZER_ON        (void)
{
	PIN_WRITE(BUZZER_PIN,HIGH);
}
void BUZZER_OFF       (void)
{
	PIN_WRITE(BUZZER_PIN,LOW);
}
void BUZZER_ONCE      (void)
{
	PIN_WRITE(BUZZER_PIN,HIGH);
	_delay_ms(30);
	PIN_WRITE(BUZZER_PIN,LOW);
}
void BUZZER_TWICE     (void)
{
	PIN_WRITE(BUZZER_PIN,HIGH);
	_delay_ms(70);
	PIN_WRITE(BUZZER_PIN,LOW);
	_delay_ms(40);
	PIN_WRITE(BUZZER_PIN,HIGH);
	_delay_ms(70);
	PIN_WRITE(BUZZER_PIN,LOW);
}
void BUZZER_ONCE_LONG (void)
{
	PIN_WRITE(BUZZER_PIN,HIGH);
	_delay_ms(600);
	PIN_WRITE(BUZZER_PIN,LOW);
}
