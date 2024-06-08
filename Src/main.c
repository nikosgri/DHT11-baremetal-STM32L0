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
#include "dht11.h"

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
	float temperature = 0.0, humidity=0.0;
	DHT_response_t res = DHT_FAIL;

    /*Initialize system clock to 16MHz*/
    init_system();

    /*Initialize USART2 peripheral*/
    uart2_init();

    /*Enable clock access to GPIO port B*/
	RCC->IOPENR |= RCC_IOPENR_GPIOBEN;


    while (1)
    {
    	/*Initiate communication*/
    	DHT11_start_signal();

    	/*Check the response from the sensor*/
    	res = DHT11_response();

    	if (res == DHT_FAIL)
    	{
    		/*FAIL*/
    		printf("Error, DHT11 sensor is can't communicate, try again\r\n");
    	} else if (res == DHT_OK)
    	{
    		/*SUCCESS*/
    		DHT_get_data(&temperature, &humidity);
			printf("Temperature: %f\r\n", temperature);
			printf("Humidity: %f\r\n", humidity);

    	}

    	/*Delay one second*/
    	delay_ms(1000);
    }

    return 1;
}
