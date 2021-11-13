/*
 * EEPROM_24C16.h
 *
 * Created: 09/10/2021 09:57:49 ص
 *  Author: dell
 */ 


#ifndef EEPROM_24C16_H_
#define EEPROM_24C16_H_

#include "STD_TYPES.h"

void EEPROM_24C16_INIT(void);
void EEPROM_24C16_WRITE(u8,u8);
u8   EEPROM_24C16_READ(u8);


#endif /* EEPROM_24C16_H_ */