/*
 * EEPROM.h
 *
 * Created: 09/10/2021 04:32:59 ص
 *  Author: dell
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_INIT(void);
void EEPROM_WRITE(u8,u16);
u8   EEPROM_READ(u16);

#endif /* EEPROM_H_ */