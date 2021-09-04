#include "TM4C123GH6PM.h"

int main()
{
 int FirstEdge, SecondEdge, CalculatedTime;
//Configuration for pinB6
// EN clock of PORTB 
SYSCTL->RCGCGPIO |= (1U<<1);
// Config PB6 as IN pin
GPIOB->DIR &= ~(1U<<6); 
// Config PB6 as digital pin
GPIOB->DEN |= (1U<<6); 
// Config PB6 as alternate function
GPIOB->AFSEL |= (1U<<6); 
// Config PB6 for T0CCP0
GPIOB->PCTL &= ~((1U<<24)|(1U<<25)|(1U<<26)|(1U<<27)); 
GPIOB->PCTL |= ((1U<<24)|(1U<<25)|(1U<<26));

//Initialization and Configuration for GPT
//To use a GPTM, the appropriate TIMER0 bit must be set in the RCGCTIMER
  SYSCTL->RCGCTIMER |= (1u<<0);
//11.4.1 One-Shot/Periodic Timer Mode
//The GPTM is configured for One-Shot and Periodic modes by the following sequence:
//1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making
//any changes.
  TIMER0->CTL &=~(1U<<0);
//2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x04 (16bit half range Timer)
  TIMER0->CFG = 0x04;
//3. Configure the Timer up-count, edge-time, capture mode
  TIMER0->TAMR |= ((1U<<0)|(1U<<1)|(1U<<2)|(1U<<4));
//4. Configure the rising edge
  TIMER0->CTL &=~((1U<<2)|(1U<<3));
 
//5. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.
  TIMER0->CTL |=(1U<<0);
//8. Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). 
  while(1)
  {
  
   // Capture the first rising edge
    // clear timer0A capture flag
    TIMER0->ICR |= (1U<<2); 
    // Poll on the capture flag
    while((TIMER0->RIS & (1U<<2)) == 0); 
    // store the first snap
    FirstEdge = TIMER0->TAR; 
    
   // Capture the Second rising edge
    // clear timer0A capture flag
    TIMER0->ICR |= (1U<<2); 
    // Poll on the capture flag
    while((TIMER0->RIS & (1U<<2)) == 0);
    // store the second snap
    SecondEdge = TIMER0->TAR;
    
   // Calculate the time difference
    CalculatedTime = SecondEdge - FirstEdge; 
  }
  
  return 0;
}
