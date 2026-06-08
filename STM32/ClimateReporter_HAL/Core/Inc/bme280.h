/*
 * bme280.h
 *
 *  Created on: 13 Apr 2026
 *      Author: CallumBinns
 */

#ifndef INC_BME280_H_
#define INC_BME280_H_
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include "bme280_defs.h"



void bme280Init(I2C_HandleTypeDef *hi2c);
void bme280Read(I2C_HandleTypeDef *hi2c, uint8_t* readingBuffer);
void bme280Calibration(I2C_HandleTypeDef *hi2c, uint8_t* readingBuffer);

#endif /* INC_BME280_H_ */
