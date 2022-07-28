#include "stm32f4xx.h"
#include "init_led.h"
#include "timerr.h"


int main(void)
{
	init_ledd();
	timer_ini();
	while(1)
	{}
}
