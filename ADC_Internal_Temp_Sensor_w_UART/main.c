// ayengec LM4F120 Internal Temperature Sensor ADC with UART monitor
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
#include "utils/uartstdio.h"

// ATTENTION!!! We need to add existing uartstdio.c to our Source directory
// now, we use the uart library is in StellarisWare ready to use
void initUART(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	
	// We only need our pins to configure Alternate Func
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinConfigure(GPIO_PA0_U0RX);

	GPIOPinTypeUART(GPIO_PORTA_BASE, 
																	GPIO_PIN_0 | GPIO_PIN_1);
	
	UARTStdioInitExpClk(0, 9600);  // unsigned long ulPort, unsigned long ulBaud. Easy to set baudrate
}

int main(void)
{
  unsigned long ulADCbuff[4];
	
	volatile unsigned long avgTempVal;
	volatile unsigned long convADCval;
	
	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	
	initUART();
	
	UARTprintf("************************************\n");
	UARTprintf("ayengec ADC READ on LM4F120XL BOARD \n");
	UARTprintf("************************************\n");
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	SysCtlADCSpeedSet(SYSCTL_ADCSPEED_125KSPS);
	ADCSequenceDisable(ADC0_BASE, 1);
	
	// Configuring Sequences and steps to use ADC0 == PE7 or AIN0 for MCU
	ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
	
	
	ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_TS);
	ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_TS);
	ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_TS);
	ADCSequenceStepConfigure(ADC0_BASE, 1, 3, ADC_CTL_IE | ADC_CTL_END | ADC_CTL_TS);
	
	ADCSequenceEnable(ADC0_BASE, 1);
	
	while(1)
    {
			ADCIntClear(ADC0_BASE, 1);
			ADCProcessorTrigger(ADC0_BASE, 1);
			
			while(ADCIntStatus(ADC0_BASE, 1, false) == 0); // Wait ADC conversion complete interrupt flag
			
			
			ADCSequenceDataGet(ADC0_BASE, 1, ulADCbuff);
			
			avgTempVal = (ulADCbuff[0]+ulADCbuff[1]+ulADCbuff[2]+ulADCbuff[3])/4;
			/* LM4f120 MCU has internal Temperature Sensor 
			in datasheet, page:774
			TEMP = 147.5 - ((75 * (VREFP - VREFN) � ADCCODE) / 4096)
			*/
			convADCval = 147.5-((75*3.3*avgTempVal) / 4096);
			UARTprintf("Internal Temperature Sensor Value is = %d *C\n", convADCval);
			
			SysCtlDelay(8000000);
			
    }
}
