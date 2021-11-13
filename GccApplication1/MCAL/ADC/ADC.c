
#include "ADC_CFG.h"
#include "ADC.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "REG.h"

void ADC_INIT(void)
{
	#if ADC_VREF == AVCC
	SET_BIT(ADMUX,6);		 
	CLR_BIT(ADMUX,7);		
	#elif ADC_VREF == AREF
	CLR_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	#elif ADC_VREF == _2V
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
	#endif
	#if ADC_ADJUSTMENT   == RIGHT
	CLR_BIT(ADMUX,5);
	#elif ADC_ADJUSTMENT == LEFT
	SET_BIT(ADMUX,5);
	#endif
	#if AUTO_TRIGERING_MODE    ==   ENABLE
	SET_BIT(ADCSRA,5);     
	#elif AUTO_TRIGERING_MODE  ==   DISABLE
	CLR_BIT(ADCSRA,5); 
	#endif
	#if ADC_PRESCALER   == _64
	CLR_BIT(ADCSRA,0);       
	SET_BIT(ADCSRA,1);       
	SET_BIT(ADCSRA,2);  
	#elif ADC_PRESCALER == _128     
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	#endif
	
	SET_BIT(ADCSRA,7);       /*_TO_ENABLE_ADC_*/
}

u16 ADC_READ(u8 channel)
{
	switch(channel)
	{
		case 0:
		CLR_BIT(ADMUX,0);        /*_TO_SELECT_ADC_CHANNEL_0_*/
		CLR_BIT(ADMUX,1);        /*_TO_SELECT_ADC_CHANNEL_0_*/
		CLR_BIT(ADMUX,2);        /*_TO_SELECT_ADC_CHANNEL_0_*/
		CLR_BIT(ADMUX,3);        /*_TO_SELECT_ADC_CHANNEL_0_*/
		CLR_BIT(ADMUX,4);        /*_TO_SELECT_ADC_CHANNEL_0_*/
		break;
		case 1:
		SET_BIT(ADMUX,0);        /*_TO_SELECT_ADC_CHANNEL_1_*/
		CLR_BIT(ADMUX,1);        /*_TO_SELECT_ADC_CHANNEL_1_*/
		CLR_BIT(ADMUX,2);        /*_TO_SELECT_ADC_CHANNEL_1_*/
		CLR_BIT(ADMUX,3);        /*_TO_SELECT_ADC_CHANNEL_1_*/
		CLR_BIT(ADMUX,4);        /*_TO_SELECT_ADC_CHANNEL_1_*/
		break;
		case 2:
		CLR_BIT(ADMUX,0);        /*_TO_SELECT_ADC_CHANNEL_2_*/
		SET_BIT(ADMUX,1);        /*_TO_SELECT_ADC_CHANNEL_2_*/
		CLR_BIT(ADMUX,2);        /*_TO_SELECT_ADC_CHANNEL_2_*/
		CLR_BIT(ADMUX,3);        /*_TO_SELECT_ADC_CHANNEL_2_*/
		CLR_BIT(ADMUX,4);        /*_TO_SELECT_ADC_CHANNEL_2_*/
		break;
		case 3:
		SET_BIT(ADMUX,0);        /*_TO_SELECT_ADC_CHANNEL_3_*/
		SET_BIT(ADMUX,1);        /*_TO_SELECT_ADC_CHANNEL_3_*/
		CLR_BIT(ADMUX,2);        /*_TO_SELECT_ADC_CHANNEL_3_*/
		CLR_BIT(ADMUX,3);        /*_TO_SELECT_ADC_CHANNEL_3_*/
		CLR_BIT(ADMUX,4);        /*_TO_SELECT_ADC_CHANNEL_3_*/
		break;
		case 4:
		CLR_BIT(ADMUX,0);        /*_TO_SELECT_ADC_CHANNEL_4_*/
		CLR_BIT(ADMUX,1);        /*_TO_SELECT_ADC_CHANNEL_4_*/
		SET_BIT(ADMUX,2);        /*_TO_SELECT_ADC_CHANNEL_4_*/
		CLR_BIT(ADMUX,3);        /*_TO_SELECT_ADC_CHANNEL_4_*/
		CLR_BIT(ADMUX,4);        /*_TO_SELECT_ADC_CHANNEL_4_*/
		break;
		case 5:
		SET_BIT(ADMUX,0);        /*_TO_SELECT_ADC_CHANNEL_5_*/
		CLR_BIT(ADMUX,1);        /*_TO_SELECT_ADC_CHANNEL_5_*/
		SET_BIT(ADMUX,2);        /*_TO_SELECT_ADC_CHANNEL_5_*/
		CLR_BIT(ADMUX,3);        /*_TO_SELECT_ADC_CHANNEL_5_*/
		CLR_BIT(ADMUX,4);        /*_TO_SELECT_ADC_CHANNEL_5_*/
		break;
		case 6:
		CLR_BIT(ADMUX,0);        /*_TO_SELECT_ADC_CHANNEL_6_*/
		SET_BIT(ADMUX,1);        /*_TO_SELECT_ADC_CHANNEL_6_*/
		SET_BIT(ADMUX,2);        /*_TO_SELECT_ADC_CHANNEL_6_*/
		CLR_BIT(ADMUX,3);        /*_TO_SELECT_ADC_CHANNEL_6_*/
		CLR_BIT(ADMUX,4);        /*_TO_SELECT_ADC_CHANNEL_6_*/
		break;
		case 7:
		SET_BIT(ADMUX,0);        /*_TO_SELECT_ADC_CHANNEL_7_*/
		SET_BIT(ADMUX,1);        /*_TO_SELECT_ADC_CHANNEL_7_*/
		SET_BIT(ADMUX,2);        /*_TO_SELECT_ADC_CHANNEL_7_*/
		CLR_BIT(ADMUX,3);        /*_TO_SELECT_ADC_CHANNEL_7_*/
		CLR_BIT(ADMUX,4);        /*_TO_SELECT_ADC_CHANNEL_7_*/
		break;
	}
	u16 x = 0;
	SET_BIT(ADCSRA,6);                  /*_TO_START_CONVERSION_*/
	while(GET_BIT(ADCSRA,4) == 0)
	{
				
	}
	x = ADC_VALUE;
	return x;
}
