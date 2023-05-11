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
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TMOD |= 0x10;			//���ö�ʱ��ģʽ
	TL1 = 0x33;				//���ö�ʱ��ʼֵ500us
	TH1 = 0xFE;				//���ö�ʱ��ʼֵ500us
	TF1 = 0;					//���TF1��־
	EA=1;							//����ȫ���ж�
	ET1=1;						//����TIMER1�ж�
	TR1=1;						//������ʱ��1
	PT1=1;						//����Ϊ���ж����ȼ�
}

void servo_pwm(void) interrupt 3
{
	TL1 = 0x33;				//���ö�ʱ��ʼֵ500us
	TH1 = 0xFE;				//���ö�ʱ��ʼֵ500us
	
	if(SERVO_PWM_VALUE<SERVO_PWM_LEVEL) {SERVO=1;}
	else	{SERVO=0;}
	SERVO_PWM_VALUE++;
	if(SERVO_PWM_VALUE==40) {SERVO_PWM_VALUE=0;}  //PWM����Ϊ20ms
}

void servo_turn_0(void) //���ַ���Ϊ0��
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=1;
}

void servo_turn_45(void) //���ת��45��
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=2;
}

void servo_turn_90(void) //���ת��90��
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=3;
}


void servo_turn_145(void) //���ת��145��
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=4;
}

void servo_turn_180(void) //���ת��180��
{
SERVO_PWM_VALUE=0;
servo_timer1_init();
SERVO_PWM_LEVEL=5;
}