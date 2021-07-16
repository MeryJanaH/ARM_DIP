
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"
#include "GPIO_Priv.h"
#include "GPIO.h"

void vGPIO_PinSetMode(uint8 Port_Name, uint8 Pin_Number, uint8 Mode)
{
	switch(Port_Name)
	{
		case GPIOA: GPIOA_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOB: GPIOB_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOC: GPIOC_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOD: GPIOD_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOE: GPIOE_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOF: GPIOF_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOG: GPIOG_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOH: GPIOH_MODER |= (Mode << (2*Pin_Number)); break;
		default: break;
	}
}

void vGPIO_PinSetOutType(uint8 Port_Name, uint8 Pin_Number, uint8 Output_Type)
{
	switch(Port_Name)
	{
		case GPIOA: GPIOA_MODER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOB: GPIOB_MODER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOC: GPIOC_MODER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOD: GPIOD_MODER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOE: GPIOE_MODER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOF: GPIOF_MODER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOG: GPIOG_MODER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOH: GPIOH_MODER |= (Output_Type << (2*Pin_Number)); break;
		default: break;
	}
}

void vGPIO_PinSetOutSpeed(uint8 Port_Name, uint8 Pin_Number, uint8 Speed)
{
		switch(Port_Name)
		{
			case GPIOA: GPIOA_OSPEEDR |= (Speed << (2*Pin_Number)); break;
			case GPIOB: GPIOB_OSPEEDR |= (Speed << (2*Pin_Number)); break;
			case GPIOC: GPIOC_OSPEEDR |= (Speed << (2*Pin_Number)); break;
			case GPIOD: GPIOD_OSPEEDR |= (Speed << (2*Pin_Number)); break;
			case GPIOE: GPIOE_OSPEEDR |= (Speed << (2*Pin_Number)); break;
			case GPIOF: GPIOF_OSPEEDR |= (Speed << (2*Pin_Number)); break;
			case GPIOG: GPIOG_OSPEEDR |= (Speed << (2*Pin_Number)); break;
			case GPIOH: GPIOH_OSPEEDR |= (Speed << (2*Pin_Number)); break;
			default: break;
		}
}

void vGPIO_PinSetPull_UP_DOWN(uint8 Port_Name, uint8 Pin_Number, uint8 Pull_Type)
{
		switch(Port_Name)
		{
			case GPIOA: GPIOA_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
			case GPIOB: GPIOB_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
			case GPIOC: GPIOC_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
			case GPIOD: GPIOD_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
			case GPIOE: GPIOE_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
			case GPIOF: GPIOF_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
			case GPIOG: GPIOG_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
			case GPIOH: GPIOH_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
			default: break;
		}
}

uint8 u8GPIO_PinReadData(uint8 Port_Name, uint8 Pin_Number)
{
	uint8 Read_Value = 0;
		switch(Port_Name)
		{
			case GPIOA: Read_Value = GPIOA_IDR & (1U << (Pin_Number)); break;
			case GPIOB: Read_Value = GPIOB_IDR & (1U << (Pin_Number)); break;
			case GPIOC: Read_Value = GPIOC_IDR & (1U << (Pin_Number)); break;
			case GPIOD: Read_Value = GPIOD_IDR & (1U << (Pin_Number)); break;
			case GPIOE: Read_Value = GPIOE_IDR & (1U << (Pin_Number)); break;
			case GPIOF: Read_Value = GPIOF_IDR & (1U << (Pin_Number)); break;
			case GPIOG: Read_Value = GPIOG_IDR & (1U << (Pin_Number)); break;
			case GPIOH: Read_Value = GPIOH_IDR & (1U << (Pin_Number)); break;
			default: break;
		}
	return Read_Value;
}

