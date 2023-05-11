#include "IR_Trace.h"

void ir_trace(void)
{
	motor_timer0_init();//定时器初始化

	while(1)
	{
		if((TRACE_L==0)&&(TRACE_R==0))//扫描到白色地板
		{forward();}

		if((TRACE_L==1)&&(TRACE_R==0))//黑线在左侧，左转
		{left();}

		if((TRACE_L==0)&&(TRACE_R==1))//黑线在右侧，右转
		{right();}

		if((TRACE_L==1)&&(TRACE_R==1))//扫描到结束的黑线
		{stop();}
	}
}