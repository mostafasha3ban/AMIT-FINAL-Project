
#ifndef SPI_H_
#define SPI_H_

#include "STD_TYPES.h"

void SPI_INIT(void);
void SPI_START_TR(void);
void SPI_STOP_TR(void);
u8   SPI_TRANSIVER(u8);

#define MASTER     1
#define SLAVE      2

#endif /* SPI_H_ */
