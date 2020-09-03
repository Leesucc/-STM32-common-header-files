#include "L298N.h"

void L298N_INIT()
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	GPIO_InitStructure.GPIO_Pin=INI11|INI12|INI13|INI14|INI21|INI22|INI23|INI24;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	INI11_L;
	INI12_L;
	INI13_L;
	INI14_L;
	INI21_L;
	INI22_L;
	INI23_L;
	INI24_L;
}
void left_up() // ������ת
{
	INI13_L;
	INI14_H;
	INI23_L;
	INI24_H;
}
void left_down()// ���ַ�ת
{
	INI13_H;
	INI14_L;
	INI23_H;
	INI24_L;
}
void right_up()// ������ת
{
	INI11_L;
	INI12_H;
	INI21_L;
	INI22_H;
}
void right_down()//���ַ�ת
{
	INI11_H;
	INI12_L;
	INI21_H;
	INI22_L;	
}
void left_stop()//����ֹͣ
{
	 INI13_H;
	 INI14_H;
	 INI23_H;
	 INI24_H;
}
void right_stop()//����ֹͣ
{
	 INI11_H;
	 INI12_H;
	 INI21_H;
	 INI22_H;
}
void up ()//��ǰ
{
	left_up();
	right_up();	
}
void down()//���
{
	left_down();
	right_down();
}

void  up_left()//��ǰ��ת
{	 	
	left_stop();
	right_up();	
}
void down_left()//�����ת
{
	left_stop();
	right_down();
}
void turn_left()// ԭ������
{
	left_down();
	right_up();	
}
void up_right()	//��ǰ��ת
{
	left_up();
	right_stop();	
}
void down_right() //�����ת
{
	left_down();
	right_stop();
}
void turn_right()  // ԭ����ת
{
	left_up();
	right_down();
}
void all_stop()	//ֹͣ
{
	left_stop();
	right_stop();

}
