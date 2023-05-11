#include "avoid.h"


void ir_avoid(void)
{
	motor_timer0_init();
	stop();

	while(1)
	{
		if((AVOID_LEFT==1)&&(AVOID_RIGHT==1))//前面没有障碍物时
		{
			forward();
		}

		if((AVOID_LEFT==0)&&(AVOID_RIGHT==0))//前面有障碍物时
		{
			back();
      Delay500ms();
			left();	
      Delay500ms();
		}

		if((AVOID_LEFT==1)&&(AVOID_RIGHT==0))//右边有障碍物
		{
			left();
		}

		if((AVOID_LEFT==0)&&(AVOID_RIGHT==1))//左边有障碍物
		{
			right();
		}
	}

}