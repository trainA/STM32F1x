#include "exit.h"

/*
�����жϳ�ʼ��
*/
void exit_key_init()
{
		NVIC_InitTypeDef NVIC_init;

	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//����AFIOʱ�ӣ�����IO�����ж��ߵ�ӳ���ϵ
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
		
}
