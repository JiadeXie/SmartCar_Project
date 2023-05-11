#include "echo.h"
#include "IR_Trace.h"
#include "avoid.h"
#include "bt.h"

sbit KEY_1=P2^7;//默认为高电平，但接上超声波模块后，会变为低电平
sbit KEY_2=P2^6;//默认为高电平
sbit KEY_3=P2^5;//默认为高电平
sbit KEY_4=P2^4;//默认为高电平
sbit BEE=P3^2;

void main(void)
{
	uchar flag=0; //用于选择工作模式

	if(KEY_1==0)
	{
		Delay1ms();
		if(KEY_1==0)
		{
			flag=1;
			BEE=0;
			Delay1000ms(1);
			BEE=1;
		}
	}

	if(KEY_2==0)
	{
		Delay1ms();
		if(KEY_2==0)
		{
			flag=2;
			BEE=0;
			Delay1000ms(1);
			BEE=1;
		}
	}

	if(KEY_3==0)
	{
		Delay1ms();
		if(KEY_3==0) 
		{
			flag=3;
			BEE=0;
			Delay1000ms(1);
			BEE=1;
		}
	}

	if(KEY_4==0)
	{
		Delay1ms();
		if(KEY_4==0) 
		{
			flag=4;
			BEE=0;
			Delay1000ms(1);
			BEE=1;
		}
	}
	
	switch(flag)
	{
		case 1:ir_trace();break;
		case 2:ir_avoid();break;
		case 3:echo_avoid();break;
		case 4:bt();break;
	}

}