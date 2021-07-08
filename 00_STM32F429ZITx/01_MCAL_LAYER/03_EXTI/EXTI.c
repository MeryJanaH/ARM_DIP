/*************************************/
/********Author : Meryem ANNOUAR******/
/********Date : 04/06/21 *************/
/*************************************/


#include "EXTI.h"
#include "EXTI_Private.h"

void vEXTI_NotMask(uint8 u8LineNumber)
{
	EXTI_IMR |= (1U << u8LineNumber);
}

void vEXTI_Mask(uint8 u8LineNumber)
{
	EXTI_IMR &=~ (1U << u8LineNumber);
}

void vEXTI_EventType(uint8 u8LineNumber, uint8 u8EventType)
{
	switch(u8EventType)
	{
		case RIZING_EVENT:
			EXTI_RTSR |= (1U << u8LineNumber);
		break;
		
		case FALLING_EVENT :
			EXTI_FTSR |= (1U << u8LineNumber);
		break;
		
		default: break;
	}
}

void vEXTI_SWTigger(uint8 u8LineNumber)
{
		EXTI_SWIER |= (1U << u8LineNumber);
}

void vEXTI_SetPort(uint8 u8LineNumber, uint8 u8PortID)
{
	if(u8LineNumber <= 3)
	{
		SYSCFG_EXTICR1 &=~ (0b1111 << u8LineNumber*4);
		SYSCFG_EXTICR1 |= (u8PortID << u8LineNumber*4);
	}
	else if(u8LineNumber <= 7)
	{
		u8LineNumber -= 4;
		SYSCFG_EXTICR2 &=~ (0b1111 << u8LineNumber*4);
		SYSCFG_EXTICR2 |= (u8PortID << u8LineNumber*4);
	}
	else if(u8LineNumber <= 11)
	{
		u8LineNumber -= 8;
	  SYSCFG_EXTICR3 &=~ (0b1111 << u8LineNumber*4);
		SYSCFG_EXTICR3 |= (u8PortID << u8LineNumber*4);
	}
	else if(u8LineNumber <= 15)
	{
		u8LineNumber -= 12;
		SYSCFG_EXTICR4 &=~ (0b1111 << u8LineNumber*4);
		SYSCFG_EXTICR4 |= (u8PortID << u8LineNumber*4);
	}
	else
	{
		
	}
}



