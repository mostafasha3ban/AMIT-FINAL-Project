
#ifndef DIO_H_
#define DIO_H_
#include "STD_TYPES.h"
/***************** PORTB MACROS *****************/
#define PB0      10
#define PB1      11
#define PB2      12
#define PB3      13
#define PB4      14
#define PB5      15
#define PB6      16
#define PB7      17
/***************** PORTD MACROS *****************/
#define PD0      20
#define PD1      21
#define PD2      22
#define PD3      23
#define PD4      24
#define PD5      25
#define PD6      26
#define PD7      27
/***************** PORTC MACROS *****************/
#define PC0      30
#define PC1      31
#define PC2      32
#define PC3      33
#define PC4      34
#define PC5      35
#define PC6      36
#define PC7      37
/***************** PORTA MACROS *****************/
#define PA0      40
#define PA1      41
#define PA2      42
#define PA3      43
#define PA4      44
#define PA5      45
#define PA6      46
#define PA7      47
/***************** PORTS MACROS *****************/
#define B         0
#define D         1
#define C         2
#define A         3
/***************** OTHER MACROS *****************/
#define INPUT     0
#define OUTPUT    1

#define LOW       0
#define HIGH      1

#define ENABLE    1
#define DISABLE   0
/****************** PROTOTYPES ******************/
void  PIN_MODE     (u8,u8);
void  PIN_WRITE    (u8,u8);  
void  PIN_TOGGLE   (u8);
u8    PIN_READ     (u8);         // NOT TEASTED YET
void  PIN_PULL_UP  (u8,u8);      // NOT TEASTED YET

void  PORT_MODE    (u8,u8);
void  PORT_WRITE   (u8,u8);
void  PORT_TOGGLE  (u8);
u8    PORT_READ    (u8);         // NOT TEASTED YET
void  PORT_PULL_UP (u8,u8);      // NOT TEASTED YET
#endif /* DIO_H_ */
