#include "bt.h"
#include "echo.h"
#include "IR_Trace.h"
#include "avoid.h"

uchar SEND_DAT;
uchar RECE_DAT;

unsigned char code ch1[]="收到指令，";
unsigned char code ch2[]="前进！";
unsigned char code ch3[]="后退！";
unsigned char code ch4[]="左转！";
unsigned char code ch5[]="右转！";
unsigned char code ch6[]="停！";
unsigned char code ch7[]="进入红外循迹模式！";
unsigned char code ch8[]="进入红外避障模式！";
unsigned char code ch9[]="进入超声波避障模式！";


void bt(void)
{
	uart_init();  //串口初始化
	motor_timer0_init();  //电机初始化
	while(1)
	{
		switch(RECE_DAT)
		{
			case 'a':forward();break;  //前进
			case 'b':back();break;  //后退
			case 'c':left();break;  //左转
			case 'd':right();break;  //右转
			case 'e':stop();break;  //停
			case 'f':ir_trace();break;  //红外循迹	
			case 'g':ir_avoid();break;  //红外避障
			case 'h':echo_avoid();break;  //超声波避障
		}
	}
}

void uart_init(void)
{
	SCON=0X50; //设置为串口工作方式1，允许串口接收
	PCON=0X00; //波特率不加倍
	TMOD&=0X0F;
	TMOD|=0X20;//设置计时器1为8位自动重装模式
	TH1=253;   //波特率设置为9600
	TL1=253;   
	PS=1;      //设置串口中断优先级为高
	EA=1;      //打开全局中断
	ET1=0;     //关闭定时器1中断
	ES=1;      //打开串口中断
	TR1=1;     //打开计时器1
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
		case 'a':uart_send_string(ch1,ch2);break;  //前进
		case 'b':uart_send_string(ch1,ch3);break;  //后退
		case 'c':uart_send_string(ch1,ch4);break;  //左转
		case 'd':uart_send_string(ch1,ch5);break;  //右转
		case 'e':uart_send_string(ch1,ch6);break;  //停
		case 'f':uart_send_string(ch1,ch7);break;  //红外循迹	
		case 'g':uart_send_string(ch1,ch8);break;  //红外避障
		case 'h':uart_send_string(ch1,ch9);break;  //超声波避障
	}

}