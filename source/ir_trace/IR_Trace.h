#ifndef __IR_TRACE_H__
#define __IR_TRACE_H__

#include "motor.h"

sbit TRACE_R=P3^5;//ɨ�赽��ɫΪ�͵�ƽ����ɫʱΪ�ߵ�ƽ
sbit TRACE_L=P3^6;//ɨ�赽��ɫΪ�͵�ƽ����ɫʱΪ�ߵ�ƽ

void ir_trace(void);

#endif