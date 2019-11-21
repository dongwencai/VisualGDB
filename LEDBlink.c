#include <chip.h>

const uint32_t ExtRateIn = 0;
const uint32_t OscRateIn = 12000000;
const uint32_t RTCOscRateIn = 32768;

#ifndef LPC_GPIO2
#define LPC_GPIO LPC_GPIO_PORT
#endif

int main()
{
	SystemCoreClockUpdate();

	SysTick_Config(SystemCoreClock / 1000);
		
	Chip_GPIO_Init(LPC_GPIO2);
	
	Chip_GPIO_SetPortDIROutput(LPC_GPIO2, 0, 1 << 6);
	
	MX_FREERTOS_Init();
	
	osKernelStart();

 
	return 0;
}
