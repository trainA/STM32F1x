#include "exit.h"
#include "MySysTick.h"
#include "stm32f10x.h"
#include "sys.h"
#include "led.h"
#include "key.h"
/*
按键中断初始化
*/
void exit_key_init()
{
		NVIC_InitTypeDef NVIC_init;
		EXTI_InitTypeDef EXIT_init;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//开启AFIO时钟，设置IO口与中断线的映射关系
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
		NVIC_init.NVIC_IRQChannel = EXTI0_IRQn;
		NVIC_init.NVIC_IRQChannelPreemptionPriority = 2;
		NVIC_init.NVIC_IRQChannelSubPriority = 3;
		NVIC_init.NVIC_IRQChannelCmd = ENABLE;
	
		NVIC_Init(&NVIC_init);
		NVIC_init.NVIC_IRQChannel = EXTI2_IRQn;
		NVIC_init.NVIC_IRQChannelPreemptionPriority = 2;
		NVIC_init.NVIC_IRQChannelSubPriority = 2;
		NVIC_init.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_init);

		NVIC_Init(&NVIC_init);
		NVIC_init.NVIC_IRQChannel = EXTI3_IRQn;
		NVIC_init.NVIC_IRQChannelPreemptionPriority = 2;
		NVIC_init.NVIC_IRQChannelSubPriority = 1;
		NVIC_init.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_init);
		
		NVIC_Init(&NVIC_init);
		NVIC_init.NVIC_IRQChannel = EXTI4_IRQn;
		NVIC_init.NVIC_IRQChannelPreemptionPriority = 2;
		NVIC_init.NVIC_IRQChannelSubPriority = 0;
		NVIC_init.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_init);
		
		EXIT_init.EXTI_Line = EXTI_Line0;
		EXIT_init.EXTI_Mode = EXTI_Mode_Interrupt;
		EXIT_init.EXTI_LineCmd = ENABLE;
		EXIT_init.EXTI_Trigger = EXTI_Trigger_Rising;
		EXTI_Init(&EXIT_init);
		
		EXIT_init.EXTI_Line = EXTI_Line2|EXTI_Line3|EXTI_Line4;
		EXIT_init.EXTI_Mode = EXTI_Mode_Interrupt;
		EXIT_init.EXTI_LineCmd = ENABLE;
		EXIT_init.EXTI_Trigger = EXTI_Trigger_Falling;
		EXTI_Init(&EXIT_init);
}


void EXTI0_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line0))
		{
				delay_ms(10);
				if(K_UP == 1)
				{
						led_on(0);
				}
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
}


void EXTI2_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line2))
		{
				delay_ms(10);
				if(K_LEFT == 0)
				{
						led_on(0);
				}
		}
		EXTI_ClearITPendingBit(EXTI_Line2);
}

void EXTI3_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line3))
		{
				delay_ms(10);
				if(K_DOWN == 0)
				{
						led_on(0);
				}
		}
		EXTI_ClearITPendingBit(EXTI_Line3);
}

void EXTI4_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line4))
		{
				delay_ms(10);
				if(K_RIGHT == 0)
				{
						led_on(0);
				}
		}
		EXTI_ClearITPendingBit(EXTI_Line4);
}
