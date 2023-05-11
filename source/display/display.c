#include "display.h"


uchar code CODE[10]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};  //¶ÎÂë±í


void display_byte_LED1(uchar dat)
{
P0=dat;
LED1=0;
Delay2ms();
LED1=1;
}

void display_byte_LED2(uchar dat)
{
P0=dat;
LED2=0;
Delay2ms();
LED2=1;
}

void display_byte_LED3(uchar dat)
{
P0=dat;
LED3=0;
Delay2ms();
LED3=1;
}