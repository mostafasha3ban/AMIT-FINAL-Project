
#ifndef UART_H_
#define UART_H_

#include "STD_TYPES.h"

void UART_INIT(void);
void UART_SEND(u8);
u8   UART_REC(void);

#endif /* UART_H_ */
