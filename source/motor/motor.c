#include "motor.h"

sbit EN1_2=P2^5;//�ұ�����ʹ��
sbit EN3_4=P2^4;//�������ʹ��

sbit IN1=P1^0;//����1
sbit IN2=P1^1;//����1
sbit IN3=P1^2;//����2
sbit IN4=P1^3;//����2

sbit IN5=P1^4;//����1
sbit IN6=P1^5;//����1
sbit IN7=P1^6;//����2
sbit IN8=P1^7;//����2


uchar PWM_VALUE;//PWM����ֵ
uchar PWM_LEVEL;//PWM�Ƚ�ֵ


void motor_timer0_init(void)//��ʱ��0��ʼ��
{
	TMOD&=0XF0;			//ѡ��16λ��ʱ
	TMOD|=0X01;
	TH0= 0XFc;		  //1ms��ʱ
	TL0= 0X18;
	TR0= 1;
	ET0= 1;
	EA = 1;
	PT0=0;					//����Ϊ���ж����ȼ�
}

void motor_pwm(void) interrupt 1 //�жϺ���
{
	TH0= 0XFc;		  //1ms��ʱ
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


void forward(void) //��ǰ
{
	PWM_LEVEL=7;

	IN1=0;
	IN2=1;//����1��ǰ

	IN3=0;
	IN4=1;//����2��ǰ

	IN5=1;
	IN6=0;//����1��ǰ

	IN7=1;
	IN8=0;//����2��ǰ
}

void back(void) //���
{
	PWM_LEVEL=7;

	IN1=1;
	IN2=0;//����1���

	IN3=1;
	IN4=0;//����2���

	IN5=0;
	IN6=1;//����1���

	IN7=0;
	IN8=1;//����2���

}

void left(void) //��ת
{
	PWM_LEVEL=7;

	IN1=0;
	IN2=1;//����1��ǰ

	IN3=0;
	IN4=1;//����2��ǰ

	IN5=0;
	IN6=1;//����1���

	IN7=0;
	IN8=1;//����2���
}

void right(void) //��ת
{
	PWM_LEVEL=7;

	IN1=1;
	IN2=0;//����1���

	IN3=1;
	IN4=0;//����2���

	IN5=1;
	IN6=0;//����1��ǰ

	IN7=1;
	IN8=0;//����2��ǰ
}

void stop(void) //ͣ
{
	IN1=0;
	IN2=0;//����1ͣ

	IN3=0;
	IN4=0;//����2ͣ

	IN5=0;
	IN6=0;//����1ͣ

	IN7=0;
	IN8=0;//����2ͣ
}