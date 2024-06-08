/*
 * rcc.h
 *
 *  Created on: Jun 8, 2024
 *      Author: Nikolaos Grigoriadis
 *		Email : n.grigoriadis09@gmail.com
 *		Title : Embedded software engineer
 * 	 	Degree: BSc and MSc in computer science, university of Ioannina
 */

#ifndef RCC_H_
#define RCC_H_

#include "stm32l0xx.h"
#include "stm32l053xx.h"

#define SYSTICK_ENABLE    (1U<<0)
#define SYSTICK_CNT_FLAG  (1U<<16)
#define SYSTICK_CLK_SRC   (1U<<2)


/**
 * @brief Setting the internal clock to HSI16. (16MHz).
 * @retval None
 */
void init_system(void);

/**
 * @brief Use SysTick timer to create delay in milliseconds.
 */
void delay_ms(int ms);

/**
 * @brief Use SysTick timer to create delay in microseconds.
 */
void delay_us(int us);

#endif /* RCC_H_ */
