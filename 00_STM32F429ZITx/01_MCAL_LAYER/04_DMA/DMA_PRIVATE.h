#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"

typedef struct
{
	volatile uint32 CR;
	volatile uint32 NDTR;
	volatile uint32 PAR;
	volatile uint32 M0AR;
	volatile uint32 M1AR;
	volatile uint32 FCR;
}DMA_Stream_t;

typedef struct
{
	volatile uint32 LISR;
	volatile uint32 HISR;
	volatile uint32 LIFCR;
	volatile uint32 HIFCR;
	DMA_Stream_t StreamID[8];
}DMA_Cfg_t;

//base address 0x40026400
#define DMA2_Instant	((volatile DMA_Cfg_t*)0x40026400)  //Pointer to (struct of type DMA)

#endif

