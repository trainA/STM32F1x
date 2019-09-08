#ifndef LED_H
#define LED_H
#include "stm32f10x.h"
#define LED_PORT_RCC RCC_APB2Periph_GPIOC
#define LED_PIN_ALL (GPIO_Pin_All)
#define LED_PORT GPIOC

void led_init(void);
void led_off(uint16_t pin);
void led_on(uint16_t pin);

#endif
