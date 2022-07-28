#include "stm32f4xx.h"
#include <stdio.h>
#include "flash.h"
#include "init_led.h"

int main(void)
{
	uint32_t data_flash;
	init_ledd();
	Flash_Write(ADDRESS, 0xFF334455);
	data_flash = Flash_Read(ADDRESS);
	printf("Данные = %X\n\r", data_flash );

		if (data_flash > 0x00000000)
		GPIO_SetBits(GPIOD, GPIO_Pin_12);					//green
		
		if (data_flash > 0x3FFFFFFF)
		GPIO_SetBits(GPIOD, GPIO_Pin_13);					//orange
		
		if (data_flash > 0xB7FFFFFF)
		GPIO_SetBits(GPIOD, GPIO_Pin_14);					//red
		
		if (data_flash > 0xBFFFFFFF)
		GPIO_SetBits(GPIOD, GPIO_Pin_15);					//blue	
		
	Flash_Write(ADDRESS, 0xFFFFFFFF);
	while(1)
	{data_flash++;}
}
