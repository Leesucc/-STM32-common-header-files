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
void left_up() // 左轮正转
{
	INI13_L;
	INI14_H;
	INI23_L;
	INI24_H;
}
void left_down()// 左轮反转
{
	INI13_H;
	INI14_L;
	INI23_H;
	INI24_L;
}
void right_up()// 右轮正转
{
	INI11_L;
	INI12_H;
	INI21_L;
	INI22_H;
}
void right_down()//右轮反转
{
	INI11_H;
	INI12_L;
	INI21_H;
	INI22_L;	
}
void left_stop()//左轮停止
{
	 INI13_H;
	 INI14_H;
	 INI23_H;
	 INI24_H;
}
void right_stop()//右轮停止
{
	 INI11_H;
	 INI12_H;
	 INI21_H;
	 INI22_H;
}
void up ()//向前
{
	left_up();
	right_up();	
}
void down()//向后
{
	left_down();
	right_down();
}

void  up_left()//向前左转
{	 	
	left_stop();
	right_up();	
}
void down_left()//向后左转
{
	left_stop();
	right_down();
}
void turn_left()// 原地向左
{
	left_down();
	right_up();	
}
void up_right()	//向前右转
{
	left_up();
	right_stop();	
}
void down_right() //向后右转
{
	left_down();
	right_stop();
}
void turn_right()  // 原地右转
{
	left_up();
	right_down();
}
void all_stop()	//停止
{
	left_stop();
	right_stop();

}
