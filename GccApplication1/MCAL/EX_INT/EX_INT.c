
#include "REG.h"
#include "BIT_MATH.h"

void EXTERNAL_INT_0_INIT(void)
{
	SET_BIT(SREG,7);         /*_TO_ENABLE_EXTERNAL_INT_*****************/
	SET_BIT(GICR,6);         /*_TO_ENABLE_TNTERRUPT_0_******************/
	CLR_BIT(MCUCR,0);        /*_DETERMINE_ACTION_TRIGGER_THE_INTERRUPT_*/
	SET_BIT(MCUCR,1);        /*_DETERMINE_ACTION_TRIGGER_THE_INTERRUPT_*/
}
