/**********************************************************/
/* Author    : Annouar Meryem                             */
/* Date      : 15/07/2021                            	    */
/**********************************************************/


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPI1_BASE_ADDRESS				0x40013000		/*APB2 Bus*/
#define SPI2_BASE_ADDRESS				0x40003800 		/*APB1 Bus*/
#define SPI3_BASE_ADDRESS				0x40003C00		/*APB1 Bus*/
#define SPI4_BASE_ADDRESS				0x40013400		/*APB2 Bus*/
#define SPI5_BASE_ADDRESS				0x40015000		/*APB2 Bus*/
#define SPI6_BASE_ADDRESS				0x40015400		/*APB2 Bus*/


#define SPI1_CR1_REG					(*((volatile uint32*)(SPI1_BASE_ADDRESS + 0x00)))
#define SPI1_CR2_REG					(*((volatile uint32*)(SPI1_BASE_ADDRESS + 0x04)))
#define SPI1_SR_REG						(*((volatile uint32*)(SPI1_BASE_ADDRESS + 0x08)))
#define SPI1_DR_REG						(*((volatile uint32*)(SPI1_BASE_ADDRESS + 0x0C)))

#define SPI2_CR1_REG					(*((volatile uint32*)(SPI2_BASE_ADDRESS + 0x00)))
#define SPI2_CR2_REG					(*((volatile uint32*)(SPI2_BASE_ADDRESS + 0x04)))
#define SPI2_SR_REG						(*((volatile uint32*)(SPI2_BASE_ADDRESS + 0x08)))
#define SPI2_DR_REG						(*((volatile uint32*)(SPI2_BASE_ADDRESS + 0x0C)))

#define SPI3_CR1_REG					(*((volatile uint32*)(SPI3_BASE_ADDRESS + 0x00)))
#define SPI3_CR2_REG					(*((volatile uint32*)(SPI3_BASE_ADDRESS + 0x04)))
#define SPI3_SR_REG						(*((volatile uint32*)(SPI3_BASE_ADDRESS + 0x08)))
#define SPI3_DR_REG						(*((volatile uint32*)(SPI3_BASE_ADDRESS + 0x0C)))
	
#define SPI4_CR1_REG					(*((volatile uint32*)(SPI4_BASE_ADDRESS + 0x00)))
#define SPI4_CR2_REG					(*((volatile uint32*)(SPI4_BASE_ADDRESS + 0x04)))
#define SPI4_SR_REG						(*((volatile uint32*)(SPI4_BASE_ADDRESS + 0x08)))
#define SPI4_DR_REG						(*((volatile uint32*)(SPI4_BASE_ADDRESS + 0x0C)))

#define SPI5_CR1_REG					(*((volatile uint32*)(SPI5_BASE_ADDRESS + 0x00)))
#define SPI5_CR2_REG					(*((volatile uint32*)(SPI5_BASE_ADDRESS + 0x04)))
#define SPI5_SR_REG						(*((volatile uint32*)(SPI5_BASE_ADDRESS + 0x08)))
#define SPI5_DR_REG						(*((volatile uint32*)(SPI5_BASE_ADDRESS + 0x0C)))
	
#define SPI6_CR1_REG					(*((volatile uint32*)(SPI6_BASE_ADDRESS + 0x00)))
#define SPI6_CR2_REG					(*((volatile uint32*)(SPI6_BASE_ADDRESS + 0x04)))
#define SPI6_SR_REG						(*((volatile uint32*)(SPI6_BASE_ADDRESS + 0x08)))
#define SPI6_DR_REG						(*((volatile uint32*)(SPI6_BASE_ADDRESS + 0x0C)))


#endif
