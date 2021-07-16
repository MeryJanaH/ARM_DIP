/**********************************************************/
/* Author    : Annouar Meryem                             */
/* Date      : 15/07/2021                            	    */
/**********************************************************/

#include "SPI.h"
#include "SPI_private.h"

void vSPI_Init(
				uint8 u8SPINumber,
				uint8 u8DeviceMode, 
				uint8 u8ClockPolarity, 
				uint8 u8ClockPhase,
				uint8 u8DataSize,
				uint8 u8DataDirection,
				uint8 u8NssMode,
				uint8 u8Baudrate,
				uint8 u8BiDiMode
				)

{
	switch(u8SPINumber)
	{
		case SPI1: 
		/* Configure the spi device mode */
		if(u8DeviceMode == SPI_MASTER) {SPI1_CR1_REG |= (1U<<2);}
		else if (u8DeviceMode == SPI_SLAVE) {SPI1_CR1_REG &=~ (1U<<2);}
		else {/*MISRA*/ }
		
		/* configure the phase and polartiy */
		if(u8ClockPolarity){SPI1_CR1_REG |= (1U<<1);}
		else {SPI1_CR1_REG &=~ (1U<<1);}
		if(u8ClockPhase){SPI1_CR1_REG |= (1U<<0);}
		else {SPI1_CR1_REG &=~ (1U<<0);}
		
		/* Configure the spi data size and direction */
		if(u8DataSize == DATASIZE_8){SPI1_CR1_REG &=~ (1U<<11);}
		else if(u8DataSize == DATASIZE_16){SPI1_CR1_REG |= (1U<<11);}
		else {/*MISRA*/ }
		
		if(u8DataDirection == DATADIR_MSB){SPI1_CR1_REG &=~ (1U<<7);}
		else if(u8DataDirection == DATADIR_LSB){SPI1_CR1_REG |= (1U<<7);}
		else {/*MISRA*/ }
		
		/* Configure the slave select line NSS Master and Slave*/
		if((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= ((1U<<9)|(1U<<8));}
		else if ((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else {/*MISRA*/ }
		
		/* Configure the  SPI deivce Baudrate */
		if((u8Baudrate <= 7)) {SPI1_CR1_REG |= (u8Baudrate<<3);}
		else {/*MISRA*/ }
		
		/* Configure the SPI device direction */
		if(u8BiDiMode) {SPI1_CR1_REG |= (1U<<15);}
		else {SPI1_CR1_REG &=~ (1U<<15);}
		/* Enable the SPI device  */
		
		break;
		
		case SPI2: 
		/* Configure the spi device mode */
		if(u8DeviceMode == SPI_MASTER) {SPI1_CR1_REG |= (1U<<2);}
		else if (u8DeviceMode == SPI_SLAVE) {SPI1_CR1_REG &=~ (1U<<2);}
		else {/*MISRA*/ }
		
		/* configure the phase and polartiy */
		if(u8ClockPolarity){SPI1_CR1_REG |= (1U<<1);}
		else {SPI1_CR1_REG &=~ (1U<<1);}
		if(u8ClockPhase){SPI1_CR1_REG |= (1U<<0);}
		else {SPI1_CR1_REG &=~ (1U<<0);}
		
		/* Configure the spi data size and direction */
		if(u8DataSize == DATASIZE_8){SPI1_CR1_REG &=~ (1U<<11);}
		else if(u8DataSize == DATASIZE_16){SPI1_CR1_REG |= (1U<<11);}
		else {/*MISRA*/ }
		
		if(u8DataDirection == DATADIR_MSB){SPI1_CR1_REG &=~ (1U<<7);}
		else if(u8DataDirection == DATADIR_LSB){SPI1_CR1_REG |= (1U<<7);}
		else {/*MISRA*/ }
		
		/* Configure the slave select line NSS Master and Slave*/
		if((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= ((1U<<9)|(1U<<8));}
		else if ((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else {/*MISRA*/ }
		/* Configure the  SPI deivce Baudrate */
		if((u8Baudrate <= 7)) {SPI1_CR1_REG |= (u8Baudrate<<3);}
		else {/*MISRA*/ }
		
		/* Configure the SPI device direction */
		if(u8BiDiMode) {SPI1_CR1_REG |= (1U<<15);}
		else {SPI1_CR1_REG &=~ (1U<<15);}
		/* Enable the SPI device  */
		break;
		
		case SPI3: 
		/* Configure the spi device mode */
		if(u8DeviceMode == SPI_MASTER) {SPI1_CR1_REG |= (1U<<2);}
		else if (u8DeviceMode == SPI_SLAVE) {SPI1_CR1_REG &=~ (1U<<2);}
		else {/*MISRA*/ }
		
		/* configure the phase and polartiy */
		if(u8ClockPolarity){SPI1_CR1_REG |= (1U<<1);}
		else {SPI1_CR1_REG &=~ (1U<<1);}
		if(u8ClockPhase){SPI1_CR1_REG |= (1U<<0);}
		else {SPI1_CR1_REG &=~ (1U<<0);}
		
		/* Configure the spi data size and direction */
		if(u8DataSize == DATASIZE_8){SPI1_CR1_REG &=~ (1U<<11);}
		else if(u8DataSize == DATASIZE_16){SPI1_CR1_REG |= (1U<<11);}
		else {/*MISRA*/ }
		
		if(u8DataDirection == DATADIR_MSB){SPI1_CR1_REG &=~ (1U<<7);}
		else if(u8DataDirection == DATADIR_LSB){SPI1_CR1_REG |= (1U<<7);}
		else {/*MISRA*/ }
		
		/* Configure the slave select line NSS Master and Slave*/
		if((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= ((1U<<9)|(1U<<8));}
		else if ((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else {/*MISRA*/ }
		
		/* Configure the  SPI deivce Baudrate */
		if((u8Baudrate <= 7)) {SPI1_CR1_REG |= (u8Baudrate<<3);}
		else {/*MISRA*/ }
		
		/* Configure the SPI device direction */
		if(u8BiDiMode) {SPI1_CR1_REG |= (1U<<15);}
		else {SPI1_CR1_REG &=~ (1U<<15);}
		/* Enable the SPI device  */
		break;
		
		
		case SPI4: 
		/* Configure the spi device mode */
		if(u8DeviceMode == SPI_MASTER) {SPI1_CR1_REG |= (1U<<2);}
		else if (u8DeviceMode == SPI_SLAVE) {SPI1_CR1_REG &=~ (1U<<2);}
		else {/*MISRA*/ }
		
		/* configure the phase and polartiy */
		if(u8ClockPolarity){SPI1_CR1_REG |= (1U<<1);}
		else {SPI1_CR1_REG &=~ (1U<<1);}
		if(u8ClockPhase){SPI1_CR1_REG |= (1U<<0);}
		else {SPI1_CR1_REG &=~ (1U<<0);}
		
		/* Configure the spi data size and direction */
		if(u8DataSize == DATASIZE_8){SPI1_CR1_REG &=~ (1U<<11);}
		else if(u8DataSize == DATASIZE_16){SPI1_CR1_REG |= (1U<<11);}
		else {/*MISRA*/ }
		
		if(u8DataDirection == DATADIR_MSB){SPI1_CR1_REG &=~ (1U<<7);}
		else if(u8DataDirection == DATADIR_LSB){SPI1_CR1_REG |= (1U<<7);}
		else {/*MISRA*/ }
		
		/* Configure the slave select line NSS Master and Slave*/
		if((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= ((1U<<9)|(1U<<8));}
		else if ((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else {/*MISRA*/ }
		
		/* Configure the  SPI deivce Baudrate */
		if((u8Baudrate <= 7)) {SPI1_CR1_REG |= (u8Baudrate<<3);}
		else {/*MISRA*/ }
		
		/* Configure the SPI device direction */
		if(u8BiDiMode) {SPI1_CR1_REG |= (1U<<15);}
		else {SPI1_CR1_REG &=~ (1U<<15);}
		/* Enable the SPI device  */
		break;
		
		
		case SPI5: 
		/* Configure the spi device mode */
		if(u8DeviceMode == SPI_MASTER) {SPI1_CR1_REG |= (1U<<2);}
		else if (u8DeviceMode == SPI_SLAVE) {SPI1_CR1_REG &=~ (1U<<2);}
		else {/*MISRA*/ }
		
		/* configure the phase and polartiy */
		if(u8ClockPolarity){SPI1_CR1_REG |= (1U<<1);}
		else {SPI1_CR1_REG &=~ (1U<<1);}
		if(u8ClockPhase){SPI1_CR1_REG |= (1U<<0);}
		else {SPI1_CR1_REG &=~ (1U<<0);}
		
		/* Configure the spi data size and direction */
		if(u8DataSize == DATASIZE_8){SPI1_CR1_REG &=~ (1U<<11);}
		else if(u8DataSize == DATASIZE_16){SPI1_CR1_REG |= (1U<<11);}
		else {/*MISRA*/ }
		
		if(u8DataDirection == DATADIR_MSB){SPI1_CR1_REG &=~ (1U<<7);}
		else if(u8DataDirection == DATADIR_LSB){SPI1_CR1_REG |= (1U<<7);}
		else {/*MISRA*/ }
		
		/* Configure the slave select line NSS Master and Slave*/
		if((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= ((1U<<9)|(1U<<8));}
		else if ((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else {/*MISRA*/ }
		
		/* Configure the  SPI deivce Baudrate */
		if((u8Baudrate <= 7)) {SPI1_CR1_REG |= (u8Baudrate<<3);}
		else {/*MISRA*/ }
		/* Configure the SPI device direction */
		if(u8BiDiMode) {SPI1_CR1_REG |= (1U<<15);}
		else {SPI1_CR1_REG &=~ (1U<<15);}
		/* Enable the SPI device  */
		break;
		
		
		case SPI6:
		/* Configure the spi device mode */
		if(u8DeviceMode == SPI_MASTER) {SPI1_CR1_REG |= (1U<<2);}
		else if (u8DeviceMode == SPI_SLAVE) {SPI1_CR1_REG &=~ (1U<<2);}
		else {/*MISRA*/ }
		
		/* configure the phase and polartiy */
		if(u8ClockPolarity){SPI1_CR1_REG |= (1U<<1);}
		else {SPI1_CR1_REG &=~ (1U<<1);}
		if(u8ClockPhase){SPI1_CR1_REG |= (1U<<0);}
		else {SPI1_CR1_REG &=~ (1U<<0);}
		
		/* Configure the spi data size and direction */
		if(u8DataSize == DATASIZE_8){SPI1_CR1_REG &=~ (1U<<11);}
		else if(u8DataSize == DATASIZE_16){SPI1_CR1_REG |= (1U<<11);}
		else {/*MISRA*/ }
		
		if(u8DataDirection == DATADIR_MSB){SPI1_CR1_REG &=~ (1U<<7);}
		else if(u8DataDirection == DATADIR_LSB){SPI1_CR1_REG |= (1U<<7);}
		else {/*MISRA*/ }
		
		/* Configure the slave select line NSS Master and Slave*/
		if((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= ((1U<<9)|(1U<<8));}
		else if ((u8DeviceMode == SPI_MASTER) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_SW)) {SPI1_CR1_REG |= (1U<<9);}
		else if ((u8DeviceMode == SPI_SLAVE) && (u8NssMode == NSS_MODE_HW)) {SPI1_CR1_REG &=~ (1U<<9);}
		else {/*MISRA*/ }
		
		/* Configure the  SPI deivce Baudrate */
		if((u8Baudrate <= 7)) {SPI1_CR1_REG |= (u8Baudrate<<3);}
		else {/*MISRA*/ }
		
		/* Configure the SPI device direction */
		if(u8BiDiMode) {SPI1_CR1_REG |= (1U<<15);}
		else {SPI1_CR1_REG &=~ (1U<<15);}
		/* Enable the SPI device  */			
		break;
		
		default:break;
		
	}
	
}


void vSPI_Enable(uint8 u8SPINumber)
{
	switch(u8SPINumber)
	{
		case SPI1: SPI1_CR1_REG |= (1U<<6); break;
		case SPI2: SPI2_CR1_REG |= (1U<<6); break;
		case SPI3: SPI3_CR1_REG |= (1U<<6); break;
		case SPI4: SPI4_CR1_REG |= (1U<<6); break;
		case SPI5: SPI5_CR1_REG |= (1U<<6); break;
		case SPI6: SPI6_CR1_REG |= (1U<<6); break;
	}
	
}
void vSPI_Disable(uint8 u8SPINumber)
{
	switch(u8SPINumber)
	{
		case SPI1: SPI1_CR1_REG &=~ (1U<<6); break;
		case SPI2: SPI2_CR1_REG &=~ (1U<<6); break;
		case SPI3: SPI3_CR1_REG &=~ (1U<<6); break;
		case SPI4: SPI4_CR1_REG &=~ (1U<<6); break;
		case SPI5: SPI5_CR1_REG &=~ (1U<<6); break;
		case SPI6: SPI6_CR1_REG &=~ (1U<<6); break;
	}
}




uint8 u8SPI_Write8BitData(uint8 u8SPINumber, uint8 u8DataOut) {
	switch(u8SPINumber)
	{
		case SPI1:
			/* Check if SPI is enabled */
			if(!(SPI1_CR1_REG & (1U<<6))){vSPI_Enable(SPI1);}
			
			/* Wait for previous transmissions to complete */
			while(((SPI1_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI1_SR_REG & (1U<<7)));
			
			/* Fill output buffer with data */
			SPI1_DR_REG = u8DataOut;
				
			/* Wait for SPI to end everything */
			while(((SPI1_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI1_SR_REG & (1U<<7)));
				
			/* Read data register */
			return(SPI1_DR_REG);
			
			case SPI2:
			/* Check if SPI is enabled */
			if(!(SPI2_CR1_REG & (1U<<6))){vSPI_Enable(SPI2);}
			
			/* Wait for previous transmissions to complete */
			while(((SPI2_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI2_SR_REG & (1U<<7)));
			
			/* Fill output buffer with data */
			SPI2_DR_REG = u8DataOut;
				
			/* Wait for SPI to end everything */
			while(((SPI2_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI2_SR_REG & (1U<<7)));
				
			/* Read data register */
			return(SPI2_DR_REG);
			
			case SPI3:
			/* Check if SPI is enabled */
			if(!(SPI3_CR1_REG & (1U<<6))){vSPI_Enable(SPI3);}
			
			/* Wait for previous transmissions to complete */
			while(((SPI3_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI3_SR_REG & (1U<<7)));
			
			/* Fill output buffer with data */
			SPI3_DR_REG = u8DataOut;
				
			/* Wait for SPI to end everything */
			while(((SPI3_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI3_SR_REG & (1U<<7)));
				
			/* Read data register */
			return(SPI3_DR_REG);
			
			case SPI4:
			/* Check if SPI is enabled */
			if(!(SPI4_CR1_REG & (1U<<6))){vSPI_Enable(SPI4);}
			
			/* Wait for previous transmissions to complete */
			while(((SPI4_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI4_SR_REG & (1U<<7)));
			
			/* Fill output buffer with data */
			SPI4_DR_REG = u8DataOut;
				
			/* Wait for SPI to end everything */
			while(((SPI4_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI4_SR_REG & (1U<<7)));
				
			/* Read data register */
			return(SPI4_DR_REG);
			
			case SPI5:
			/* Check if SPI is enabled */
			if(!(SPI5_CR1_REG & (1U<<6))){vSPI_Enable(SPI5);}
			
			/* Wait for previous transmissions to complete */
			while(((SPI5_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI5_SR_REG & (1U<<7)));
			
			/* Fill output buffer with data */
			SPI5_DR_REG = u8DataOut;
				
			/* Wait for SPI to end everything */
			while(((SPI5_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI5_SR_REG & (1U<<7)));
				
			/* Read data register */
			return(SPI5_DR_REG);
		
			case SPI6:
			/* Check if SPI is enabled */
			if(!(SPI6_CR1_REG & (1U<<6))){vSPI_Enable(SPI6);}
			
			/* Wait for previous transmissions to complete */
			while(((SPI6_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI6_SR_REG & (1U<<7)));
			
			/* Fill output buffer with data */
			SPI6_DR_REG = u8DataOut;
				
			/* Wait for SPI to end everything */
			while(((SPI6_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI6_SR_REG & (1U<<7)));
				
			/* Read data register */
			return(SPI6_DR_REG);
	}
}



void vSPI_WriteMulti8BitData(uint8 u8SPINumber, uint8* u8DataOut, uint8* u8DataIn, uint8 u8Count) {
	uint8 index;
	
	/* Check if SPI is enabled */
	if(!(SPI1_CR1_REG & (1U<<6))){vSPI_Enable(SPI1);}
	
	/* Wait for previous transmissions to complete */
	while(((SPI1_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI1_SR_REG & (1U<<7)));
	
	for (index = 0; index < u8Count; index++) {
		/* Fill output buffer with data */
		SPI1_DR_REG = u8DataOut[index];
		
		/* Wait for SPI to end everything */
		while(((SPI1_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI1_SR_REG & (1U<<7)));
		
		/* Read data register */
		u8DataIn[index] = SPI1_DR_REG;
	}
}


void vSPI_ReadMulti8BitData(uint8 u8SPINumber, uint8* u8DataIn, uint8 u8dummy, uint8 u8Count) {
	uint8 index;
	
	/* Check if SPI is enabled */
	if(!(SPI1_CR1_REG & (1U<<6))){vSPI_Enable(SPI1);}
	
	/* Wait for previous transmissions to complete */
	while(((SPI1_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI1_SR_REG & (1U<<7)));
	
	for (index = 0; index < u8Count; index++) {
		/* Fill output buffer with data */
		SPI1_DR_REG = u8dummy;
		
		/* Wait for SPI to end everything */
		while(((SPI1_SR_REG & ((1U<<1)|(1U<<0))) == 0) || (SPI1_SR_REG & (1U<<7)));
		
		/* Save data to buffer */
		u8DataIn[index] = SPI1_DR_REG;
	}
}

