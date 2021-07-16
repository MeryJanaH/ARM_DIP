// Memory to Memory 

/* 
We have 3 options to copy data from one array to another
- Using Indirect method: for loop  u32DST_Array[index] = u32SRC_Array[index] 
- Using Direct method(Pointers): while loop *u32DST_Array++ = *u32SRC_Array++
- Using DMA
Conclusion: DMA is the fastest method then pointer method then indirect method
*/


#define SIZE  500

#include "stm32f429xx.h"
#include "DMA_PRIVATE.h"
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/01_MCAL_LAYER/02_NVIC/NVIC.h"

int main(void)
{
	
 uint32 u32SRC_Array[SIZE];
 uint32 u32DST_Array[SIZE];

 //Init SRC array with these values: {0,1,2,3,4,... 499}	
 uint32 u32index;
 for(u32index=0; u32index<SIZE; u32index++)
 {
	u32SRC_Array[u32index]=u32index;
 }

 vNVIC_SetEnable(56); //Enable NVIC for DMA IRQ
 u8DMA_StreamInit();
 vDMA_SetAddresses(u32SRC_Array,u32DST_Array,SIZE);
 vDMA_Enable();
}

// This ISR function is called if any flag is raised from the 5 flags of DMA
void DMA2_Stream0_IRQHandler(void)
{
	// Action indicates that transfer complete operation is done successfully 
	DMA2_Instant->LIFCR |=(1U<<5);
}
