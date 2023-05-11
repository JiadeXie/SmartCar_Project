#include "echo.h"


uint time;	
uint distance;			//单位时CM
uchar echo_dat[3];  //echo_dat[0]==个位,echo_dat[1]==十位,echo_dat[2]==百位，用于数码管显示

void echo_avoid(void)
{
	stop();
	servo_turn_90();	//舵机归中
	Delay500ms();     //延时足够时间让舵机旋转，否则不工作

	motor_timer0_init();	//定时器0产生电机PWM信号
	echo_timer1_init();		//超声波信号初始化

	while(1) 
	{
		send_echo();				//发送超声波
		rec_echo_count();		//接收超声波并计算距离
		distance_display();	//数码管显示距离

		if(distance>30) {forward();}		//如果前方障碍物距离大于30cm，前进
		else	
		{
			stop();
			servo_turn_0();		//舵机右转
			Delay500ms();			
			
			echo_timer1_init();		//由于产生舵机PWM信号的计时器和接收超声波信号的计时器都是timer1，因此舵机每次转向后，
			send_echo();					//都要重新初始化timer1，以便发送接收超声波
			rec_echo_count();			//接收超声波并计算距离
			distance_display();		//数码管显示距离
			//Delay1000ms(1);
			if(distance>30) 			//如果右方障碍物距离大于30cm
			{
				right();						//小车右转
				Delay500ms();
				servo_turn_90();		//舵机归中
				Delay500ms();
				echo_timer1_init();
				send_echo();
				rec_echo_count();
				distance_display();
				forward();					//小车向前
			}
			else									//如果右方障碍物距离小于30cm
			{
				stop();
				servo_turn_180();		//舵机左转
				Delay500ms();

				echo_timer1_init();
				send_echo();
				rec_echo_count();
				distance_display();
				if(distance>30)			//如果左方障碍物距离大于30cm
				{
					left();						//小车左转
					Delay500ms();
					servo_turn_90();	//舵机归中
					Delay500ms();
					echo_timer1_init();
					send_echo();
					rec_echo_count();
					distance_display();
					forward();
				}
				else 								//如果前，右，左方障碍物距离都小于30cm
				{
					stop();
					servo_turn_90();	//舵机归中
					Delay500ms();
					back();						//小车后退
					Delay500ms();
					right();
					Delay500ms();
					echo_timer1_init();
					send_echo();
					rec_echo_count();
					distance_display();
					continue;					//小车退出本次循环
				}
			}
		}

	}
}

void echo_timer1_init(void)
{
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x10;			//设置定时器模式
	TL1 = 0x00;				//设置定时初始值
	TH1 = 0x00;				//设置定时初始值
	TF1 = 0;					//清除TF1标志
	TR1=0;						//关闭定时器1
	EA=1;							//全局中断不能关闭，否则电机PWM调速不起作用
	ET1=0;						//关闭TIMER1中断
}

void send_echo(void)
{
	TRIG=1;
	Delay20us();
	TRIG=0;
}

void rec_echo_count(void)
{
	while(!ECHO);       //未收到回声时等待
	TR1=1;				      //收到声波，开始计时
	while(ECHO);	      //等待声波结束
	TR1=0;				      //关闭定时器
	time=TH1*256+TL1;		//计算超声波从发射到接收时间
	distance=(time*1.7)/100;    //distance=(((time/1000000)*340)*100)/2=(time*1.7)/100
	TH1=0;
	TL1=0;							//计时器1清零
	echo_dat_count();
}

void echo_dat_count(void)
{
	uchar temp=0;
	echo_dat[0]=distance%10;  //取出个位
	temp=distance/10;
	echo_dat[1]=temp%10; //取出十位
	echo_dat[2]=distance/100; //取出百位
}

void distance_display(void)
{
	display_byte_LED1(CODE[echo_dat[2]]);	 //显示百位
	display_byte_LED2(CODE[echo_dat[1]]);	 //显示十位
	display_byte_LED3(CODE[echo_dat[0]]);  //显示个位
}

