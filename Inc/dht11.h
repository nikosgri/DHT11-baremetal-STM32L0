/*
 * dht11.h
 *
 *  Created on: Jun 8, 2024
 *      Author: Nikolaos Grigoriadis
 *		Email : n.grigoriadis09@gmail.com
 *		Title : Embedded software engineer
 * 	 	Degree: BSc and MSc in computer science, university of Ioannina
 */

#ifndef DHT11_H_
#define DHT11_H_

#include "stm32l0xx.h"
#include "stm32l053xx.h"
#include "rcc.h"


/**
 * brief Valid & Error codes
 */
typedef enum
{
	DHT_OK   = 0,
    DHT_FAIL = -1
}DHT_response_t;


/**
 * brief This function sends a start singal to the DTH11 peripheral in order to wake it up from power consumption mode.
 * PB0 pin is chosen to be the input signal pin for receiving data from the sensor.
 */
void DHT11_start_signal(void);

/**
 * @brief This function detects if the sensor is able to send data or not.
 * @retval DHT_OK if sensor is ready, DHT_FAIL otherwise.
 */
DHT_response_t DHT11_response(void);

/**
 * @bried This function reads the sensor.
 * @retval A byte.
 */
uint8_t DHT11_read_sensor(void);

/**
 * @brief This function sets temperature and humidity data.
 * @param temperature: Temperature parameter for storing data from the sensor.
 * @param humidity: Humidity parameter for storing data from the sensor.
 * @retval None.
 */
void DHT_get_data(float *temperature, float *humidity);

#endif /* DHT11_H_ */
