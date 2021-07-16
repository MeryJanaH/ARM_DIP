/*************************************/
/********Author : Meryem ANNOUAR******/
/********Date : 04/06/21 *************/
/*************************************/

#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

#define EXTI_BASE_ADDRESS   0x40013C00
#define SYSCFG_BASE_ADDRESS 0x40013800

#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"

#define EXTI_IMR 	  			(*((volatile uint32*)(EXTI_BASE_ADDRESS + 0x00)))
#define EXTI_RTSR 				(*((volatile uint32*)(EXTI_BASE_ADDRESS + 0x08)))
#define EXTI_FTSR 				(*((volatile uint32*)(EXTI_BASE_ADDRESS + 0x0C)))
#define EXTI_SWIER 				(*((volatile uint32*)(EXTI_BASE_ADDRESS + 0x10)))
#define EXTI_PR 	  			(*((volatile uint32*)(EXTI_BASE_ADDRESS + 0x04)))
	
#define SYSCFG_EXTICR1 	  (*((volatile uint32*)(SYSCFG_BASE_ADDRESS + 0x08)))
#define SYSCFG_EXTICR2 	  (*((volatile uint32*)(SYSCFG_BASE_ADDRESS + 0x0C)))
#define SYSCFG_EXTICR3 	  (*((volatile uint32*)(SYSCFG_BASE_ADDRESS + 0x10)))
#define SYSCFG_EXTICR4 	  (*((volatile uint32*)(SYSCFG_BASE_ADDRESS + 0x14)))

#endif
