#ifndef __IR_TRACE_H__
#define __IR_TRACE_H__

#include "motor.h"

sbit TRACE_R=P3^5;//扫描到白色为低电平，黑色时为高电平
sbit TRACE_L=P3^6;//扫描到白色为低电平，黑色时为高电平

void ir_trace(void);

#endif