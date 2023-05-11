#ifndef __ECHO_H__
#define __ECHO_H__

#include "public.h"
#include "display.h"
#include "motor.h"
#include "servo.h"


sbit TRIG=P2^6;  //���ڷ��ͳ�����
sbit ECHO=P3^3;  //���ڽ��ܻ�����ԭ����ΪP2^7,�����ڰ���1��P2^7���ã��ʸ�ΪP3^3

void echo_timer1_init(void);
void send_echo(void);
void rec_echo_count(void);
void echo_dat_count(void);
void distance_display(void);
void echo_avoid(void);

#endif