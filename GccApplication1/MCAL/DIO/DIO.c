
#include "DIO_CFG.h"
#include "DIO.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "REG.h"

void PIN_MODE (u8 pin,u8 mode)
{
	u8 port = pin / 10;
	switch(mode)
	{
		case OUTPUT:
	    switch(port)
		{
			case 1:
			pin = pin % 10;
			SET_BIT(DIRECTION_REGISTER_B,pin);
			break;
			case 2:
			pin = pin % 20;
			SET_BIT(DIRECTION_REGISTER_D,pin);
			break;
			case 3:
			pin = pin % 30;
			SET_BIT(DIRECTION_REGISTER_C,pin);
			break;
			case 4:
			pin = pin % 40;
			SET_BIT(DIRECTION_REGISTER_A,pin);
			break;	
		}
		break;
		
		case INPUT:
		switch(port)
		{
			case 1:
			pin = pin % 10;
			CLR_BIT(DIRECTION_REGISTER_B,pin);
			break;
			case 2:
			pin = pin % 20;
			CLR_BIT(DIRECTION_REGISTER_D,pin);
			break;
			case 3:
			pin = pin % 30;
			CLR_BIT(DIRECTION_REGISTER_C,pin);
			break;
			case 4:
			pin = pin % 40;
			CLR_BIT(DIRECTION_REGISTER_A,pin);
			break;
		}
		break;
	}
}
void PIN_WRITE (u8 pin,u8 status)
{
	u8 port = pin / 10;
	switch(status)
	{
		case HIGH:
		switch(port)
		{
			case 1:
			pin = pin % 10;
			SET_BIT(WRITE_DATA_REGISTER_B,pin);
			break;
			case 2:
			pin = pin % 20;
			SET_BIT(WRITE_DATA_REGISTER_D,pin);
			break;
			case 3:
			pin = pin % 30;
			SET_BIT(WRITE_DATA_REGISTER_C,pin);
			break;
			case 4:
			pin = pin % 40;
			SET_BIT(WRITE_DATA_REGISTER_A,pin);
			break;
		}
		break;
		
		case LOW:
		switch(port)
		{
			case 1:
			pin = pin % 10;
			CLR_BIT(WRITE_DATA_REGISTER_B,pin);
			break;
			case 2:
			pin = pin % 20;
			CLR_BIT(WRITE_DATA_REGISTER_D,pin);
			break;
			case 3:
			pin = pin % 30;
			CLR_BIT(WRITE_DATA_REGISTER_C,pin);
			break;
			case 4:
			pin = pin % 40;
			CLR_BIT(WRITE_DATA_REGISTER_A,pin);
			break;
		}
		break;
	}
}

void PIN_TOGGLE(u8 pin)
{
	u8 port = pin / 10;
	switch(port)
	{
		case 1:
		pin = pin % 10;
		TOG_BIT(WRITE_DATA_REGISTER_B,pin);
		break;
		case 2:
		pin = pin % 20;
		TOG_BIT(WRITE_DATA_REGISTER_D,pin);
		break;
		case 3:
		pin = pin % 30;
		TOG_BIT(WRITE_DATA_REGISTER_C,pin);
		break;
		case 4:
		pin = pin % 40;
		TOG_BIT(WRITE_DATA_REGISTER_A,pin);
		break;
	}	
}

