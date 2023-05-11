#ifndef __BT_H__
#define __BT_H__

#include "motor.h"
void bt(void);

sbit TX=P3^0;
sbit RX=P3^1;

void uart_init(void);
void uart_send_byte(uchar ch);
void uart_send_string(unsigned char* pt1,unsigned char* pt2);

#endif