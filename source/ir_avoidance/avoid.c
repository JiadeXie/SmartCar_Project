#include "avoid.h"


void ir_avoid(void)
{
	motor_timer0_init();
	stop();

	while(1)
	{
		if((AVOID_LEFT==1)&&(AVOID_RIGHT==1))//ǰ��û���ϰ���ʱ
		{
			forward();
		}

		if((AVOID_LEFT==0)&&(AVOID_RIGHT==0))//ǰ�����ϰ���ʱ
		{
			back();
      Delay500ms();
			left();	
      Delay500ms();
		}

		if((AVOID_LEFT==1)&&(AVOID_RIGHT==0))//�ұ����ϰ���
		{
			left();
		}

		if((AVOID_LEFT==0)&&(AVOID_RIGHT==1))//������ϰ���
		{
			right();
		}
	}

}