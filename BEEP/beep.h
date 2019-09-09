#ifndef _BEEP_H_DEF
#define _BEEP_H_DEF
#include "stm32f10x.h"                  // Device header

#define BEEP_PORT_RCC RCC_APB2Periph_GPIOB
#define BEEP_GPIO_PIN GPIO_Pin_5
#define LED_PORT GPIOB

void beep_init(void);


#endif
