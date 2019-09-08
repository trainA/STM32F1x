#include "MySysTick.h"
/*
ʱ�Ӳ����Ĳ�
	1. ���ö�ʱ��ʱ��Դ
	2.���ö�ʱ�����س�ʼֵ
	3.���㵱ǰ������
	4.�򿪵δ��ʱ��

*/
uint16_t fac_us;
uint16_t fac_ms;
void SysTick_Init(uint8_t SYSCLK)
{
		SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//ѡ��ʱ��Դ
		fac_us = SYSCLK/8;																	//����us��ʱ
		fac_ms = (u16)fac_us*1000;													//����ms��ʱ
}
void delay_ms(uint32_t  mus)
{
		uint32_t temp;
		SysTick->LOAD = mus*fac_ms;				//���õ���ʱֵLOAD��һ��24λ������ܳ���
		/*
			���㷽��ΪLOAD ���ֵΪ2^24
			fac_usΪ9000
			LOAD���Ը�ֵ�����ֵΪ2^24/9000 
		*/
		SysTick->VAL = 0x00;							//��ռ�����
		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;	//��ʼ����
		do
		{
			temp = SysTick->CTRL;						//��ȡ��ǰ����ֵ
		}while((temp&0x01)&&!(temp&(1<<16)));	//�Ĵ���CTRL���һλΪ1λ1 ��ʾ������ʼ�� ��16λΪ1 ��ʱ�򵹼�ʱΪ0 ��
		SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;	//�رռ�����
		SysTick->VAL = 0x00;//��ռ�����
}
