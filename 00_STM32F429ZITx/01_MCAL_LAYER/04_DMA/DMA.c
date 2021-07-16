
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/01_MCAL_LAYER/00_RCC/RCC.h"
#include "DMA_PRIVATE.h"
#include "DMA_Cfg.h"

#define RCC_EN_DMA2_ID   22

void u8DMA_StreamInit(void)
{
	//Step1: RCC Enable for DMA2 use function vRCC_EnPerClk
	vRCC_EnPerClk(RCC_AHB1ENR,RCC_EN_DMA2_ID);
	
	//Step2:Check on the Enable bit it must be disabled
	if((DMA2_Instant->StreamID[0].CR) == 1)
	{
		DMA2_Instant->StreamID[0].CR &=~ (1U<<0); // write 0 in Enable bit to disable the Stream
		while((DMA2_Instant->StreamID[0].CR) == 1) {} //waiting the Enable bit to be cleared 		
	}
	else {/*MISRA*/}
	
	//Step3:Select the proper channel in the stream
		//In our Application this step is not mandatory as we are using M to M mode
		
	//Step4:Set the stream Priority
	DMA2_Instant->StreamID[0].CR |= ((1U<<16)|(1U<<17)); // Priority of stream0 is very High
	
	//Step5:Set Direction mode
	DMA2_Instant->StreamID[0].CR |= (1U<<7);  //stream0 data direction mode is M to M
	DMA2_Instant->StreamID[0].CR &=~ (1U<<6);
	
	//Step6:Set the M and P size
	DMA2_Instant->StreamID[0].CR |= (1U<<12);  //M and P size is word (32bit)
	DMA2_Instant->StreamID[0].CR &=~ (1U<<11);
	DMA2_Instant->StreamID[0].CR |= (1U<<14);  
	DMA2_Instant->StreamID[0].CR &=~ (1U<<13);
	
	//Step7:Disable Direct mode
	DMA2_Instant->StreamID[0].FCR |= (1U<<2); //Disable to the direct mode
	
	//Step8:Set FIFO Threshold
	DMA2_Instant->StreamID[0].FCR |= (1U<<0); //Half FIFO buffer threshold
	DMA2_Instant->StreamID[0].FCR &=~ (1U<<1); 
	
	//Step9:SRC and DST Increamnet
	DMA2_Instant->StreamID[0].CR |= (1U<<9);  //Increamnet for both SRC and DST 
	DMA2_Instant->StreamID[0].CR |= (1U<<10);
	
	//Step10:Enable Transfer complete Interrupt
	DMA2_Instant->StreamID[0].CR |= (1U<<4); 
	
}

void vDMA_SetAddresses(uint32* Pu32SrcAdd, uint32* Pu32DstAdd, uint32 u32Size)
{
	DMA2_Instant->StreamID[0].PAR = (uint32)Pu32SrcAdd;
	DMA2_Instant->StreamID[0].M0AR = (uint32)Pu32DstAdd;
	DMA2_Instant->StreamID[0].NDTR = u32Size;
	
}


void vDMA_Enable(void)
{
 DMA2_Instant->LIFCR |= ((1U<<0)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5));
 DMA2_Instant->StreamID[0].CR |= (1U<<0);
}	
