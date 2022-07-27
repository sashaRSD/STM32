#include "stm32f4xx.h"
#include "timerr.h"

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
	}
}


void timer_ini(void)
{
	
	TIM_TimeBaseInitTypeDef timer_struct;
	NVIC_InitTypeDef ContrPrer_struct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	timer_struct.TIM_Prescaler = 20000-1;
	timer_struct.TIM_CounterMode = TIM_CounterMode_Up;
	timer_struct.TIM_Period = 5000;
	timer_struct.TIM_ClockDivision = TIM_CKD_DIV1;
	timer_struct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM2, &timer_struct);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	ContrPrer_struct.NVIC_IRQChannel = TIM2_IRQn;
	ContrPrer_struct.NVIC_IRQChannelPreemptionPriority = 0;
	ContrPrer_struct.NVIC_IRQChannelSubPriority = 0;
	ContrPrer_struct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&ContrPrer_struct);
	
	TIM_Cmd(TIM2, ENABLE);
}
