/**********************************************************/
/* Author    : Annouar Meryem                             */
/* Date      : 15/07/2021                            	    */
/**********************************************************/
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"

#ifndef SPI_H
#define SPI_H

#define SPI1 1
#define SPI2 2
#define SPI3 3
#define SPI4 4
#define SPI5 5
#define SPI6 6

#define SPI_MASTER 		0
#define SPI_SLAVE 		1

#define DATASIZE_8 		0
#define DATASIZE_16 	1

#define DATADIR_MSB 	0
#define DATADIR_LSB 	1

#define NSS_MODE_SW		0
#define NSS_MODE_HW		1



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
				);
void vSPI_Enable(uint8 u8SPINumber);
void vSPI_Disable(uint8 u8SPINumber);
uint8 u8SPI_Write8BitData(uint8 u8SPINumber, uint8 u8DataOut);



#endif
