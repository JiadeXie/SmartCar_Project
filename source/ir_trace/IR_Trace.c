#include "IR_Trace.h"

void ir_trace(void)
{
	motor_timer0_init();//��ʱ����ʼ��

	while(1)
	{
		if((TRACE_L==0)&&(TRACE_R==0))//ɨ�赽��ɫ�ذ�
		{forward();}

		if((TRACE_L==1)&&(TRACE_R==0))//��������࣬��ת
		{left();}

		if((TRACE_L==0)&&(TRACE_R==1))//�������Ҳ࣬��ת
		{right();}

		if((TRACE_L==1)&&(TRACE_R==1))//ɨ�赽�����ĺ���
		{stop();}
	}
}