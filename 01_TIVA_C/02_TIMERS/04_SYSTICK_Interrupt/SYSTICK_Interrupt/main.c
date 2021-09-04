/****************************************************************************************************//**
 * @file     main.c
 *
 * @brief    Application on SYSTICK Timer
 *           
 *
 * @version  V1.0
 * @date     8. MAR 2021
 *******************************************************************************************************/

#include "TM4C123GH6PM.h"

void SysTick_Handler(void);

int main (void)
{
/* Enable Clock Gating for GPIOF */
SYSCTL->RCGCGPIO |= (1U<<5);
// Set LED pins 1 as output (Other leds pins are 2,3)
GPIOF->DIR = (1U<<1);
/* Enable digital functionality for LED pin 1 in GPIOF */
GPIOF->DEN = (1U<<1);
/* Init all leds to zero */
GPIOF->DATA &=~ (1U<<1); 



SysTick->CTRL |= (1U<<0)|(1U<<2)|(1U<<1);
SysTick->LOAD = 8000000U-1;
 
while (1)
{
  
}

}


void SysTick_Handler(void)
{
 GPIOF->DATA ^= (1U<<1); 
}
