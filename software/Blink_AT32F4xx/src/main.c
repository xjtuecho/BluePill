#include <string.h>
#include "HAL.h"
#include "main.h"

volatile int32_t sysTickTimer = 0;

int main(void)
{
	RCU_Config();
	GPIO_Config();
	NVIC_Config();

	// Setup SysTick Timer for 1 msec interrupts.
	if (SysTick_Config(SystemCoreClock / 1000))
	{
		while(1);
	}

	while(1)
	{
		LED_ON();
		Delay(100);
		LED_OFF();
		Delay(100);
	}
}

//  delays number of tick Systicks (happens every 1 ms)
void Delay(uint32_t dlyTicks)
{
	uint32_t curTicks;

	curTicks = sysTickTimer;
	while ((sysTickTimer - curTicks) < dlyTicks)
	{
		__NOP();
	}
}

