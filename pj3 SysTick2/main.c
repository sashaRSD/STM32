#include "stm32f4xx.h"
#define	RED_ON()				GPIO_SetBits(GPIOD, GPIO_Pin_14)
#define	RED_OFF()				GPIO_ResetBits(GPIOD, GPIO_Pin_14)
#define	BLUE_ON()				GPIO_SetBits(GPIOD, GPIO_Pin_15)
#define	BLUE_OFF()			GPIO_ResetBits(GPIOD, GPIO_Pin_15)
#define	GREEN_ON()			GPIO_SetBits(GPIOD, GPIO_Pin_12)
#define	GREEN_OFF()			GPIO_ResetBits(GPIOD, GPIO_Pin_12)
#define	YELLOW_ON()			GPIO_SetBits(GPIOD, GPIO_Pin_13)
#define	YELLOW_OFF()		GPIO_ResetBits(GPIOD, GPIO_Pin_13)
#define	DELAY						100


uint16_t delay_count=0;

//----------------------------------------------
//
//----------------------------------------------
void SysTick_Handler(void)//1ms
{
	if (delay_count > 0)
	{
		delay_count--;
	}
}

//----------------------------------------------
//
//----------------------------------------------
void delay_ms(uint16_t delay_temp)
{
	delay_count = delay_temp;
	
	while(delay_count){}
}

//----------------------------------------------
//
//----------------------------------------------
void LEDs_ini(void)
{
	GPIO_InitTypeDef GPIO_Init_LED;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_Init_LED.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LED.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_Init_LED);
}

//----------------------------------------------
//
//----------------------------------------------
int main(void)
{
	LEDs_ini();
	SysTick_Config(SystemCoreClock/1000);//1 ms
	while(1)
	{
		RED_ON();
		YELLOW_OFF();
		delay_ms(DELAY);
		RED_OFF();
		BLUE_ON();
		delay_ms(DELAY);
		BLUE_OFF();
		GREEN_ON();
		delay_ms(DELAY);
		GREEN_OFF();
		YELLOW_ON();
		delay_ms(DELAY);
	}
}

