#include "stm32f429xx.h"

#include "GPIO_Priv.h"
#include "GPIO.h"
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/01_MCAL_LAYER/00_RCC/RCC.h"

#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"

int main(void)
{
	//RCC Enable to port G
	vRCC_EnPerClk(AHB1 , 6U);
	//== RCC_AHB1ENR |= (1U<<6); 
	
	//Set Mode of PIN13 & PIN14 to output mode	
	vGPIO_PinSetMode(GPIOG,PIN13,GPIO_OUTPUT_MODE);	
	vGPIO_PinSetMode(GPIOG,PIN14,GPIO_OUTPUT_MODE);	
	
	//Set OUTPUT Type of PIN13 & PIN14 to PushPull
	vGPIO_PinSetOutType(GPIOG,PIN13,GPIO_OUTPUT_PUSHPULL);
	vGPIO_PinSetOutType(GPIOG,PIN14,GPIO_OUTPUT_PUSHPULL);
	
	//Set OUTPUT Speed of PIN13 & PIN14 to Low
	vGPIO_PinSetOutSpeed(GPIOG,PIN13,GPIO_OUTPUT_LSPEED);
	vGPIO_PinSetOutSpeed(GPIOG,PIN14,GPIO_OUTPUT_LSPEED);
	
	volatile uint32 Local_u32Count=0;
		
	while(1)
	{
		vGPIO_PinWriteData(GPIOG,PIN13,1);
		vGPIO_PinWriteData(GPIOG,PIN14,1);
		for(Local_u32Count=0; Local_u32Count<500000; Local_u32Count++);
		vGPIO_PinWriteData(GPIOG,PIN13,0);
		vGPIO_PinWriteData(GPIOG,PIN14,0);
		for(Local_u32Count=0; Local_u32Count<500000; Local_u32Count++);
	}
	
	
}