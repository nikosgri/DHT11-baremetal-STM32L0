/*
 * dht11.c
 *
 *  Created on: Jun 8, 2024
 *      Author: Nikolaos Grigoriadis
 *      Email : n.grigoriadis09@gmail.com
 *      Title : Embedded software engineer
 *      Degree: BSc and MSc in computer science, university of Ioannina
 */


#include "dht11.h"

void DHT11_start_signal(void) {
    /* Set the pin as output for at least 20ms */
    GPIOB->MODER |= GPIO_MODER_MODE0_0;
    GPIOB->MODER &= ~GPIO_MODER_MODE0_1;

    /* Drive the pin low at least 18ms */
    GPIOB->ODR &= ~GPIO_ODR_OD0;

    delay_ms(18);

    /* Release the pin by setting it as input mode */
    GPIOB->MODER &= ~GPIO_MODER_MODE0_0;
    GPIOB->MODER &= ~GPIO_MODER_MODE0_1;
}

DHT_response_t DHT11_response(void) {
    DHT_response_t response = DHT_FAIL;

    /* Wait for DHT11 response */
    delay_us(40);

    /* Read the input pin */
    if (!(GPIOB->IDR & (1U << 0))) {
        /* Wait for DHT preparation */
        delay_us(80);

        /* Read the pin again */
        if ((GPIOB->IDR & (1U << 0))) {
            /* Valid response sequence */
            response = DHT_OK;
        } else {
            /* Wrong response sequence */
            response = DHT_FAIL;
        }
    }

    /* Wait until the DHT drives the pin low */
    while ((GPIOB->IDR & (1U << 0))) {}

    return response;
}

uint8_t DHT11_read_sensor(void) {
    uint8_t data = 0;

    for (uint8_t byte = 0; byte < 8; byte++) {
        /* Wait for the sensor to drive the pin high */
        while (!(GPIOB->IDR & (1U << 0))) {}

        /* Delay for 40us */
        delay_us(40);

        if (!(GPIOB->IDR & (1U << 0))) {
            /* Set 0 bit to the appropriate position of the byte */
            data &= ~(1 << (7 - byte));
        } else {
            /* Set 1 bit to the appropriate position of the byte */
            data |= (1 << (7 - byte));
        }

        /* Wait for the sensor to drive the pin low */
        while (GPIOB->IDR & (1U << 0)) {}
    }

    return data;
}

void DHT_get_data(float *temperature, float *humidity) {
    uint8_t Rh_byte1 = DHT11_read_sensor();
    uint8_t Rh_byte2 = DHT11_read_sensor();
    uint8_t Temp_byte1 = DHT11_read_sensor();
    uint8_t Temp_byte2 = DHT11_read_sensor();
    uint8_t SUM = DHT11_read_sensor();

    /* Convert to real values */
    *humidity = (float)Rh_byte1;
    *temperature = (float)Temp_byte1;

    /* Validate checksum */
    uint8_t checksum = Rh_byte1 + Rh_byte2 + Temp_byte1 + Temp_byte2;
    if (checksum != SUM) {
        printf("Checksum validation failed.\r\n");
    }

    /* Print raw data for debugging */
    printf("Raw data: Rh_byte1=%u, Rh_byte2=%u, Temp_byte1=%u, Temp_byte2=%u, SUM=%u\r\n",
           Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2, SUM);
}
