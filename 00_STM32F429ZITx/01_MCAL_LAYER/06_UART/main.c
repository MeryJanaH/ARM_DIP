
#include "C:/Users/merye/Documents/Keil_workspace/00_STM32F429ZITx/00_LIBRARY_LAYER/00_STD_TYPES/STD_TYPES.h"
#include "stm32f429xx.h"

void vUART_Init(void);
void USART1_Enable(void);
void vUART_Write(int ch);
void delayMS(int delay);
void SysTick_Init(void);

int main(void)
{
	vUART_Init();
	USART1_Enable();
	
	while(1)
	{
		vUART_Write('E');
		vUART_Write('m');
		vUART_Write('b');
		vUART_Write('e');
		vUART_Write('d');
		vUART_Write('d');
		vUART_Write('e');
		vUART_Write('d');
		vUART_Write(' ');
		vUART_Write('M');
		vUART_Write('A');
		vUART_Write('\r');
		vUART_Write('\n');
		delayMS(1000);
	}
	
}

void USART1_Enable()
{
	//enable USART1
	USART1->CR1 |= USART_CR1_UE;
	
	//enable transmitter
	USART1->CR1 |= USART_CR1_TE;
	
	//enable receiver
	USART1->CR1 |= USART_CR1_RE;
}


void vUART_Init(){
		
	//enable port A clock 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	//select alternate function mode
	GPIOA->MODER &= ~(GPIO_MODER_MODER9 | GPIO_MODER_MODER10);
	GPIOA->MODER |= (GPIO_MODER_MODER9_1 | GPIO_MODER_MODER10_1);

	//select output type push-pull for Tx(PA9)
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_9);

	//select output speed medium for Tx(PA9)
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR9);
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9_0;

	//select pull up
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR9 | GPIO_PUPDR_PUPDR10);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR9_0 | GPIO_PUPDR_PUPDR10_0);
	
	//select AF7
	//AF PA9 / PA10 pin masks
	
	#define GPIO_AFRH_AFRH9          ((uint32_t) 0x000000F0)
	#define GPIO_AFRH_AFRH9_AF7      ((uint32_t) 0x00000070)
	#define GPIO_AFRH_AFRH10         ((uint32_t) 0x00000F00)
	#define GPIO_AFRH_AFRH10_AF7     ((uint32_t) 0x00000700)
	
	GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH9 | GPIO_AFRH_AFRH10);
	GPIOA->AFR[1] |= (GPIO_AFRH_AFRH9_AF7 | GPIO_AFRH_AFRH10_AF7);
	
	//configure USART1
	//enable USART1 clock
	RCC->APB2ENR = RCC_APB2ENR_USART1EN;

	//select oversampling by 16 mode
	USART1->CR1 &= ~USART_CR1_OVER8;

	//select one sample bit method 
	USART1->CR3 |= USART_CR3_ONEBIT;

	//select 1 start bit, Data bits, n stop bit
	USART1->CR1 |= USART_CR1_M;

	//select 1 stop bit 
	USART1->CR2 &= ~USART_CR2_STOP;

	//enable parity control 
	USART1->CR1 &=~ USART_CR1_PCE;

	//select odd parity
	USART1->CR1 |= USART_CR1_PS;


	USART1->BRR = 0x0683; // 9600bit/s
}

void vUART_Write(int ch)
{
	while(!(USART1->SR & (1U<<7))){}
		USART1->DR = (ch &0xFF);
}

void delayMS(int delay)
{
	int i;
	for(;delay>0;delay--)
	{
		for(i=0;i<3195;i++);
	}
}
