#include "HwAb.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "interfaces.h"

void Clk_Init(void){
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
}

void PushButton_Init(void){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
	GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}

uint8_t PushButton_Read(void){
		uint32_t sw_delay = 300000;
		uint8_t input;
        input = (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) != 0) ? 1 : 0;
		if(input == 0){
			while(sw_delay--);
			input = (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) != 0) ? 1 : 0;
			return (input == 0) ? 0 : 1;
		}
		return 1;
}

void RGB_LED_Init(void){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, (GPIO_PIN_3 | GPIO_PIN_2 | GPIO_PIN_1));
}

void RGB_LED_Set(RGB_LED_Color color){
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_3 | GPIO_PIN_2 | GPIO_PIN_1), color);
}
