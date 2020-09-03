#include "stm32f10x_tim.h"
#include "timer.h"
//PWMÊä³ö³õÊ¼»¯
//arr£º×Ô¶¯ÖØ×°Öµ
//psc£ºÊ±ÖÓÔ¤·ÖÆµÊı


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

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE); //Ê±ÖÓÊ¹ÄÜ
	
	//¶¨Ê±Æ÷TIM3³õÊ¼»¯
	TIM_TimeBaseStructure.TIM_Period = arr; //ÉèÖÃÔÚÏÂÒ»¸ö¸üĞÂÊÂ¼ş×°Èë»î¶¯µÄ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷ÖÜÆÚµÄÖµ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //ÉèÖÃÓÃÀ´×÷ÎªTIMxÊ±ÖÓÆµÂÊ³ıÊıµÄÔ¤·ÖÆµÖµ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ÉèÖÃÊ±ÖÓ·Ö¸î:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIMÏòÉÏ¼ÆÊıÄ£Ê½
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure); //¸ù¾İÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯TIMxµÄÊ±¼ä»ùÊıµ¥Î»
 
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE ); //Ê¹ÄÜÖ¸¶¨µÄTIM3ÖĞ¶Ï,ÔÊĞí¸üĞÂÖĞ¶Ï

	//ÖĞ¶ÏÓÅÏÈ¼¶NVICÉèÖÃ
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;  //TIM3ÖĞ¶Ï
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //ÏÈÕ¼ÓÅÏÈ¼¶0¼¶
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //´ÓÓÅÏÈ¼¶3¼¶
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQÍ¨µÀ±»Ê¹ÄÜ
	NVIC_Init(&NVIC_InitStructure);  //³õÊ¼»¯NVIC¼Ä´æÆ÷


	TIM_Cmd(TIM6, ENABLE);  //Ê¹ÄÜTIMxè
							 
}

void TIM7_Int_Init(u16 arr,u16 psc)
{	
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE); //Ê±ÖÓÊ¹ÄÜ//TIM4Ê±ÖÓÊ¹ÄÜ    
	
	//¶¨Ê±Æ÷TIM3³õÊ¼»¯
	TIM_TimeBaseStructure.TIM_Period = arr; //ÉèÖÃÔÚÏÂÒ»¸ö¸üĞÂÊÂ¼ş×°Èë»î¶¯µÄ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷ÖÜÆÚµÄÖµ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //ÉèÖÃÓÃÀ´×÷ÎªTIMxÊ±ÖÓÆµÂÊ³ıÊıµÄÔ¤·ÖÆµÖµ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ÉèÖÃÊ±ÖÓ·Ö¸î:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIMÏòÉÏ¼ÆÊıÄ£Ê½
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure); //¸ù¾İÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯TIMxµÄÊ±¼ä»ùÊıµ¥Î»
 
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE ); //Ê¹ÄÜÖ¸¶¨µÄTIM4ÖĞ¶Ï,ÔÊĞí¸üĞÂÖĞ¶Ï

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//ÇÀÕ¼ÓÅÏÈ¼¶3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//×ÓÓÅÏÈ¼¶3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQÍ¨µÀÊ¹ÄÜ
	NVIC_Init(&NVIC_InitStructure);	//¸ù¾İÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯VIC¼Ä´æÆ÷
	
	
}
void TIM7_Set(u8 sta)
{
	if(sta)
	{
       
		TIM_SetCounter(TIM7,0);//¼ÆÊıÆ÷Çå¿Õ
		TIM_Cmd(TIM7, ENABLE);  //Ê¹ÄÜTIMx	
	}else TIM_Cmd(TIM7, DISABLE);//¹Ø±Õ¶¨Ê±Æ÷4	   
}
