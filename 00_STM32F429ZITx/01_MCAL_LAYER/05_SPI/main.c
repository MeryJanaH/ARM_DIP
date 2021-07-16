
#include "SPI.h"
#include "SPI_private.h"
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/01_MCAL_LAYER/01_GPIO/GPIO.h"
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/01_MCAL_LAYER/00_RCC/RCC.h"
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"

int main(void)
{

	// RCC activate GPIO & SPI 
	//0 : GPIOA   &   1 : SPI1
	vRCC_EnPerClk(AHB1, 0);
	vRCC_EnPerClk(APB2, 1);
  
	//Config GPIO : MOSI On "Alternate Fct" Output "01"
	//GPIO0 & PIN0 & ALT5 0101
	vGPIO_PinSetMode(0, 0, 01);
	vGPIO_PinSetAltFn(0, 0, 0101);
	//Config GPIO : MISO On "Alternate Fct" INPUT "00"
	vGPIO_PinSetMode(0, 0, 00);
	vGPIO_PinSetAltFn(0, 0, 0101);
	//Config GPIO : /NSS On "Alternate Fct" Output
  vGPIO_PinSetMode(0, 0, 01);
	vGPIO_PinSetAltFn(0, 0, 0101);

	//NVIC initialization
	
	
	
 return 0;
}
