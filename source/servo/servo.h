#ifndef __SERVO_H__
#define __SERVO_H__


#include "public.h"

sbit SERVO=P2^3;
extern uchar SERVO_PWM_VALUE;
extern uchar SERVO_PWM_LEVEL;

void servo_timer1_init(void);
void servo_turn_0(void);
void servo_turn_45(void);
void servo_turn_90(void);
void servo_turn_145(void);
void servo_turn_180(void);

#endif