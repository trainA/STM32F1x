#include "stm32f10x.h"
#include "led.h"
#include "MySysTick.h"
#include "beep.h"
#include "exit.h"
#include "exti_tim.h"
#include "PWM_LED.h"
#include "usart.h"
#include <stdio.h>
/*
第一个参数设置 主频分频
第二个参数设置 倍频
*/
void RCC_HSE_Config(u32 div, u32 pllm) //自定义系统时间（可以修改时钟）
{
    RCC_DeInit(); //将外设RCC寄存器重设为缺省值
    RCC_HSEConfig(RCC_HSE_ON);//设置外部高速晶振（HSE）
    if(RCC_WaitForHSEStartUp() == SUCCESS) //等待HSE起振
    {
        RCC_HCLKConfig(RCC_SYSCLK_Div1);//设置AHB时钟（HCLK）
        RCC_PCLK1Config(RCC_HCLK_Div2);//设置低速AHB时钟（PCLK1）
        RCC_PCLK2Config(RCC_HCLK_Div1);//设置高速AHB时钟（PCLK2）
        RCC_PLLConfig(div, pllm); //设置PLL时钟源及倍频系数
        RCC_PLLCmd(ENABLE); //使能或者失能PLL
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); //检查指定的RCC标志位设置与否,PLL就绪
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//设置系统时钟（SYSCLK）
        while(RCC_GetSYSCLKSource() != 0x08); //返回用作系统时钟的时钟源,0x08：PLL作为系统时钟
    }
}
/**
 * 重定向printf
*/
int fputc(int ch ,FILE *p)
{
    USART_SendData(USART1,(u8)ch);
    while (USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
    return ch;
}
int main(void)
{

    u16 i;
    u8 fx;
    //RCC_HSE_Config(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
   //exit_key_init();
   // TIM4_init(1000, 36000 - 1); //500ms中断一次
    SysTick_Init(72);
    led_init();
    //	beep_init();
    //	beep = 1;
    TIM3_CH1_PWM_Init(500, 72 - 1);
		USART1_Init(9600);

    printf("start\n");
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
        TIM_SetCompare1(TIM3, i); //i值最大可以取499，因为ARR最大值是499.
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

