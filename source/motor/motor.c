#include "motor.h"

sbit EN1_2=P2^5;//右边轮子使能
sbit EN3_4=P2^4;//左边轮子使能

sbit IN1=P1^0;//右轮1
sbit IN2=P1^1;//右轮1
sbit IN3=P1^2;//右轮2
sbit IN4=P1^3;//右轮2

sbit IN5=P1^4;//左轮1
sbit IN6=P1^5;//左轮1
sbit IN7=P1^6;//左轮2
sbit IN8=P1^7;//左轮2


uchar PWM_VALUE;//PWM计数值
uchar PWM_LEVEL;//PWM比较值


void motor_timer0_init(void)//计时器0初始化
{
	TMOD&=0XF0;			//选择16位计时
	TMOD|=0X01;
	TH0= 0XFc;		  //1ms定时
	TL0= 0X18;
	TR0= 1;
	ET0= 1;
	EA = 1;
	PT0=0;					//设置为低中断优先级
}

void motor_pwm(void) interrupt 1 //中断函数
{
	TH0= 0XFc;		  //1ms定时
	TL0= 0X18;
	if(PWM_VALUE<PWM_LEVEL)
	{
		EN1_2=1;
		EN3_4=1;
	}
	else
	{
		EN1_2=0;
		EN3_4=0;
	}
	PWM_VALUE++;
	if(PWM_VALUE>=20) {PWM_VALUE=0;}
}


void forward(void) //向前
{
	PWM_LEVEL=7;

	IN1=0;
	IN2=1;//右轮1向前

	IN3=0;
	IN4=1;//右轮2向前

	IN5=1;
	IN6=0;//左轮1向前

	IN7=1;
	IN8=0;//左轮2向前
}

void back(void) //向后
{
	PWM_LEVEL=7;

	IN1=1;
	IN2=0;//右轮1向后

	IN3=1;
	IN4=0;//右轮2向后

	IN5=0;
	IN6=1;//左轮1向后

	IN7=0;
	IN8=1;//左轮2向后

}

void left(void) //左转
{
	PWM_LEVEL=7;

	IN1=0;
	IN2=1;//右轮1向前

	IN3=0;
	IN4=1;//右轮2向前

	IN5=0;
	IN6=1;//左轮1向后

	IN7=0;
	IN8=1;//左轮2向后
}

void right(void) //右转
{
	PWM_LEVEL=7;

	IN1=1;
	IN2=0;//右轮1向后

	IN3=1;
	IN4=0;//右轮2向后

	IN5=1;
	IN6=0;//左轮1向前

	IN7=1;
	IN8=0;//左轮2向前
}

void stop(void) //停
{
	IN1=0;
	IN2=0;//右轮1停

	IN3=0;
	IN4=0;//右轮2停

	IN5=0;
	IN6=0;//左轮1停

	IN7=0;
	IN8=0;//左轮2停
}