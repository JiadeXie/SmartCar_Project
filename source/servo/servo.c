#include "servo.h"

uchar SERVO_PWM_VALUE=0;
uchar SERVO_PWM_LEVEL=0;

//void main(void)
//{

//servo_turn_90();
//while(1);

//}

void servo_timer1_init(void)
{
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x10;			//设置定时器模式
	TL1 = 0x33;				//设置定时初始值500us
	TH1 = 0xFE;				//设置定时初始值500us
	TF1 = 0;					//清除TF1标志
	EA=1;							//开启全局中断
	ET1=1;						//开启TIMER1中断
	TR1=1;						//开启定时器1
	PT1=1;						//设置为高中断优先级
}

void servo_pwm(void) interrupt 3
{
	TL1 = 0x33;				//设置定时初始值500us
	TH1 = 0xFE;				//设置定时初始值500us
	
	if(SERVO_PWM_VALUE<SERVO_PWM_LEVEL) {SERVO=1;}
	else	{SERVO=0;}
	SERVO_PWM_VALUE++;
	if(SERVO_PWM_VALUE==40) {SERVO_PWM_VALUE=0;}  //PWM周期为20ms
}

void servo_turn_0(void) //左轮方向为0度
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=1;
}

void servo_turn_45(void) //舵机转向45度
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=2;
}

void servo_turn_90(void) //舵机转向90度
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=3;
}


void servo_turn_145(void) //舵机转向145度
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=4;
}

void servo_turn_180(void) //舵机转向180度
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=5;
}