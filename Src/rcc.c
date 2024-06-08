/*
 * rcc.c
 *
 *  Created on: Jun 8, 2024
 *      Author: Nikolaos Grigoriadis
 *		Email : n.grigoriadis09@gmail.com
 *		Title : Embedded software engineer
 * 	 	Degree: BSc and MSc in computer science, university of Ioannina
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
	/*Set the reload value*/
	SysTick->LOAD = 16000 - 1; // Subtrack 1 because we count from 0.

	/*Set the initial value to 0*/
	SysTick->VAL = 0;

	/*Select internal clock source*/
	SysTick->CTRL |= SYSTICK_CLK_SRC;

	/*Enable the counter*/
	SysTick->CTRL |= SYSTICK_ENABLE;

	for (uint32_t i=0; i<ms; i++)
	{
        /*Wait until the count flag occurs*/
		while (!(SysTick->CTRL & SYSTICK_CNT_FLAG)) {}
	}

	/*Reset control register*/
	SysTick->CTRL = 0;
}


void delay_us(int us)
{
	/*SET THE reload value*/
	SysTick->LOAD = 16 - 1; // Subtrack by 1 because we count from 0.

	/*Set the initial value to 0*/
	SysTick->VAL = 0;

	/*Select internal clock source*/
	SysTick->CTRL |= SYSTICK_CLK_SRC;

	/*Enable the counter*/
	SysTick->CTRL |= SYSTICK_ENABLE;

	for (uint32_t i=0; i<us; i++)
	{
        /*Wait until the count flag occurs*/
		while (!(SysTick->CTRL & SYSTICK_CNT_FLAG)) {}
	}

	/*Reset control register*/
	SysTick->CTRL = 0;
}


