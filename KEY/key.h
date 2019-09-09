#ifndef _KEY_H_
#define _KEY_H_

#include "stm32f10x.h"                  // Device header

#define KEY_UP_PIN GPIO_Pin_0
#define KEY_UP_PORT GPIOA

#define KEY_LEFT_PIN GPIO_Pin_2
#define KEY_DOWN_PIN GPIO_Pin_3
#define KEY_RIGHT_PIN GPIO_Pin_4
#define KEY_OTHER_PORT GPIOE


void key_init(void);
u8 key_scan(void);
#endif
