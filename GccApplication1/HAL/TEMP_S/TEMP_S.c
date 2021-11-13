
#include "ADC.h"
#include "TEMP_S_CFG.h"

void TEMP_S_INIT(void)
{
	ADC_INIT();
}
u16  TEMP_S_READ(void)
{
	u16 value;	
	value = ADC_READ(TEMP_S_PIN);
	u16 temp;
	temp = ((u32)value * 500 ) / 1023;
	return temp;
}
