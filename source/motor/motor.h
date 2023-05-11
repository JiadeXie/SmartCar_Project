#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "public.h"

extern uchar PWM_VALUE;
extern uchar PWM_LEVEL;

void forward(void);
void back(void);
void left(void);
void right(void);
void stop(void);
void motor_timer0_init(void);

#endif