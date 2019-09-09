#include "beep.h"

void beep_init()
{
		GPIO_InitTypeDef GPIO_init;
		RCC_APB2PeriphClockCmd(BEEP_PORT_RCC,ENABLE);
		GPIO_init.GPIO_Pin = BEEP_GPIO_PIN;
		GPIO_init.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(BEEP_PORT,&GPIO_init);
}
void beep_on()
{
	GPIO_SetBits(BEEP_PORT,BEEP_GPIO_PIN);
}
void beep_off()
{
		GPIO_ResetBits(BEEP_PORT,BEEP_GPIO_PIN);
}

