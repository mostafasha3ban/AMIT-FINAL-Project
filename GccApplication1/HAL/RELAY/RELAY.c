
#include "RELAY_CFG.h"
#include "DIO.h"

void RELAY_INIT (void)
{
	PIN_MODE(RELAY_PIN,OUTPUT);
}
void RELAY_ON   (void)
{
	PIN_WRITE(RELAY_PIN,HIGH);
}
void RELAY_OFF  (void)
{
	PIN_WRITE(RELAY_PIN,LOW);
}
