
#include "DC_MOTOR_CFG.h"
#include "TIMER.h"
#include "DC_MOTOR.h"
#include "DIO.h"

void DC_MOTOR_INIT(void)
{
	PIN_MODE(DC_DIRECTION_1_PIN,OUTPUT);
	PIN_MODE(DC_DIRECTION_2_PIN,OUTPUT);
	PWM_0_INIT();
}

void DC_MOTOR_SET_DIRECTION(u8 direction)
{
	switch(direction)
	{
		case CLOCK_WISE:
		PIN_WRITE(DC_DIRECTION_1_PIN,HIGH);
		PIN_WRITE(DC_DIRECTION_2_PIN,LOW);
		break;
		case ANTI_CLOCK_WISE:
		PIN_WRITE(DC_DIRECTION_1_PIN,LOW);
		PIN_WRITE(DC_DIRECTION_2_PIN,HIGH);
		break;
		default:
		break;
	}
}

void DC_MOTOR_SET_DUTY_CYCLE(u8 duty_cycle)
{
	PWM_0_SET_DUTY_CYCLE(duty_cycle);
}

void DC_MOTOR_START(void)
{
	PWM_0_START();
}

void DC_MOTOR_OFF(void)
{
	//PWM_0_STOP();
	PIN_WRITE(DC_DIRECTION_1_PIN,HIGH);
	PIN_WRITE(DC_DIRECTION_2_PIN,HIGH);
}
