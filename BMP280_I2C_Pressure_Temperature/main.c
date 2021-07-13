#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_i2c.h"
#include "driverlib/i2c.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
#include "utils/uartstdio.h"
#include <stdio.h>
#include <stdint.h>

// ATTENTION!!! We need to add existing uartstdio.c to our Source directory
// now, we use the uart library is in StellarisWare ready to use

uint32_t getPressure(int32_t tfine)
{
	unsigned long rdata;
	signed long adc_P;
	int32_t var1, var2;
  uint32_t p;
	short digP1, digP2, digP3, digP4, digP5, digP6, digP7, digP8, digP9;
	char sil[80];
    
  /////////////////// digP1 /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x8E); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	digP1 = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x8F); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	digP1 +=  rdata;
    //////////////////////////////////////////////////////////////////
    /////////////////// digP2 /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x90); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	digP2 = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x91); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	digP2 +=  rdata;
  //////////////////////////////////////////////////////////////////
	/////////////////// digP3 /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x92); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	digP3 = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x93); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	digP3 +=  rdata;
  //////////////////////////////////////////////////////////////////
  /////////////////// digP4 /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x94); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	digP4 = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x95); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	digP4 +=  rdata;
  //////////////////////////////////////////////////////////////////
	/////////////////// digP5 /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x96); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	digP5 = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x97); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	digP5 +=  rdata;
  //////////////////////////////////////////////////////////////////
	/////////////////// digP6 /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x98); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	digP6 = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x99); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	digP6 +=  rdata;
  //////////////////////////////////////////////////////////////////
	/////////////////// digP7 /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x9A); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	digP7 = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x9B); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	digP7 +=  rdata;
  //////////////////////////////////////////////////////////////////
	/////////////////// digP8 /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x9C); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	digP8 = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x9D); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	digP8 +=  rdata;
  //////////////////////////////////////////////////////////////////
	/////////////////// digP9 /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x9E); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	digP9 = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0x9F); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	digP9 +=  rdata;
  ///////////////////////////////////////////////////////////
	/////////////////// adc_P /////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0xFA); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	adc_P = 256*rdata;
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0xFB); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);

	adc_P +=  rdata;
	adc_P = adc_P <<4;
	///////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////
  var1 = ((int32_t)tfine>>1)-(int32_t)64000;
  var2 = ((var1>>2)*(var1>>2))*((int32_t)digP6);
  var2 = var2+((var1*((int32_t)digP5))<<1);
  var2 = (var2>>2)+(((int32_t)digP4)<<16);
  var1 = (((digP3*(((var1>>2)*(var1>>2))>>13))>>3)+((((int32_t)digP2)*var1)>>1))>>18;
  var1 = ((((32768+var1))*((int32_t)digP1))>>15);
  if(var1 == 0)
  {
      return 0;
  }
  p = (((uint32_t)(((int32_t)1048576)-adc_P)-(var2>>12)))*3125;
  if(p < 0x80000000)
  {
      p = (p<<1)/((uint32_t)var1);
  }
  else
  {
      p = (p/(uint32_t)var1)*2;
  }
  var1 = (((int32_t)digP9)*((int32_t)(((p>>3)*(p>>3))>>13)))>>12;
  var2 = (((int32_t)(p>>2)) * ((int32_t)digP8))>>13;
  p = (uint32_t)((int32_t)p+((var1+var2+digP7)>>4));
  return p;
}
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
  unsigned long rdata;
	
	signed long adc_T;
	unsigned short digT1;
	short digT2, digT3;
	double var1, var2;
	double temp_result;
	uint32_t press_result;
	
	int32_t tfine_temp;
	
	char line[80];
	
	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	
	initUART();
	
	UARTprintf("****************************************\n");
	UARTprintf("ayengec BMP280 I2C Communication Project\n");
	UARTprintf("****************************************\n");
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	
	GPIOPinConfigure(GPIO_PB2_I2C0SCL);
	GPIOPinConfigure(GPIO_PB3_I2C0SDA);
	
	GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);
	GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
	
	I2CMasterInitExpClk(I2C0_MASTER_BASE, SysCtlClockGet(), false); // true = fast mode = 400 kbps
	I2CMasterTimeoutSet(I2C0_MASTER_BASE,0XFF);
	
	///////
	SysCtlDelay(4000000);

	UARTprintf("Reading ID from sensor\n");
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0xD0); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));

	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	UARTprintf("CHIP ID is 0x%2x\n", rdata);
	
	SysCtlDelay(5000000);
	///////////////////////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0xF4); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_BURST_SEND_START);
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	I2CMasterDataPut(I2C0_MASTER_BASE,0x27); // read chip id register
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_BURST_SEND_FINISH);
	UARTprintf("Config Data is Written\n");
	/////////////////////
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
	I2CMasterDataPut(I2C0_MASTER_BASE,0xF4); // read chip id register
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	
	while(I2CMasterBusy(I2C0_MASTER_BASE));
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
	I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
	while(I2CMasterBusy(I2C0_MASTER_BASE));

	rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
	UARTprintf("Config read data 0x%2x\n", rdata);
	///////
	
	while(1)
    {
			
			SysCtlDelay(10000000);

			//////////// adc_T //////////////////
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
			I2CMasterDataPut(I2C0_MASTER_BASE,0xFA); // read chip id register
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
			
			while(I2CMasterBusy(I2C0_MASTER_BASE));
			
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE));

			rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
			//UARTprintf("MSB data is 0x%2x\n", rdata);		
			
			adc_T = rdata*256;
			///////////////////////////////////////
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
			I2CMasterDataPut(I2C0_MASTER_BASE,0xFB); // read chip id register
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
			
			//while(!(I2CMasterIntStatusEx(I2C0_MASTER_BASE,false) & I2C_MASTER_INT_DATA));
			while(I2CMasterBusy(I2C0_MASTER_BASE));
			
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE));

			rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
			//UARTprintf("LSB data is 0x%2x\n", rdata);
			adc_T +=  rdata;
			adc_T = adc_T <<4;
			
			//UARTprintf("ADC_T Value is %d\n", adc_T);
			
			/////////// dig_T1 ///////////
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
			I2CMasterDataPut(I2C0_MASTER_BASE,0x89); 
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
			
			while(I2CMasterBusy(I2C0_MASTER_BASE));
			
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE));

			rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
			//UARTprintf("T1 MSB is 0x%2x\n", rdata);	
			digT1 = rdata*256;
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
			I2CMasterDataPut(I2C0_MASTER_BASE,0x88); 
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
			
			while(I2CMasterBusy(I2C0_MASTER_BASE));
			
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE));

			rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
			//UARTprintf("T1 LSB is 0x%2x\n", rdata);		
			digT1 += rdata;
			///////////////////////////////////////
			
			/////////// dig_T2 ///////////
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
			I2CMasterDataPut(I2C0_MASTER_BASE,0x8B); // read chip id register
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
			
			while(I2CMasterBusy(I2C0_MASTER_BASE));
			
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE));

			rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
			//UARTprintf("T2 MSB  0x%2x\n", rdata);		
			digT2 = rdata*256;
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
			I2CMasterDataPut(I2C0_MASTER_BASE,0x8A); // read chip id register
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
			
			while(I2CMasterBusy(I2C0_MASTER_BASE));
			
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE));

			rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
			//UARTprintf("T2 LSB 0x%2x\n", rdata);
			digT2 +=  rdata;
			///////////////////////////////////////
			
			/////////// dig_T3 ///////////
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
			I2CMasterDataPut(I2C0_MASTER_BASE,0x8D); // read chip id register
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
			
			while(I2CMasterBusy(I2C0_MASTER_BASE));
			
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE));

			rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
			//UARTprintf("T3 MSB 0x%2x\n", rdata);	
			
			digT3 = rdata*256;

			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,false);
			I2CMasterDataPut(I2C0_MASTER_BASE,0x8C); // read chip id register
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_SEND);
			
			while(I2CMasterBusy(I2C0_MASTER_BASE));
			
			I2CMasterSlaveAddrSet(I2C0_MASTER_BASE,0x76,true);
			I2CMasterControl(I2C0_MASTER_BASE,I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE));

			rdata = I2CMasterDataGet(I2C0_MASTER_BASE);
			//UARTprintf("T3 LSB 0x%2x\n", rdata);	
			digT3 += rdata;
			
			///////////////////////////////////////
			
			UARTprintf("digT1= %i\n",digT1);
			UARTprintf("digT2= %i\n",digT2);
			UARTprintf("digT3= %i\n",digT3);
			
			
			var1 = ( (double)adc_T/16384.0 - (double)digT1/1024.0) * (double)digT2;

			var2 = (((double)adc_T/131072.0) - ((double)digT1/8192.0))*(((double)adc_T/131072.0) - ((double)digT1/8192.0))*(double)digT3;			
			
			temp_result = (var1 + var2)/5120;
			sprintf(line, "temp result= %g *C\n", temp_result);
			UARTprintf(line);
			
			tfine_temp =(int32_t)(var1+var2);
			press_result = getPressure(tfine_temp);
						
			sprintf(line, "Pressure result= %i Pa\n", press_result);
			UARTprintf(line);
			
			SysCtlDelay(8000000);
			
    }
}