u8 PIN_READ (u8 pin)
{
	u8 port = pin / 10;
	u8 value = 0;
	switch(port)
	{
		case 1:
		pin = pin % 10;
		value = GET_BIT(READ_DATA_REGISTER_B,pin);
		break;
		case 2:
		pin = pin % 20;
		value = GET_BIT(READ_DATA_REGISTER_D,pin);
		break;
		case 3:
		pin = pin % 30;
		value = GET_BIT(READ_DATA_REGISTER_C,pin);
		break;
		case 4:
		pin = pin % 40;
		value = GET_BIT(READ_DATA_REGISTER_A,pin);
		break;
	}
    return value;
}
void  PIN_PULL_UP  (u8 pin,u8 status)
{
	u8 port = pin / 10;
	switch(status)
	{
		case ENABLE:
		switch(port)
		{
			case 1:
			pin = pin % 10;
			SET_BIT(WRITE_DATA_REGISTER_B,pin);
			break;
			case 2:
			pin = pin % 20;
			SET_BIT(WRITE_DATA_REGISTER_D,pin);
			break;
			case 3:
			pin = pin % 30;
			SET_BIT(WRITE_DATA_REGISTER_C,pin);
			break;
			case 4:
			pin = pin % 40;
			SET_BIT(WRITE_DATA_REGISTER_A,pin);
			break;
		}
		break;
		
		case DISABLE:
		switch(port)
		{
			case 1:
			pin = pin % 10;
			CLR_BIT(WRITE_DATA_REGISTER_B,pin);
			break;
			case 2:
			pin = pin % 20;
			CLR_BIT(WRITE_DATA_REGISTER_D,pin);
			break;
			case 3:
			pin = pin % 30;
			CLR_BIT(WRITE_DATA_REGISTER_C,pin);
			break;
			case 4:
			pin = pin % 40;
			CLR_BIT(WRITE_DATA_REGISTER_A,pin);
			break;
		}
		break;
	}
}

void  PORT_MODE    (u8 port,u8 mode)
{
	switch(port)
	{
		case B:
		DIRECTION_REGISTER_B = mode;
		break;
		case D:
		DIRECTION_REGISTER_D = mode;
		break;
		case C:
		DIRECTION_REGISTER_C = mode;
		break;
		case A:
		DIRECTION_REGISTER_A = mode;
		break;
	}
}
void  PORT_WRITE   (u8 port,u8 value)
{
	switch(port)
	{
		case B:
		WRITE_DATA_REGISTER_B = value;
		break;
		case D:
		WRITE_DATA_REGISTER_D = value;
		break;
		case C:
		WRITE_DATA_REGISTER_C = value;
		break;
		case A:
		WRITE_DATA_REGISTER_A = value;
		break;
	}
}
void  PORT_TOGGLE  (u8 port)
{
	switch(port)
	{
		case B:
		WRITE_DATA_REGISTER_B ^= 0xff;
		break;
		case D:
		WRITE_DATA_REGISTER_D ^= 0xff;
		break;
		case C:
		WRITE_DATA_REGISTER_C ^= 0xff;
		break;
		case A:
		WRITE_DATA_REGISTER_A ^= 0xff;
		break;
	}
}
u8 PORT_READ    (u8 port)
{
	u8 port_value = 0;
	switch(port)
	{
		case B:
		port_value = READ_DATA_REGISTER_B;
		break;
		case D:
		port_value = READ_DATA_REGISTER_D;
		break;
		case C:
		port_value = READ_DATA_REGISTER_C;
		break;
		case A:
		port_value = READ_DATA_REGISTER_A;
		break;
	}
	return port_value;
}
void  PORT_PULL_UP (u8 port,u8 status)
{
	switch(status)
	{
		case ENABLE:
		switch(port)
		{
			case B:
			WRITE_DATA_REGISTER_B = 0Xff;
			break;
			case D:
			WRITE_DATA_REGISTER_D = 0Xff;
			break;
			case C:
			WRITE_DATA_REGISTER_C = 0Xff;
			break;
			case A:
			WRITE_DATA_REGISTER_A = 0Xff;
			break;
		}
		break;
		
		case DISABLE:
		switch(port)
		{
			case B:
			WRITE_DATA_REGISTER_B = 0X00;
			break;
			case D:
			WRITE_DATA_REGISTER_D = 0X00;
			break;
			case C:
			WRITE_DATA_REGISTER_C = 0X00;
			break;
			case A:
			WRITE_DATA_REGISTER_A = 0X00;
			break;
		}
		break;
	}
}
