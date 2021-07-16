/*************************************/
/********Author : Meryem ANNOUAR******/
/********Date : 28/05/21 *************/
/*************************************/

#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS 0xE000E100


#define NVIC_ISER0 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x100)))
#define NVIC_ISER1 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x104)))

#define NVIC_ICER0 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x180)))
#define NVIC_ICER1 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x184)))

#define NVIC_ISPR0 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x200)))
#define NVIC_ISPR1 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x204)))

#define NVIC_ICPR0 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x280)))
#define NVIC_ICPR1 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x284)))

#define NVIC_IABR0 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x300)))
#define NVIC_IABR1 	(*((volatile uint32*)(NVIC_BASE_ADDRESS + 0x304)))

#define NVIC_IPR    (((volatile uint8*)(NVIC_BASE_ADDRESS + 0x400)))

#define SCB_BASE_ADDRESS 	0xE000E

#define SCB_AIRCR		(*((volatile uint32*)(SCB_BASE_ADDRESS + 0x0c)))

#define GROUP_PRIORITY_CGF0      0
#define GROUP_PRIORITY_CGF1      1
#define GROUP_PRIORITY_CGF2      2
#define GROUP_PRIORITY_CGF3      3
#define GROUP_PRIORITY_CGF4      4
#endif
