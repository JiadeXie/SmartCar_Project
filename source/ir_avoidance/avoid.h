#ifndef __AVOID_H__
#define __AVOID_H__

#include "motor.h"


sbit AVOID_LEFT=P3^7; //�����IR
sbit AVOID_RIGHT=P3^4;//�ұ���IR

void ir_avoid(void);


#endif