void vGPIO_PinWriteData(uint8 Port_Name, uint8 Pin_Number, uint8 Value)
{
	if (Value == 1)
	{
		switch(Port_Name)
		{
			case GPIOA:  GPIOA_ODR |= (1U << Pin_Number)	; break;
			case GPIOB:  GPIOB_ODR |= (1U << Pin_Number)	; break;
			case GPIOC:  GPIOC_ODR |= (1U << Pin_Number)	; break;
			case GPIOD:  GPIOD_ODR |= (1U << Pin_Number)	; break;
			case GPIOE:  GPIOE_ODR |= (1U << Pin_Number)	; break;
			case GPIOF:  GPIOF_ODR |= (1U << Pin_Number)	; break;
			case GPIOG:  GPIOG_ODR |= (1U << Pin_Number)	; break;
			case GPIOH:  GPIOH_ODR |= (1U << Pin_Number)	; break;
			default: break;
		}
	}
	else
	{
		switch(Port_Name)
		{
			case GPIOA:  GPIOA_ODR &=~ (1U << Pin_Number)	; break;
			case GPIOB:  GPIOB_ODR &=~ (1U << Pin_Number)	; break;
			case GPIOC:  GPIOC_ODR &=~ (1U << Pin_Number)	; break;
			case GPIOD:  GPIOD_ODR &=~ (1U << Pin_Number)	; break;
			case GPIOE:  GPIOE_ODR &=~ (1U << Pin_Number)	; break;
			case GPIOF:  GPIOF_ODR &=~ (1U << Pin_Number)	; break;
			case GPIOG:  GPIOG_ODR &=~ (1U << Pin_Number)	; break;
			case GPIOH:  GPIOH_ODR &=~ (1U << Pin_Number)	; break;
			default: break;
		}	
	}
}
void vGPIO_PinLock(uint8 Port_Name, uint8 Pin_Number)
{
		switch(Port_Name)
		{
			case GPIOA:
				GPIOA_LCKR |= (1U << Pin_Number); 
				GPIOA_LCKR |= (1U << LCKK);
				while(!(GPIOA_LCKR & (1U << LCKK)));
			break;
			case GPIOB: 
				GPIOB_LCKR |= (1U << Pin_Number); 
				GPIOB_LCKR |= (1U << LCKK);
				while(!(GPIOB_LCKR & (1U << LCKK)));
			break;
			case GPIOC: 
				GPIOC_LCKR |= (1U << Pin_Number); 
				GPIOC_LCKR |= (1U << LCKK);
				while(!(GPIOC_LCKR & (1U << LCKK)));
			break;
			case GPIOD: 
				GPIOD_LCKR |= (1U << Pin_Number); 
				GPIOD_LCKR |= (1U << LCKK);
				while(!(GPIOD_LCKR & (1U << LCKK)));
			break;
			case GPIOE: 
				GPIOE_LCKR |= (1U << Pin_Number); 
				GPIOE_LCKR |= (1U << LCKK);
				while(!(GPIOE_LCKR & (1U << LCKK)));
			break;
			case GPIOF: 
				GPIOF_LCKR |= (1U << Pin_Number); 
				GPIOF_LCKR |= (1U << LCKK);
				while(!(GPIOF_LCKR & (1U << LCKK)));
			break;
			case GPIOG: 
				GPIOG_LCKR |= (1U << Pin_Number); 
				GPIOG_LCKR |= (1U << LCKK);
				while(!(GPIOG_LCKR & (1U << LCKK)));
			break;
			case GPIOH: 
				GPIOH_LCKR |= (1U << Pin_Number); break;
				GPIOH_LCKR |= (1U << LCKK);
				while(!(GPIOH_LCKR & (1U << LCKK)));
			default: break;
		}
}
void vGPIO_PinSetAltFn(uint8 Port_Name, uint8 Pin_Number, uint8 Alt_Value)
{
	/*from pin0 to 7*/ 
	if(Pin_Number <= 7)
	{
		switch(Port_Name)
		{ 
			case GPIOA:  GPIOA_AFRL |= (Alt_Value << (4*Pin_Number))	; break;
			case GPIOB:  GPIOB_AFRL |= (Alt_Value << (4*Pin_Number))	; break;
			case GPIOC:  GPIOC_AFRL |= (Alt_Value << (4*Pin_Number))	; break;
			case GPIOD:  GPIOD_AFRL |= (Alt_Value << (4*Pin_Number))	; break;
			case GPIOE:  GPIOE_AFRL |= (Alt_Value << (4*Pin_Number))	; break;
			case GPIOF:  GPIOF_AFRL |= (Alt_Value << (4*Pin_Number))	; break;
			case GPIOG:  GPIOG_AFRL |= (Alt_Value << (4*Pin_Number))	; break;
			case GPIOH:  GPIOH_AFRL |= (Alt_Value << (4*Pin_Number))	; break;
			default: break;            
		}                            
	}                              
	/*from pin 8 to 15*/           
	else                           
	{                              
		switch(Port_Name)            
		{                            
			case GPIOA:  GPIOA_AFRH |= (Alt_Value << (4*Pin_Number % 8))	; break;
			case GPIOB:  GPIOB_AFRH |= (Alt_Value << (4*Pin_Number % 8))	; break;
			case GPIOC:  GPIOC_AFRH |= (Alt_Value << (4*Pin_Number % 8))	; break;
			case GPIOD:  GPIOD_AFRH |= (Alt_Value << (4*Pin_Number % 8))	; break;
			case GPIOE:  GPIOE_AFRH |= (Alt_Value << (4*Pin_Number % 8))	; break;
			case GPIOF:  GPIOF_AFRH |= (Alt_Value << (4*Pin_Number % 8))	; break;
			case GPIOG:  GPIOG_AFRH |= (Alt_Value << (4*Pin_Number % 8))	; break;
			case GPIOH:  GPIOH_AFRH |= (Alt_Value << (4*Pin_Number % 8))	; break;
			default: break;           
		}
	}
}

