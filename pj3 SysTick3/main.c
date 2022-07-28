#include "main.h"

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

