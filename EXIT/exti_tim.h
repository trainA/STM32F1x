#ifndef _EXTI_TIM__
#define _EXIT_TIM__
/*
	定时器定时时间计算公式
	tout = ((per)*(psc+1))/Tclk;
	per 自动装载值
	psc分配系数
	Tclk APB总线速度（一般是72M）
*/
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
void TIM4_init(u16 pre,u16 psc);


#endif

