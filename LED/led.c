#include "led.h"

void led_init()
{
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(LED_PORT_RCC,ENABLE);//����ʱ������Ϊʹ�����
		GPIO_InitStructure.GPIO_Pin = LED_PIN_ALL;//�������ж˿�
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//����Ϊ�������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//���������СΪ50MHz
		
		GPIO_Init(LED_PORT,&GPIO_InitStructure);			//��ʼ��GPIOC
		GPIO_SetBits(LED_PORT,LED_PIN_ALL);				//��������Ϊ�ߵ�ƽ�Է���������
}
void led_off(uint16_t pin)
{
	GPIO_SetBits(LED_PORT,1<<pin);
}
void led_on(uint16_t pin)
{
	GPIO_ResetBits(LED_PORT,1<<pin);
}
