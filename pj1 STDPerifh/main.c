#include "stm32f4xx.h"

int main(void)
{
	uint32_t i;
	GPIO_InitTypeDef GPIO_Init_LED;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_Init_LED.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LED.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_Init_LED);
	
	while(1)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_12);					//green
		for (i=0;i<500000;i++){}
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
		for (i=0;i<500000;i++){}
		GPIO_SetBits(GPIOD, GPIO_Pin_13);					//orange
		for (i=0;i<500000;i++){}
		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
		for (i=0;i<500000;i++){}
		GPIO_SetBits(GPIOD, GPIO_Pin_14);					//red
		for (i=0;i<500000;i++){}
		GPIO_ResetBits(GPIOD, GPIO_Pin_14);
		for (i=0;i<500000;i++){}
		GPIO_SetBits(GPIOD, GPIO_Pin_15);					//blue
		for (i=0;i<500000;i++){}
		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
		for (i=0;i<2000000;i++){}
			
		GPIO_SetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		for (i=0;i<1000000;i++){}
		GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		for (i=0;i<1000000;i++){}
	}
}
