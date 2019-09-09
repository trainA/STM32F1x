#ifndef SYSTICK_DEF
#define SYSTICK_DEF
#include "stm32f10x.h"



extern uint16_t fac_us;
extern uint16_t fac_ms;

void SysTick_Init(uint8_t SYSCLK);
void delay_ms(uint32_t );
void delay_us(uint32_t  us);

#endif
