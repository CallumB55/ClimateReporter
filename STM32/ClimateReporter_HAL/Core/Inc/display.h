/*
 * display.h
 *
 *  Created on: 4 Apr 2026
 *      Author: CallumBinns
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_
#include "stm32f4xx_hal.h"
#include <stdint.h>
void displayInit(I2C_HandleTypeDef *hi2c);
void displayClear(I2C_HandleTypeDef *hi2c);
void stringToDisplayBytes(char input[], uint8_t* outputBuffer);
void writeTextToDisplay(I2C_HandleTypeDef *hi2c, char input[]);
void setPage(I2C_HandleTypeDef *hi2c,uint8_t lowerBound,uint8_t upperBound);
void setColumns(I2C_HandleTypeDef *hi2c,uint8_t lowerBound,uint8_t upperBound);


#endif /* INC_DISPLAY_H_ */
