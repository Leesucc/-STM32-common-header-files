#include "stm32f10x_tim.h"
#include "timer.h"
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数


void TIM1_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //??? TIM1 ??
	//??? TIM1 ???
	TIM_TimeBaseStructure.TIM_Period = arr; //??????????????
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //?????????????
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //??????
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM ????
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0; //?????1??????????????????????????72mhz ???????
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //???? TIM1
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE ); //???????
	//????? NVIC ??
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn; //TIM1 ??
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //????? 1 ?
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //???? 3 ?
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ ?????
	NVIC_Init(&NVIC_InitStructure); //???? NVIC ???
	TIM_Cmd(TIM1, ENABLE); //??? TIM1

}



void TIM6_Int_Init(u16 arr,u16 psc)//SYSCLK
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE); //时钟使能
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

	//中断优先级NVIC设置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器


	TIM_Cmd(TIM6, ENABLE);  //使能TIMx�
							 
}

void TIM7_Int_Init(u16 arr,u16 psc)
{	
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE); //时钟使能//TIM4时钟使能    
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE ); //使能指定的TIM4中断,允许更新中断

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
	
}
void TIM7_Set(u8 sta)
{
	if(sta)
	{
       
		TIM_SetCounter(TIM7,0);//计数器清空
		TIM_Cmd(TIM7, ENABLE);  //使能TIMx	
	}else TIM_Cmd(TIM7, DISABLE);//关闭定时器4	   
}
