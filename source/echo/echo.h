#ifndef __ECHO_H__
#define __ECHO_H__

#include "public.h"
#include "display.h"
#include "motor.h"
#include "servo.h"


sbit TRIG=P2^6;  //用于发送超声波
sbit ECHO=P3^3;  //用于接受回声，原引脚为P2^7,但由于按键1与P2^7公用，故改为P3^3

void echo_timer1_init(void);
void send_echo(void);
void rec_echo_count(void);
void echo_dat_count(void);
void distance_display(void);
void echo_avoid(void);

#endif