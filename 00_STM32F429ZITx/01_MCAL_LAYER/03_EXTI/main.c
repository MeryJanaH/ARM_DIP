
#include "GPIO_Priv.h"
#include "GPIO.h"
#include "RCC.h"
#include "NVIC.h"
#include "EXTI.h"

volatile uint8 u8GlobalFlag = 0;

int main(void)
{
	//RCC Enable to port G
	RCC_AHB1ENR |= (1U<<6); 
	
	//Set Mode of PIN13 & PIN14 to output mode	
	vGPIO_PinSetMode(GPIOG,PIN13,GPIO_OUTPUT_MODE);	
	vGPIO_PinSetMode(GPIOG,PIN14,GPIO_OUTPUT_MODE);	
	
	//Set OUTPUT Type of PIN13 & PIN14 to PushPull
	vGPIO_PinSetOutType(GPIOG,PIN13,GPIO_OUTPUT_PUSHPULL);
	vGPIO_PinSetOutType(GPIOG,PIN14,GPIO_OUTPUT_PUSHPULL);
	
	//Set OUTPUT Speed of PIN13 & PIN14 to Low
	vGPIO_PinSetOutSpeed(GPIOG,PIN13,GPIO_OUTPUT_LSPEED);
	vGPIO_PinSetOutSpeed(GPIOG,PIN14,GPIO_OUTPUT_LSPEED);
	
	
	/* Enable INT from NVIC and set pending flag using NVIC */
	/* Set enable EXTI0 */
	vNVIC_SetEnable(6);
	vNVIC_SetPending(6);
	
	/* Enable INT from NVIC and enable INT from EXTI pendig flag should be set when we press on the button */
	/* Set enable EXTI0 / Mthd 2 */

	
	while(1)
	{
		if(u8GlobalFlag == 1)
		{
			vGPIO_PinWriteData(GPIOG,PIN13,1);
			vGPIO_PinWriteData(GPIOG,PIN14,1);
			for(int i=0; i<500000; i++);
			vGPIO_PinWriteData(GPIOG,PIN13,0);
			vGPIO_PinWriteData(GPIOG,PIN14,0);
			for(int i=0; i<500000; i++);
			u8GlobalFlag = 0;
		}
	}
	
}

void EXTI0_IRQHandler(void)
{
	u8GlobalFlag = 1;
}