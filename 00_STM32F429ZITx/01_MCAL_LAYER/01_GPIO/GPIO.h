#ifndef GPIO_H
#define GPIO_H

#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"

/* USER Macros*/
#define GPIOA				0
#define GPIOB				1
#define GPIOC				2
#define GPIOD				3
#define GPIOE				4
#define GPIOF				5
#define GPIOG 			6
#define GPIOH				7

#define PIN0 				0
#define PIN1 				1
#define PIN2 				2
#define PIN3 				3
#define PIN4 				4
#define PIN5 				5
#define PIN6 				6
#define PIN7 				7
#define PIN8 				8
#define PIN9 				9
#define PIN10				10
#define PIN11				11
#define PIN12				12
#define PIN13				13
#define PIN14				14
#define PIN15				15

#define LCKK				16

#define GPIO_INPUT_MODE ((uint8)0x00)
#define GPIO_OUTPUT_MODE ((uint8)0x01)
#define GPIO_ALTFCT_MODE ((uint8)0x10)
#define GPIO_ANALOG_MODE ((uint8)0x11)

#define GPIO_OUTPUT_PUSHPULL ((uint8)0x00)
#define GPIO_OUTPUT_OPENDRAIN ((uint8)0x01)

#define GPIO_OUTPUT_LSPEED ((uint8) 0x00)
#define GPIO_OUTPUT_MSPEED ((uint8) 0x01)
#define GPIO_OUTPUT_HSPEED ((uint8) 0x10)
#define GPIO_OUTPUT_VSPEED ((uint8) 0x11)

/* Functions Prototypes*/
void vGPIO_PinSetMode(uint8 Port_Name, uint8 Pin_Number, uint8 Mode);
void vGPIO_PinSetOutType(uint8 Port_Name, uint8 Pin_Number, uint8 Output_Type);
void vGPIO_PinSetOutSpeed(uint8 Port_Name, uint8 Pin_Number, uint8 Speed);
void vGPIO_PinSetPull_UP_DOWN(uint8 Port_Name, uint8 Pin_Number, uint8 Pull_Type);
uint8 u8GPIO_PinReadData(uint8 Port_Name, uint8 Pin_Number);
void vGPIO_PinWriteData(uint8 Port_Name, uint8 Pin_Number, uint8 Value);
void vGPIO_PinLock(uint8 Port_Name, uint8 Pin_Number);
void vGPIO_PinSetAltFn(uint8 Port_Name, uint8 Pin_Number, uint8 Alt_Value);





#endif
