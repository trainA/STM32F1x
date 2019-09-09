#include "beep.h"

void beep_init()
{
		GPIO_InitTypeDef GPIO_init;
		RCC_APB2PeriphClockCmd(BEEP_PORT_RCC,ENABLE);
		GPIO_init.GPIO_Pin = BEEP_GPIO_PIN;
		GPIO_init.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(LED_PORT,&GPIO_init);
}
