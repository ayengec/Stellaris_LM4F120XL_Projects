#include "inc/lm4f120h5qr.h"
#include "inc/hw_memmap.h"  		   // It has memory map macros
#include "inc/hw_types.h"				   // It has structural types
#include "inc/hw_ints.h"				   // It has hardware interrputs
#include "driverlib/sysctl.h"		   // System control API for Stellaris devices
#include "driverlib/gpio.h"			   // GPIO control API for Stellaris devices
#include "driverlib/interrupt.h"	 
#include "driverlib/timer.h"			  

int main(void)
{
	unsigned long timPeriod;

	//SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);  // System Clock settings in one line thanks to API
	SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);  // System Clock settings in one line thanks to API

	// to enable GPIO block's clock with API
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	
	// to set our LED's GPIO output type with API. It sets GPIOx_MODER register easily. GPIO registers are connected to APB bus on LM4F architecture
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
	
	// to enable TIMER0 block's clock with API, it is also on the APB bus
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_32_BIT_PER); 		// GPTMCFG Register' s GPTMCFG field: The function is controlled by bits 1:0 of GPTMTAMR and GPTMTBMR.
	
	timPeriod = (SysCtlClockGet()/ 2 )/ 2;
	TimerLoadSet(TIMER0_BASE, TIMER_A, timPeriod-1); 			// GPTM Timer A Interval Load (GPTMTAILR)

	IntMasterEnable();																		// Enable Global 
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);			// generate interrupt if it will be timeout
	IntEnable(INT_TIMER0A);																// TIMERA interrupts are enabled
	
	TimerEnable(TIMER0_BASE, TIMER_A);										// Start the count
	
  while(1)
  {
		
  }
}

// This Interrupt Handler Must be defined in startup_rvmdk.s as Extern !
void Timer0_Interrupt_Handler(void)
{
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);			// Clear the timer interrupts
	if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2))				// Read the current state of GPIO pin
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x00);
	}
	else
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x06);	
	}
}
