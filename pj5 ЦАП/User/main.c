#include "stm32f4xx.h"
#include "DAC.h"


int main(void)
{
	DAC_ini();
	
	DAC_SetChannel1Data(DAC_Align_12b_R, (uint16_t)(1.83*4095/3));
	while(1)
	{}
}
