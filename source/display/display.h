#ifndef __DISPLAY_H__
#define __DISPLAY_H__



#include "public.h"

extern code uchar CODE[]; //段码表

sbit LED1=P2^0; //左起第一位数码管
sbit LED2=P2^1;	//左起第二位数码管
sbit LED3=P2^2;

void display_byte_LED1(uchar dat);
void display_byte_LED2(uchar dat);
void display_byte_LED3(uchar dat);


#endif