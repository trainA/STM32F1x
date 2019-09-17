#include "stm32f10x.h"
#include "led.h"
#include "MySysTick.h"
#include "beep.h"
#include "exit.h"
#include "exti_tim.h"
#include "PWM_LED.h"
#include "usart.h"
/*
��һ���������� ��Ƶ��Ƶ
�ڶ����������� ��Ƶ
*/
void RCC_HSE_Config(u32 div, u32 pllm) //�Զ���ϵͳʱ�䣨�����޸�ʱ�ӣ�
{
    RCC_DeInit(); //������RCC�Ĵ�������Ϊȱʡֵ
    RCC_HSEConfig(RCC_HSE_ON);//�����ⲿ���پ���HSE��
    if(RCC_WaitForHSEStartUp() == SUCCESS) //�ȴ�HSE����
    {
        RCC_HCLKConfig(RCC_SYSCLK_Div1);//����AHBʱ�ӣ�HCLK��
        RCC_PCLK1Config(RCC_HCLK_Div2);//���õ���AHBʱ�ӣ�PCLK1��
        RCC_PCLK2Config(RCC_HCLK_Div1);//���ø���AHBʱ�ӣ�PCLK2��
        RCC_PLLConfig(div, pllm); //����PLLʱ��Դ����Ƶϵ��
        RCC_PLLCmd(ENABLE); //ʹ�ܻ���ʧ��PLL
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); //���ָ����RCC��־λ�������,PLL����
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//����ϵͳʱ�ӣ�SYSCLK��
        while(RCC_GetSYSCLKSource() != 0x08); //��������ϵͳʱ�ӵ�ʱ��Դ,0x08��PLL��Ϊϵͳʱ��
    }
}

int main(void)
{

    u16 i;
    u8 fx;
    //RCC_HSE_Config(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
   //exit_key_init();
   // TIM4_init(1000, 36000 - 1); //500ms�ж�һ��
    SysTick_Init(72);
    led_init();
    //	beep_init();
    //	beep = 1;
    TIM3_CH1_PWM_Init(500, 72 - 1);
		USART1_Init(9600);
    while(1)
    {

        if(fx == 0)
        {
            i++;
            if(i == 300)
            {
                fx = 1;
            }
        }
        else
        {
            i--;
            if(i == 0)
            {
                fx = 0;
            }
        }
        TIM_SetCompare1(TIM3, i); //iֵ������ȡ499����ΪARR���ֵ��499.
        delay_ms(10);
    }
//	{
//		delay_ms(1000);
//		led_on(j);
//		delay_ms(1000);
//		led_off(j);
//		++j;
//		j%=8;

//	}
}

