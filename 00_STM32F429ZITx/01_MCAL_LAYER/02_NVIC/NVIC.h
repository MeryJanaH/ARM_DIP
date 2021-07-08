/*************************************/
/********Author : Meryem ANNOUAR******/
/********Date : 28/05/21 *************/
/*************************************/
#include "STD_TYPES.h"

#ifndef _NVIC_H
#define _NVIC_H

//functions Declarations
void vNVIC_SetEnable(uint8 u8IntNumber);
void vNVIC_ClearEnable(uint8 u8IntNumber);

void vNVIC_SetPending(uint8 u8IntNumber);
void vNVIC_ClearPending(uint8 u8IntNumber);

uint8 u8NVIC_GetActiveFlag(uint8 u8IntNumber);

void vNVIC_SetPriority(uint8 u8IntNumber,uint8 u8GroupPriority, uint8 u8SubGroupPriority, uint8 GroupPriorityCFG);

#endif