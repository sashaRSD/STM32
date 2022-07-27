#include "stm32f4xx.h"

uint16_t count;

void SysTick_Handler(void)
{
	if (count > 0)
	{
	}
	count--;
}

void delay_ms(uint16_t tmp)
{
	count = tmp;
	while(count){}
}

int main(void)
{
	GPIO_InitTypeDef GPIO_Init_LED;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	SysTick_Config(SystemCoreClock/1000); //SystemCoreClock/160 ?
	
	GPIO_Init_LED.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LED.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_Init_LED);
	
	while(1)
	{
			
		GPIO_SetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		delay_ms(5000);
		GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		delay_ms(5000);
	}
}
