#include "stm32f4xx.h"                  // Device header

int main(void)
{
uint32_t i;
 
RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;

GPIOD->MODER = 0x55000000;
GPIOD->OTYPER = 0;
GPIOD->OSPEEDR = 0;

while(1)
{
GPIOD->ODR = 0x8000; 					//blue
for(i=0;i<500000;i++){}
GPIOD->ODR = 0x4000;					//red 
for(i=0;i<500000;i++){}
GPIOD->ODR = 0x2000;					//orange
for(i=0;i<500000;i++){}
GPIOD->ODR = 0x1000;					//green
for(i=0;i<500000;i++){}
GPIOD->ODR = 0x0000;
for(i=0;i<1000000;i++){}
	
	GPIOD->ODR = 0xF000;
	for(i=0;i<2000000;i++){}
	GPIOD->ODR = 0x0000;
	for(i=0;i<2000000;i++){}
}
}
