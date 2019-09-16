#include  "exti_tim.h"
#include "led.h"


void TIM4_init(u16 pre,u16 psc)
{
	
		NVIC_InitTypeDef NVIC_init;
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);//打开时钟
		TIM_TimeBaseInitTypeDef TIM4_TimBaseInit;
		TIM4_TimBaseInit.TIM_Period = pre;
		TIM4_TimBaseInit.TIM_Prescaler = psc;
		TIM4_TimBaseInit.TIM_ClockDivision = TIM_CKD_DIV1;//不分频
		TIM4_TimBaseInit.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
		TIM_TimeBaseInit(TIM4,&TIM4_TimBaseInit);
	
		TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);//清除中断标志位
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
		NVIC_init.NVIC_IRQChannel = TIM4_IRQn;
		NVIC_init.NVIC_IRQChannelPreemptionPriority = 2;
		NVIC_init.NVIC_IRQChannelSubPriority = 3;
		NVIC_init.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_init);
		TIM_Cmd(TIM4,ENABLE);
}	
void TIM4_IRQHandler()
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update))
	{
		led1 = !led1;
		
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
}

