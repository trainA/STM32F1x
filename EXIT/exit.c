#include "exit.h"
#include "MySysTick.h"
#include "stm32f10x.h"
#include "sys.h"
#include "led.h"
#include "key.h"
/*
�����жϳ�ʼ��
*/
void exit_key_init()
{
	
	/*
		
		EXTI 0~15��Ӧ�ⲿIO�ڵ������ж�
		STM32ʹ��ӳ��ķ�ʽ��ÿ��IOӳ�䵽EXTI�ж�����
		ÿ��GPIO�ϵ�0 ��ӦEXIT0
		���ζ�Ӧ
		��9-5�ǹ���һ���жϺ���
		10-15����һ������
	*/
		NVIC_InitTypeDef NVIC_init;
		EXTI_InitTypeDef EXIT_init;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//����AFIOʱ�ӣ�����IO�����ж��ߵ�ӳ���ϵ
	//AFIO���ⲿ�ж����üĴ���
		
		//��GPIOӳ�䵽��Ӧ���ж�����
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
	
		//����NVIC
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
		NVIC_init.NVIC_IRQChannel = EXTI4_IRQn;			//�ж�Դ
		NVIC_init.NVIC_IRQChannelPreemptionPriority = 2;//��ռʽ���ȼ�
		NVIC_init.NVIC_IRQChannelSubPriority = 0;			//��Ӧ���ȼ�
		NVIC_init.NVIC_IRQChannelCmd = ENABLE;			//����ʹ��
		NVIC_Init(&NVIC_init);
		
		EXIT_init.EXTI_Line = EXTI_Line0;
		EXIT_init.EXTI_Mode = EXTI_Mode_Interrupt;
		EXIT_init.EXTI_LineCmd = ENABLE;
		EXIT_init.EXTI_Trigger = EXTI_Trigger_Rising;		//������
		EXTI_Init(&EXIT_init);
		
		EXIT_init.EXTI_Line = EXTI_Line2|EXTI_Line3|EXTI_Line4;
		EXIT_init.EXTI_Mode = EXTI_Mode_Interrupt;
		EXIT_init.EXTI_LineCmd = ENABLE;
		EXIT_init.EXTI_Trigger = EXTI_Trigger_Falling;	//�½���
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
