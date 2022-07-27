#include "stm32f4xx.h"

int main(void)
{
	uint32_t Led_Num;
	uint32_t i;
	GPIO_InitTypeDef GPIO_Init_LED;
	GPIO_InitTypeDef GPIO_Init_Buttom;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_Init_LED.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LED.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_Init_LED);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_Init_Buttom.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init_Buttom.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init_Buttom.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_Buttom.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Buttom.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_Init_Buttom);
	
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
		{
		for (i=0;i<700000;i++){}
		Led_Num++;
		}
		
			
		if(Led_Num == 1 || Led_Num == 9 || Led_Num == 5)
		{
		GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		GPIO_SetBits(GPIOD, GPIO_Pin_12);					//green
		}

		if(Led_Num == 2 || Led_Num == 8)
		{
		GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		GPIO_SetBits(GPIOD, GPIO_Pin_13);					//orange
		}
		
		if(Led_Num == 3 || Led_Num == 7)
		{
		GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		GPIO_SetBits(GPIOD, GPIO_Pin_14);					//red
		}
		
		if(Led_Num == 4 || Led_Num == 6)
		{
		GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		GPIO_SetBits(GPIOD, GPIO_Pin_15);					//blue
		}
		
		if(Led_Num >9)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
			for (i=0;i<500000;i++){}
			GPIO_SetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
			Led_Num = 0;
		}
		
	}
}
