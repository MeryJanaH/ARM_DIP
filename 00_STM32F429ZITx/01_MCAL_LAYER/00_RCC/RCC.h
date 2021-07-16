 /******************************************************************************
 *
 * Layer: MCAL
 *
 * File Name: RCC.h
 *
 * Description: contains all the functions prototypes and used macros
 *
 * By : ANNOUAR Meryem
 *******************************************************************************/


#ifndef RCC_H
#define RCC_H

#include "RCC_CONFIG.h"

 /******************************************************************************
 *
 *			Functions Prototypes
 *
 *******************************************************************************/

void vRCC_SetSYSCLK(ClKSrcName_t ClkSrc, HSESrcName_t HSESRC, PLLSrcName_t PLLSrc, AHBPreName_t AHB_Prescaler, APB1PreName_t APB1_Prescaler, APB2PreName_t APB2_Prescaler);
void vRCC_EnPerClk(BusName_t BusName, uint8 PerName);




 /******************************************************************************
 *
 *			Macros
 *
 *******************************************************************************/
//RCC Base address is 0x40023800
/* RCC Register Map */
#define RCC_CR              *((uint32*)0x40023800)
#define RCC_PLLCFGR         *((uint32*)0x40023804)
#define RCC_CFGR            *((uint32*)0x40023808)
#define RCC_CIR        		  *((uint32*)0x4002380C)
#define RCC_AHB1RSTR        *((uint32*)0x40023810)
#define RCC_AHB2RSTR        *((uint32*)0x40023814)
#define RCC_AHB3RSTR        *((uint32*)0x40023818)
#define RCC_APB1RSTR  		  *((uint32*)0x40023820)
#define RCC_APB2RSTR   		  *((uint32*)0x40023824)
#define RCC_AHB1ENR     	  *((uint32*)0x40023830)
#define RCC_AHB2ENR     	  *((uint32*)0x40023834)
#define RCC_AHB3ENR     	  *((uint32*)0x40023838)
#define RCC_APB1ENR    		  *((uint32*)0x40023840)
#define RCC_APB2ENR    		  *((uint32*)0x40023844)
#define RCC_AHB1LPENR      	*((uint32*)0x40023850)
#define RCC_AHB2LPENR      	*((uint32*)0x40023854)
#define RCC_AHB3LPENR      	*((uint32*)0x40023858)
#define RCC_APB1LPENR      	*((uint32*)0x40023860)
#define RCC_APB2LPENR      	*((uint32*)0x40023864)
#define RCC_BDCR       	  	*((uint32*)0x40023870)
#define RCC_CSR        		  *((uint32*)0x40023874)
#define RCC_SSCGR          	*((uint32*)0x40023880)
#define RCC_PLLI2SCFGR      *((uint32*)0x40023884)
#define RCC_PLLSAICFGR      *((uint32*)0x40023888)
#define RCC_DCKCFGR         *((uint32*)0x4002388C)


	/* Macros Of :
			         
							- RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
	*/
#define PERIPHERAL_EN_GPIOA						     	0
#define PERIPHERAL_EN_GPIOB						     	1
#define PERIPHERAL_EN_GPIOC						     	2
#define PERIPHERAL_EN_GPIOD						     	3
#define PERIPHERAL_EN_GPIOE						     	4
#define PERIPHERAL_EN_GPIOF						     	5
#define PERIPHERAL_EN_GPIOG						     	6
#define PERIPHERAL_EN_GPIOH						     	7
#define PERIPHERAL_EN_GPIOI						     	8
#define PERIPHERAL_EN_CRC							       12
#define PERIPHERAL_EN_FLITF            15
#define PERIPHERAL_EN_BKPSRAM         	18
#define PERIPHERAL_EN_CCMDATARAM      	20
#define PERIPHERAL_EN_DMA1						      	21
#define PERIPHERAL_EN_DMA2						      	22
#define PERIPHERAL_EN_ETHMAC						     25
#define PERIPHERAL_EN_ETHMACTX         26
#define PERIPHERAL_EN_ETHMACRX         27
#define PERIPHERAL_EN_ETHMACPTP        28
#define PERIPHERAL_EN_OTGHS					  	    29
#define PERIPHERAL_EN_OTGHSULPI        30					
/* Macros Of :
			         
							- RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
	*/
	
#define PERIPHERAL_EN_DCMI 						 0
#define PERIPHERAL_EN_CRYP 						 4
#define PERIPHERAL_EN_HASH 						 5
#define PERIPHERAL_EN_RNG 	  				 6
#define PERIPHERAL_EN_OTGFS 					 7

	/* Macros Of :
			         
							- RCC APB1 peripheral clock enable register
	*/
		
#define PERIPHERAL_EN_TIM2						 0
#define PERIPHERAL_EN_TIM3					 	1
#define PERIPHERAL_EN_TIM4					  2
#define PERIPHERAL_EN_TIM5					  3
#define PERIPHERAL_EN_TIM6						 4
#define PERIPHERAL_EN_TIM7					 	5
#define PERIPHERAL_EN_TIM12					 6
#define PERIPHERAL_EN_TIM13				  7
#define PERIPHERAL_EN_TIM14				  8
#define PERIPHERAL_EN_WWDG					 	11
#define PERIPHERAL_EN_SPI2				 		14
#define PERIPHERAL_EN_SPI3					 	15
#define PERIPHERAL_EN_UART2						17
#define PERIPHERAL_EN_UART3						18
#define PERIPHERAL_EN_UART4						19
#define PERIPHERAL_EN_UART5						20
#define PERIPHERAL_EN_I2C1					 	21
#define PERIPHERAL_EN_I2C2					 	22
#define PERIPHERAL_EN_I2C3					 	23
#define PERIPHERAL_EN_CAN1					 	25
#define PERIPHERAL_EN_CAN2					 	26
#define PERIPHERAL_EN_PWR						  28
#define PERIPHERAL_EN_DAC						  29

/* Macros Of :
			         
							- RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)
	*/

#define PERIPHERAL_EN_FSMC					 0

/* Macros Of :
			         
							- RCC APB2 peripheral clock enable register (RCC_APB2ENR)
	*/

#define PERIPHERAL_EN_TIM1  				 0
#define PERIPHERAL_EN_TIM8					 1
#define PERIPHERAL_EN_USART1				 4
#define PERIPHERAL_EN_USART6				 5
#define PERIPHERAL_EN_ADC1					 8
#define PERIPHERAL_EN_ADC2					 9
#define PERIPHERAL_EN_ADC3					 10
#define PERIPHERAL_EN_SDIO					 11
#define PERIPHERAL_EN_SPI1					 12
#define PERIPHERAL_EN_SYSCFG				 14
#define PERIPHERAL_EN_TIM9					 16
#define PERIPHERAL_EN_TIM10					 17
#define PERIPHERAL_EN_TIM11 				 18
	 
     












#endif
