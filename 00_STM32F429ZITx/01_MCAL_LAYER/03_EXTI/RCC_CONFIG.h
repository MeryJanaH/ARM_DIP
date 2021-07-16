 /******************************************************************************
 *
 * Layer: MCAL
 *
 * File Name: RCC_CONFIG.c
 *
 * Description: contains all the configuration of the RCC peripheral
 *
 * By : ANNOUAR Meryem
 *******************************************************************************/
 
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"

typedef  enum
{
	AHB1=0,
	AHB2,
	AHB3,
	APB1,
	APB2
}BusName_t;

typedef  enum
{
	HSE=0,
	HSI,
	PLL
}ClKSrcName_t;


typedef  enum
{
	HSE_Crystal=0,
	HSE_RC
}HSESrcName_t;


typedef  enum
{
	PLL_HSE=0,
	PLL_HSI
}PLLSrcName_t;


typedef  enum
{
	AHB_Pre1=0,
	AHB_Pre2,
	AHB_Pre4,
	AHB_Pre8,
	AHB_Pre16,
	AHB_Pre64,
	AHB_Pre128,
	AHB_Pre256,
	AHB_Pre512
}AHBPreName_t;


typedef  enum
{
	APB1_Pre1=0,
	APB1_Pre2,
	APB1_Pre4,
	APB1_Pre8,
	APB1_Pre16,
}APB1PreName_t;


typedef  enum
{
	APB2_Pre1=0,
	APB2_Pre2,
	APB2_Pre4,
	APB2_Pre8,
	APB2_Pre16,
}APB2PreName_t;




