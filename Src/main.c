/*
 * main.c
 *
 *  Created on: Jun 8, 2024
 *      Author: Nikolaos Grigoriadis
 *		Email : n.grigoriadis09@gmail.com
 *		Title : Embedded software engineer
 * 	 	Degree: BSc and MSc in computer science, university of Ioannina
 */

#include "stm32l0xx.h"
#include "stm32l053xx.h"
#include "stdio.h"
#include "rcc.h"
#include "uart.h"

/**
 * @brief Retargeting printf
 */
int __io_putchar(int ch)
{
	uart_transmit_byte(ch);
	return ch;
}

int main()
{
    /*Initialize system clock to 16MHz*/
	init_system();

	/*Initialize USART2 peripheral*/
	uart2_init();


	while (1)
	{

	}

	return 1;
}
