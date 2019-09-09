#include "key.h"
#include "sys.h"
#include "MySysTick.h"
#define K_UP 			GPIO_ReadInputDataBit(KEY_UP_PORT,KEY_UP_PIN)
#define K_DOWN 		GPIO_ReadInputDataBit(KEY_UP_PORT,KEY_DOWN_PIN)
#define K_LEFT 		GPIO_ReadInputDataBit(KEY_UP_PORT,KEY_LEFT_PIN)
#define K_RIGHT  	GPIO_ReadInputDataBit(KEY_UP_PORT,KEY_RIGHT_PIN)

void key_init(void)
{
		GPIO_InitTypeDef GPIO_init;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);
		GPIO_init.GPIO_Pin = KEY_UP_PIN;
		GPIO_init.GPIO_Mode = GPIO_Mode_IPD;//设置为下拉  这个按键外部接的是3.3v 所以内部默认为低电平
		GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(KEY_UP_PORT,&GPIO_init);
		GPIO_init.GPIO_Pin = KEY_DOWN_PIN|KEY_LEFT_PIN|KEY_RIGHT_PIN;
		GPIO_init.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(KEY_OTHER_PORT,&GPIO_init);
}

u8 key_scan()
{
		if(K_UP == 1||K_DOWN == 0||K_LEFT == 0||K_RIGHT == 0)
		{
				delay_ms(10);
				if(K_UP == 1)
				{
						return 1;
				}
				else if(K_DOWN == 0)
				{
						return 2;
					
				}
				else if(K_LEFT == 0)
				{
						return 3;
				}
				else if(K_RIGHT == 0)
				{
						return 4;
				}
				return 0;
		}
		return 0;
}

