#include "led.h"

void led_init()
{
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(LED_PORT_RCC,ENABLE);//开启时钟设置为使能输出
		GPIO_InitStructure.GPIO_Pin = LED_PIN_ALL;//开启所有端口
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//设置为推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//设置输出大小为50MHz
		
		GPIO_Init(LED_PORT,&GPIO_InitStructure);			//初始化GPIOC
		GPIO_SetBits(LED_PORT,LED_PIN_ALL);				//首线先置为高电平以防出现问题
}
void led_off(uint16_t pin)
{
	GPIO_SetBits(LED_PORT,1<<pin);
}
void led_on(uint16_t pin)
{
	GPIO_ResetBits(LED_PORT,1<<pin);
}
