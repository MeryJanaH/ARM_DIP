
 /******************************************************************************
 *
 * Layer: MCAL
 *
 * File Name: RCC.c
 *
 * Description: contains all the functions definations for RCC (Version with Macros)
 *
 * By : ANNOUAR Meryem
 *******************************************************************************/
#include "RCC.h"


void vRCC_SetSYSCLK(ClKSrcName_t ClkSrc, HSESrcName_t HSESRC, PLLSrcName_t PLLSrc, AHBPreName_t AHB_Prescaler, APB1PreName_t APB1_Prescaler, APB2PreName_t APB2_Prescaler)
{
        //HSE
        #if ClkSrc == 0;

                //HSE_Crystal
            #if HSESRC == 0;
                RCC_CR |=(1U<<16); //Enable HSE
                RCC_CR &=~(1U<<18); // Disable BYP
                RCC_CFGR |=(1U<<0); // SYSCLK equal to HSE
                RCC_CFGR &=~(1U<<1);

                //HSE_RC
            #elif HSESRC == 1;
                RCC_CR |=(1U<<16); //Enable HSE
                RCC_CR |=(1U<<18); //Enable BYP
                RCC_CFGR |=(1U<<0); // SYSCLK equal to HSE
                RCC_CFGR &=~(1U<<1);

            #else


            #endif // HSESRC


		//HSI
		#elif ClkSrc == 1;

			RCC_CR |=(1U<<0); //Enable HSI
			RCC_CFGR &=~(1U<<0); // SYSCLK equal to HSI
			RCC_CFGR &=~(1U<<1);


		//PLL
		#elif ClkSrc == 2;

				//PLL_HSE
            #if PLLSrc == 0;
				RCC_CR |=(1U<<24); //Enable PLL
				RCC_CR |=(1U<<16); //Enable HSE
				RCC_PLLCFGR |=(1U<<22); //Select PLL source equal to HSE
				RCC_CFGR &=~(1U<<0); // SYSCLK equal to PLL
				RCC_CFGR |=(1U<<1);

				//PLL_HSI
            #elif PLLSrc == 1;
				RCC_CR |= (1U<<24); //Enable PLL
				RCC_CR |= (1U<<0); //Enable HSI
				RCC_PLLCFGR &=~(1U<<22); //Select PLL source equal to HSI
				RCC_CFGR &=~(1U<<0); // SYSCLK equal to PLL
				RCC_CFGR |=(1U<<1);

			#else
            #endif // PLLSrc

		#else

		#endif // ClkSrc


	//Task Prescalers

	/////////*************APB1***********/////////////


        #if APB1_Prescaler == ABP1_Pre1;
			RCC_CFGR &=~ (1U<<10) ;
			RCC_CFGR &=~ (1U<<11) ;
			RCC_CFGR &=~ (1U<<12) ;

		#elif APB1_Prescaler == ABP1_Pre2;
			RCC_CFGR &=~ (1U<<10) ;
			RCC_CFGR &=~ (1U<<11) ;
			RCC_CFGR |=  (1U<<12) ;

		#elif APB1_Prescaler == ABP1_Pre4;
			RCC_CFGR |=  (1U<<10) ;
			RCC_CFGR &=~ (1U<<11) ;
			RCC_CFGR |=  (1U<<12) ;

		#elif APB1_Prescaler == ABP1_Pre8;
			RCC_CFGR &=~ (1U<<10) ;
			RCC_CFGR |=  (1U<<11) ;
			RCC_CFGR |=  (1U<<12) ;

		#elif APB1_Prescaler == ABP1_Pre16;
			RCC_CFGR |=  (1U<<10) ;
			RCC_CFGR |=  (1U<<11) ;
			RCC_CFGR |=  (1U<<12) ;

		#else
		    //do nothing
        #endif // APB1_Prescaler

	/////////*************APB2***********/////////////

        #if APB2_Prescaler == ABP2_Pre1;
			RCC_CFGR &=~ (1U<<10) ;
			RCC_CFGR &=~ (1U<<11) ;
			RCC_CFGR &=~ (1U<<12) ;

        #elif APB2_Prescaler == ABP2_Pre2;
			RCC_CFGR &=~ (1U<<10) ;
			RCC_CFGR &=~ (1U<<11) ;
			RCC_CFGR |=  (1U<<12) ;

        #elif APB2_Prescaler == ABP2_Pre4;
			RCC_CFGR |=  (1U<<10) ;
			RCC_CFGR &=~ (1U<<11) ;
			RCC_CFGR |=  (1U<<12) ;

        #elif APB2_Prescaler == ABP2_Pre8;
			RCC_CFGR &=~ (1U<<10) ;
			RCC_CFGR |=  (1U<<11) ;
			RCC_CFGR |=  (1U<<12) ;

        #elif APB2_Prescaler == ABP2_Pre1+;
			RCC_CFGR |=  (1U<<10) ;
			RCC_CFGR |=  (1U<<11) ;
			RCC_CFGR |=  (1U<<12) ;

		#else
		    //do nothing
        #endif // APB2_Prescaler

	/////////*************AHB***********/////////////

        #if AHB_Prescaler == AHB_Pre1;
			RCC_CFGR &=~ (1U<<4) ;
			RCC_CFGR &=~ (1U<<5) ;
			RCC_CFGR &=~ (1U<<6) ;
			RCC_CFGR &=~ (1U<<7) ;

        #elif AHB_Prescaler == AHB_Pre2;
			RCC_CFGR &=~ (1U<<4) ;
			RCC_CFGR &=~ (1U<<5) ;
			RCC_CFGR &=~ (1U<<6) ;
			RCC_CFGR |=  (1U<<7) ;

        #elif AHB_Prescaler == AHB_Pre4;
			RCC_CFGR |=  (1U<<4) ;
			RCC_CFGR &=~ (1U<<5) ;
			RCC_CFGR &=~ (1U<<6) ;
			RCC_CFGR |=  (1U<<7) ;

        #elif AHB_Prescaler == AHB_Pre8;
			RCC_CFGR &=~ (1U<<4) ;
			RCC_CFGR |=  (1U<<5) ;
			RCC_CFGR &=~ (1U<<6) ;
			RCC_CFGR |=  (1U<<7) ;

        #elif AHB_Prescaler == AHB_Pre16;
			RCC_CFGR |=  (1U<<4) ;
			RCC_CFGR |=  (1U<<5) ;
			RCC_CFGR &=~ (1U<<6) ;
			RCC_CFGR |=  (1U<<7) ;

        #elif AHB_Prescaler == AHB_Pre64;
			RCC_CFGR &=~ (1U<<4) ;
			RCC_CFGR &=~ (1U<<5) ;
			RCC_CFGR |=  (1U<<6) ;
			RCC_CFGR |=  (1U<<7) ;

        #elif AHB_Prescaler == AHB_Pre128;
			RCC_CFGR |=  (1U<<4) ;
			RCC_CFGR &=~ (1U<<5) ;
			RCC_CFGR |=  (1U<<6) ;
			RCC_CFGR |=  (1U<<7) ;

        #elif AHB_Prescaler == AHB_Pre256;
			RCC_CFGR &=~ (1U<<4) ;
			RCC_CFGR |=  (1U<<5) ;
			RCC_CFGR |=  (1U<<6) ;
			RCC_CFGR |=  (1U<<7) ;

        #elif AHB_Prescaler == AHB_Pre512;
			RCC_CFGR |=  (1U<<4) ;
			RCC_CFGR |=  (1U<<5) ;
			RCC_CFGR |=  (1U<<6) ;
			RCC_CFGR |=  (1U<<7) ;

		#else
		    //do nothing
        #endif // AHB_Prescaler

}


void vRCC_EnPerClk(BusName_t BusName, uint8 PerName)
{

		//AHB1
		#if BusName == 0;
		    RCC_AHB1ENR |=(1U<<PerName); break;

		//AHB2
		#elif BusName == 1;
		    RCC_AHB2ENR |=(1U<<PerName); break;

		//AHB3
		#if BusName == 2;
		    RCC_AHB3ENR |=(1U<<PerName); break;

		//APB1
		#if BusName == 3;
		    RCC_APB1ENR |=(1U<<PerName); break;

		//APB2
		#if BusName == 4;
		    RCC_APB2ENR |=(1U<<PerName); break;

		#else
		    //do nothing
        #endif // BusName

}
