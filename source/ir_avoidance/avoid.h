#ifndef __AVOID_H__
#define __AVOID_H__

#include "motor.h"


sbit AVOID_LEFT=P3^7; //◊Û±‹’œIR
sbit AVOID_RIGHT=P3^4;//”“±‹’œIR

void ir_avoid(void);


#endif