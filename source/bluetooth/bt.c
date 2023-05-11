#include "bt.h"
#include "echo.h"
#include "IR_Trace.h"
#include "avoid.h"

uchar SEND_DAT;
uchar RECE_DAT;

unsigned char code ch1[]="�յ�ָ�";
unsigned char code ch2[]="ǰ����";
unsigned char code ch3[]="���ˣ�";
unsigned char code ch4[]="��ת��";
unsigned char code ch5[]="��ת��";
unsigned char code ch6[]="ͣ��";
unsigned char code ch7[]="�������ѭ��ģʽ��";
unsigned char code ch8[]="����������ģʽ��";
unsigned char code ch9[]="���볬��������ģʽ��";


void bt(void)
{
	uart_init();  //���ڳ�ʼ��
	motor_timer0_init();  //�����ʼ��
	while(1)
	{
		switch(RECE_DAT)
		{
			case 'a':forward();break;  //ǰ��
			case 'b':back();break;  //����
			case 'c':left();break;  //��ת
			case 'd':right();break;  //��ת
			case 'e':stop();break;  //ͣ
			case 'f':ir_trace();break;  //����ѭ��	
			case 'g':ir_avoid();break;  //�������
			case 'h':echo_avoid();break;  //����������
		}
	}
}

void uart_init(void)
{
	SCON=0X50; //����Ϊ���ڹ�����ʽ1�������ڽ���
	PCON=0X00; //�����ʲ��ӱ�
	TMOD&=0X0F;
	TMOD|=0X20;//���ü�ʱ��1Ϊ8λ�Զ���װģʽ
	TH1=253;   //����������Ϊ9600
	TL1=253;   
	PS=1;      //���ô����ж����ȼ�Ϊ��
	EA=1;      //��ȫ���ж�
	ET1=0;     //�رն�ʱ��1�ж�
	ES=1;      //�򿪴����ж�
	TR1=1;     //�򿪼�ʱ��1
}

void uart_send_byte(uchar ch)
{
	SBUF=ch;
	while(!TI);
	TI=0;
}

void uart_send_string(unsigned char* pt1,unsigned char* pt2)
{
	while(*pt1!='\0')
	{
		uart_send_byte(*pt1);
		pt1++;
	}

	while(*pt2!='\0')
	{
		uart_send_byte(*pt2);
		pt2++;
	}

}

void uart_rece_byte(void) interrupt 4
{
	if(RI==1)
	{
		RECE_DAT=SBUF;
		RI=0;
	}

//	uart_send_byte(RECE_DAT);

	switch(RECE_DAT)
	{
		case 'a':uart_send_string(ch1,ch2);break;  //ǰ��
		case 'b':uart_send_string(ch1,ch3);break;  //����
		case 'c':uart_send_string(ch1,ch4);break;  //��ת
		case 'd':uart_send_string(ch1,ch5);break;  //��ת
		case 'e':uart_send_string(ch1,ch6);break;  //ͣ
		case 'f':uart_send_string(ch1,ch7);break;  //����ѭ��	
		case 'g':uart_send_string(ch1,ch8);break;  //�������
		case 'h':uart_send_string(ch1,ch9);break;  //����������
	}

}