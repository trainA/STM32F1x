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
	
	/*
		
		EXTI 0~15对应外部IO口的输入中断
		STM32使用映射的方式将每个IO映射到EXTI中断线上
		每个GPIO上的0 对应EXIT0
		依次对应
		从9-5是公用一个中断函数
		10-15公用一个函数
	*/
		NVIC_InitTypeDef NVIC_init;
		EXTI_InitTypeDef EXIT_init;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//开启AFIO时钟，设置IO口与中断线的映射关系
	//AFIO是外部中断配置寄存器
		
		//将GPIO映射到对应的中断线上
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
	
		//配置NVIC
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
		NVIC_init.NVIC_IRQChannel = EXTI4_IRQn;			//中断源
		NVIC_init.NVIC_IRQChannelPreemptionPriority = 2;//抢占式优先级
		NVIC_init.NVIC_IRQChannelSubPriority = 0;			//响应优先级
		NVIC_init.NVIC_IRQChannelCmd = ENABLE;			//开启使能
		NVIC_Init(&NVIC_init);
		
		EXIT_init.EXTI_Line = EXTI_Line0;
		EXIT_init.EXTI_Mode = EXTI_Mode_Interrupt;
		EXIT_init.EXTI_LineCmd = ENABLE;
		EXIT_init.EXTI_Trigger = EXTI_Trigger_Rising;		//上升沿
		EXTI_Init(&EXIT_init);
		
		EXIT_init.EXTI_Line = EXTI_Line2|EXTI_Line3|EXTI_Line4;
		EXIT_init.EXTI_Mode = EXTI_Mode_Interrupt;
		EXIT_init.EXTI_LineCmd = ENABLE;
		EXIT_init.EXTI_Trigger = EXTI_Trigger_Falling;	//下降沿
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
