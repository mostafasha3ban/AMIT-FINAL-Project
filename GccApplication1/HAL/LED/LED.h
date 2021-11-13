
#ifndef LED_H_
#define LED_H_

#include "STD_TYPES.h"

/***** PROTOTYPES *****/
void LED_INIT   (u8);
void LED_ON     (u8);
void LED_OFF    (u8);
void LED_TOGGLE (u8);
void LEDS_ON    (void);
void LEDS_OFF   (void);
/******* MACROS *******/
#define R_LED   0
#define M_LED   1
#define L_LED   2

#endif /* LED_H_ */
