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

/**
 * @brief Setting the internal clock to HSI16. (16MHz).
 * @retval None
 */
void init_system(void);

#endif /* RCC_H_ */
