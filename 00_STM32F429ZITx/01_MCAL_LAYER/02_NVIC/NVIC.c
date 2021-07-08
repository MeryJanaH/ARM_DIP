/*************************************/
/********Author : Meryem ANNOUAR******/
/********Date : 28/05/21 *************/
/*************************************/

#include "NVIC_Private.h"
#include "NVIC.h"

void vNVIC_SetEnable(uint8 u8IntNumber)
{
	if(u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1U << u8IntNumber);
	}
	else if((u8IntNumber >= 32) && (u8IntNumber <= 63))
	{
		u8IntNumber -= 32;
		NVIC_ISER1 = (1U << u8IntNumber);
	}
}

void vNVIC_ClearEnable(uint8 u8IntNumber)
{
	if(u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1U << u8IntNumber);
	}
	else if((u8IntNumber >= 32) && (u8IntNumber <= 63))
	{
		u8IntNumber -= 32;
		NVIC_ISER1 = (1U << u8IntNumber);
	}
}

void vNVIC_SetPending(uint8 u8IntNumber)
{
	if(u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1U << u8IntNumber);
	}
	else if((u8IntNumber >= 32) && (u8IntNumber <= 63))
	{
		u8IntNumber -= 32;
		NVIC_ISPR1 = (1U << u8IntNumber);
	}
}
void vNVIC_ClearPending(uint8 u8IntNumber)
{
	if(u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1U << u8IntNumber);
	}
	else if((u8IntNumber >= 32) && (u8IntNumber <= 63)) 
	{
		u8IntNumber -= 32;
		NVIC_ICPR1 = (1U << u8IntNumber);
	}
}

uint8 u8NVIC_GetActiveFlag(uint8 u8IntNumber)
{
	uint8 u8ActiveState = 0;
	
	if(u8IntNumber <= 31)
	{
		u8ActiveState = NVIC_IABR0 & (1U << u8IntNumber);
	}
	else if((u8IntNumber >= 32) && (u8IntNumber <= 63))
	{
		u8IntNumber -= 32;
		u8ActiveState = NVIC_IABR1 & (1U << u8IntNumber);
	}
	return u8ActiveState;
}

void vNVIC_SetPriority(uint8 u8IntNumber,uint8 u8GroupPriority, uint8 u8SubGroupPriority, uint8 GroupPriorityCFG)
{
	switch(GroupPriorityCFG)
	{
		/*we assign the 4 priority bits for group priority*/
		case GROUP_PRIORITY_CGF0:
			SCB_AIRCR = 0x05fA03000;
			NVIC_IPR[u8IntNumber] = (u8GroupPriority << 4U);
		break;
		/*we assign the 3 priority bits for group priority and 1 bit for SubG Priority*/
		case GROUP_PRIORITY_CGF1:
			SCB_AIRCR = 0x05fA04000;
			NVIC_IPR[u8IntNumber] = ((u8GroupPriority << 5U) | (u8SubGroupPriority << 4U));
		break;
		/*we assign the 2 priority bits for group priority and 2 bit for SubG Priority*/
		case GROUP_PRIORITY_CGF2:
			SCB_AIRCR = 0x05fA05000;
			NVIC_IPR[u8IntNumber] = ((u8GroupPriority << 6U) | (u8SubGroupPriority << 4U));
		break;
		/*we assign the 1 priority bits for group priority and 3 bit for SubG Priority*/
		case GROUP_PRIORITY_CGF3:
			SCB_AIRCR = 0x05fA06000;
			NVIC_IPR[u8IntNumber] = ((u8GroupPriority << 7U) | (u8SubGroupPriority << 4U));
		break;		
		/*we assign the 0 priority bits for group priority and 4 bit for SubG Priority*/
		case GROUP_PRIORITY_CGF4:
			SCB_AIRCR = 0x05fA07000;
			NVIC_IPR[u8IntNumber] = u8SubGroupPriority << 4U;
		break;	
		default: break;
	}
}
