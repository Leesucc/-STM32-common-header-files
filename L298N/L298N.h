#ifndef _L298N_H
#define _L298N_H
#include "stm32f10x.h"

#define INI11    GPIO_Pin_1		  //PA0
#define INI12    GPIO_Pin_0		  //PA1
#define INI13	   GPIO_Pin_2		  //PA2
#define INI14    GPIO_Pin_3		  //PA3

#define INI21		 GPIO_Pin_5
#define INI22    GPIO_Pin_4
#define INI23    GPIO_Pin_6
#define INI24    GPIO_Pin_7

#define GPIO_L298N GPIOC	 //����ܽŶ���

#define INI11_H GPIO_SetBits(GPIO_L298N,INI11)
#define INI11_L GPIO_ResetBits(GPIO_L298N,INI11)
#define INI12_H GPIO_SetBits(GPIO_L298N,INI12)
#define INI12_L GPIO_ResetBits(GPIO_L298N,INI12)
#define INI13_H GPIO_SetBits(GPIO_L298N,INI13)
#define INI13_L GPIO_ResetBits(GPIO_L298N,INI13)
#define INI14_H GPIO_SetBits(GPIO_L298N,INI14)
#define INI14_L GPIO_ResetBits(GPIO_L298N,INI14)

#define INI21_H GPIO_SetBits(GPIO_L298N,INI21)
#define INI21_L GPIO_ResetBits(GPIO_L298N,INI21)
#define INI22_H GPIO_SetBits(GPIO_L298N,INI22)
#define INI22_L GPIO_ResetBits(GPIO_L298N,INI22)
#define INI23_H GPIO_SetBits(GPIO_L298N,INI23)
#define INI23_L GPIO_ResetBits(GPIO_L298N,INI23)
#define INI24_H GPIO_SetBits(GPIO_L298N,INI24)
#define INI24_L GPIO_ResetBits(GPIO_L298N,INI24)




void L298N_INIT(void);
void left_up(void); // ������ת
void left_down(void);// ���ַ�ת
void right_up(void);// ������ת
void right_down(void);//���ַ�ת
void left_stop(void);//����ֹͣ
void right_stop(void);//����ֹͣ
void up (void);//��ǰ
void down(void);//���
void  up_left(void);//��ǰ��ת
void down_left(void);//�����ת
void turn_left(void);// ԭ������
void up_right(void);//��ǰ��ת
void down_right(void);//�����ת
void turn_right(void); // ԭ����ת
void all_stop(void);//ֹͣ

#endif
