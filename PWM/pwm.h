#ifndef __PWM_H
#define __PWM_H
#include "sys.h"



void TIM4_PWM_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void straight(void);
void rightH(void);
void rightL(void);
void leftH(void);
void leftL(void);
void stop(void);
void be_stop(void);

#endif
