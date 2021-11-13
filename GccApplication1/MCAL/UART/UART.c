
#include "UART_CFG.h"
#include "DIO.h"
#include "BIT_MATH.h"
#include "REG.h"
void UART_INIT(void)
{
	PIN_MODE(PD0,INPUT);
	PIN_MODE(PD1,OUTPUT);
	
	UBRRL = (CRYSTAL_FREQUANCY / (16 * BUAD_RATE)) - 1;
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	
	SET_BIT(UCSRC,7);
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);


	
}
void UART_SEND(u8 data)
{
	UDR = data;
	while (GET_BIT(UCSRA,5) == 0)
	{
		
	}
}
u8   UART_REC(void)
{
	while(GET_BIT(UCSRC,7) == 0)
	{
		
	}
	return UDR;
}
