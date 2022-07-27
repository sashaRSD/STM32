#include "stm32f4xx.h"
#include "DAC.h"


void DAC_ini(void)
{
	
	DAC_InitTypeDef DAC_struct;
	GPIO_InitTypeDef GPIO_Init_DAC;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_Init_DAC.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init_DAC.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_DAC.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_DAC.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_DAC.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_Init_DAC);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	DAC_struct.DAC_Trigger = DAC_Trigger_None;
	DAC_struct.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_struct.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_struct.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	DAC_Init(DAC_Channel_1, &DAC_struct);
	DAC_Cmd(DAC_Channel_1, ENABLE);
}
