#ifndef __DISPLAY_H__
#define __DISPLAY_H__



#include "public.h"

extern code uchar CODE[]; //�����

sbit LED1=P2^0; //�����һλ�����
sbit LED2=P2^1;	//����ڶ�λ�����
sbit LED3=P2^2;

void display_byte_LED1(uchar dat);
void display_byte_LED2(uchar dat);
void display_byte_LED3(uchar dat);


#endif