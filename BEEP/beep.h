#ifndef _BEEP_H_DEF
#define _BEEP_H_DEF
#include "stm32f10x.h"                  // Device header
#include <sys.h>
#define BEEP_PORT_RCC RCC_APB2Periph_GPIOB
#define BEEP_GPIO_PIN GPIO_Pin_5
#define BEEP_PORT GPIOB

#define beep PBout(5)

void beep_init(void);
void beep_on(void);
void beep_off(void);

#endif
