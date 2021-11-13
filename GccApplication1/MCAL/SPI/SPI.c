
#include "SPI_CFG.h"
#include "SPI.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "REG.h"

void SPI_INIT(void)
{
	#if SPI_MODE     ==     MASTER
	PIN_MODE(PB4,OUTPUT);
	PIN_MODE(PB5,OUTPUT);
	PIN_MODE(PB6,INPUT);
	PIN_MODE(PB7,OUTPUT);
	
	SET_BIT(SPCR,4);
	SET_BIT(SPCR,6);
	
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	#elif SPI_MODE     ==  SLAVE
	PIN_MODE(PB4,INPUT);
	PIN_MODE(PB5,INPUT);
	PIN_MODE(PB6,OUTPUT);
	PIN_MODE(PB7,INPUT);
	
	SET_BIT(SPCR,6);
	#endif
}

void SPI_START_TR(void)
{
	PIN_WRITE(PB4,LOW);
}
void SPI_STOP_TR(void)
{
	PIN_WRITE(PB4,HIGH);
}
u8   SPI_TRANSIVER(u8 data)
{
	u8 rec_data = 0;
	SPDR = data;
	while(GET_BIT(SPSR,7) == 0);
	rec_data = SPDR;
	return rec_data;
}
