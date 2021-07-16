#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"

void u8DMA_StreamInit(void);
void vDMA_SetAddresses(uint32* Pu32SrcAdd, uint32* Pu32DstAdd, uint32 u32Size);
void vDMA_Enable(void);
void DMA2_Stream0_IRQHandler(void);

