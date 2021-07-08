/*************************************/
/********Author : Meryem ANNOUAR******/
/********Date : 04/06/21 *************/
/*************************************/

#ifndef _EXTI_H
#define _EXTI_H

#include "STD_TYPES.h"


void vEXTI_NotMask(uint8 u8LineNumber);
void vEXTI_Mask(uint8 u8LineNumber);
void vEXTI_EventType(uint8 u8LineNumber, uint8 u8EventType);
void vEXTI_SWTigger(uint8 u8LineNumber);
void vEXTI_SetPort(uint8 u8LineNumber, uint8 u8PortID);

#define RIZING_EVENT   0
#define FALLING_EVENT  1
	
#endif