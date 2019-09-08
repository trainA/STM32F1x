#include "MySysTick.h"
/*
时钟操作四步
	1. 设置定时器时钟源
	2.设置定时器重载初始值
	3.清零当前计数器
	4.打开滴答计时器

*/
uint16_t fac_us;
uint16_t fac_ms;
void SysTick_Init(uint8_t SYSCLK)
{
		SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//选择时钟源
		fac_us = SYSCLK/8;																	//设置us用时
		fac_ms = (u16)fac_us*1000;													//设置ms用时
}
void delay_us(uint32_t  nus)
{
		uint32_t temp;
		SysTick->LOAD = nus*fac_us;				//设置倒计时值
		SysTick->VAL = 0x00;							//清空计数器
		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;	//开始倒数
		do
		{
			temp = SysTick->CTRL;						//读取当前计数值
		}while((temp&0x01)&&!(temp&(1<<16)));	//寄存器CTRL最后一位为1位1 表示计数开始了 第16位为1 的时候倒计时为0 了
		SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;	//关闭计数器
		SysTick->VAL = 0x00;//清空计数器
}