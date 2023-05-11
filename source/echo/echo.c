#include "echo.h"


uint time;	
uint distance;			//��λʱCM
uchar echo_dat[3];  //echo_dat[0]==��λ,echo_dat[1]==ʮλ,echo_dat[2]==��λ�������������ʾ

void echo_avoid(void)
{
	stop();
	servo_turn_90();	//�������
	Delay500ms();     //��ʱ�㹻ʱ���ö����ת�����򲻹���

	motor_timer0_init();	//��ʱ��0�������PWM�ź�
	echo_timer1_init();		//�������źų�ʼ��

	while(1) 
	{
		send_echo();				//���ͳ�����
		rec_echo_count();		//���ճ��������������
		distance_display();	//�������ʾ����

		if(distance>30) {forward();}		//���ǰ���ϰ���������30cm��ǰ��
		else	
		{
			stop();
			servo_turn_0();		//�����ת
			Delay500ms();			
			
			echo_timer1_init();		//���ڲ������PWM�źŵļ�ʱ���ͽ��ճ������źŵļ�ʱ������timer1����˶��ÿ��ת���
			send_echo();					//��Ҫ���³�ʼ��timer1���Ա㷢�ͽ��ճ�����
			rec_echo_count();			//���ճ��������������
			distance_display();		//�������ʾ����
			//Delay1000ms(1);
			if(distance>30) 			//����ҷ��ϰ���������30cm
			{
				right();						//С����ת
				Delay500ms();
				servo_turn_90();		//�������
				Delay500ms();
				echo_timer1_init();
				send_echo();
				rec_echo_count();
				distance_display();
				forward();					//С����ǰ
			}
			else									//����ҷ��ϰ������С��30cm
			{
				stop();
				servo_turn_180();		//�����ת
				Delay500ms();

				echo_timer1_init();
				send_echo();
				rec_echo_count();
				distance_display();
				if(distance>30)			//������ϰ���������30cm
				{
					left();						//С����ת
					Delay500ms();
					servo_turn_90();	//�������
					Delay500ms();
					echo_timer1_init();
					send_echo();
					rec_echo_count();
					distance_display();
					forward();
				}
				else 								//���ǰ���ң����ϰ�����붼С��30cm
				{
					stop();
					servo_turn_90();	//�������
					Delay500ms();
					back();						//С������
					Delay500ms();
					right();
					Delay500ms();
					echo_timer1_init();
					send_echo();
					rec_echo_count();
					distance_display();
					continue;					//С���˳�����ѭ��
				}
			}
		}

	}
}

void echo_timer1_init(void)
{
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TMOD |= 0x10;			//���ö�ʱ��ģʽ
	TL1 = 0x00;				//���ö�ʱ��ʼֵ
	TH1 = 0x00;				//���ö�ʱ��ʼֵ
	TF1 = 0;					//���TF1��־
	TR1=0;						//�رն�ʱ��1
	EA=1;							//ȫ���жϲ��ܹرգ�������PWM���ٲ�������
	ET1=0;						//�ر�TIMER1�ж�
}

void send_echo(void)
{
	TRIG=1;
	Delay20us();
	TRIG=0;
}

void rec_echo_count(void)
{
	while(!ECHO);       //δ�յ�����ʱ�ȴ�
	TR1=1;				      //�յ���������ʼ��ʱ
	while(ECHO);	      //�ȴ���������
	TR1=0;				      //�رն�ʱ��
	time=TH1*256+TL1;		//���㳬�����ӷ��䵽����ʱ��
	distance=(time*1.7)/100;    //distance=(((time/1000000)*340)*100)/2=(time*1.7)/100
	TH1=0;
	TL1=0;							//��ʱ��1����
	echo_dat_count();
}

void echo_dat_count(void)
{
	uchar temp=0;
	echo_dat[0]=distance%10;  //ȡ����λ
	temp=distance/10;
	echo_dat[1]=temp%10; //ȡ��ʮλ
	echo_dat[2]=distance/100; //ȡ����λ
}

void distance_display(void)
{
	display_byte_LED1(CODE[echo_dat[2]]);	 //��ʾ��λ
	display_byte_LED2(CODE[echo_dat[1]]);	 //��ʾʮλ
	display_byte_LED3(CODE[echo_dat[0]]);  //��ʾ��λ
}

