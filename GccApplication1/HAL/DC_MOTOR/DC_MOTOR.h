
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "STD_TYPES.h"

#define CLOCK_WISE        0
#define ANTI_CLOCK_WISE   1

void DC_MOTOR_INIT(void);
void DC_MOTOR_SET_DIRECTION(u8);
void DC_MOTOR_SET_DUTY_CYCLE(u8);
void DC_MOTOR_START(void);
void DC_MOTOR_OFF(void);

#endif /* DC_MOTOR_H_ */
