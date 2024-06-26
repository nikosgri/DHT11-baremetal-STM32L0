/*
 * rcc.c
 *
 *  Created on: Jun 8, 2024
 *      Author: Nikolaos Grigoriadis
 *      Email : n.grigoriadis09@gmail.com
 *      Title : Embedded software engineer
 *      Degree: BSc and MSc in computer science, university of Ioannina
 */

#include "rcc.h"

void init_system(void)
{
     /*Enable high speed internal clock HSI16*/
     RCC->CR |= RCC_CR_HSION;

     /*Wait until internal high speed clock is ready*/
     while (RCC->CR & RCC_CR_HSIRDY) {}

     /*Do not devide the HSI*/
     RCC->CR &= ~RCC_CR_HSIDIVEN;

     /*Select microcontroller output clock*/
     MODIFY_REG(RCC->CFGR, RCC_CFGR_MCOSEL, (0x02 << RCC_CFGR_MCOSEL_Pos));

     /*Select HSI16 as system clock*/
     MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, (0x01 << RCC_CFGR_SW_Pos));

     /*Wait until HSI16 becomes system clock*/
     while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI) {}

     /*Update system core clock*/
     SystemCoreClockUpdate();
}


void delay_ms(int ms)
{
    SysTick->LOAD = 16000 - 1; // 16 MHz / 1000 = 16000 for 1 ms delay
    SysTick->VAL = 0;
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    for (uint32_t i = 0; i < ms; i++)
    {
        while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)) {}
    }

    SysTick->CTRL = 0;
}

void delay_us(int us)
{
    SysTick->LOAD = 16 - 1; // 16 MHz / 1000000 = 16 for 1 us delay
    SysTick->VAL = 0;
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    for (uint32_t i = 0; i < us; i++)
    {
        while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)) {}
    }

    SysTick->CTRL = 0;
}


