/*
 * bme280.c
 *
 *  Created on: 13 Apr 2026
 *      Author: CallumBinns
 */
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include "bme280_defs.h"

void bme280Init(I2C_HandleTypeDef *hi2c){
	uint8_t humControl = 0x01;
	uint8_t tempPressControl = 0x27;

	//write to humidity control to setup i2cHandle, bmeWriteAddr,HumidityControlMemAddr,wysiwyg,sets to oversampling 1x, number of bytes, timeout
	//oversampling is different to below, only first three bits of byte are used 00000001
	HAL_I2C_Mem_Write(hi2c, 0xEC, 0xF2, I2C_MEMADD_SIZE_8BIT, &humControl, 1, HAL_MAX_DELAY);
	//write to combined temp+pressure control to setup i2cHandle, bmeWriteAddr,HumidityControlMemAddr,wysiwyg,sets oversampling and energy use, number of bytes, timeout
	//oversampling+energy use byte 001(temp 1x)001(pressure 1x)11(normal power)
	HAL_I2C_Mem_Write(hi2c, 0xEC, 0xF4, I2C_MEMADD_SIZE_8BIT, &tempPressControl, 1, HAL_MAX_DELAY);

}


void bme280Read(I2C_HandleTypeDef *hi2c, uint8_t* readingBuffer){
	//reads measurement, starts at 0xF7 (press_msb) then iterates through press_lsb, press_xlsb, temp_msb, temp_lsb,temp_xlsb,hum_msb,hum_lsb
	HAL_I2C_Mem_Read(hi2c, 0xEC, 0xF7, I2C_MEMADD_SIZE_8BIT, readingBuffer, 8, HAL_MAX_DELAY);

}

void bme280Calibration(I2C_HandleTypeDef *hi2c, BME280_Calib_t *calib){
	uint8_t readingBuffer1[26];
	//Read first calibration block
	HAL_I2C_Mem_Read(hi2c, 0xEC, 0x88, I2C_MEMADD_SIZE_8BIT, readingBuffer1, 26, HAL_MAX_DELAY);
	calib->dig_T1 = (readingBuffer1[1] << 8) | readingBuffer1[0];
	calib->dig_T2 = (readingBuffer1[3] << 8) | readingBuffer1[2];
	calib->dig_T3 = (readingBuffer1[5] << 8) | readingBuffer1[4];
	calib->dig_P1 = (readingBuffer1[7] << 8) | readingBuffer1[6];
	calib->dig_P2 = (readingBuffer1[9] << 8) | readingBuffer1[8];
	calib->dig_P3 = (readingBuffer1[11] << 8) | readingBuffer1[10];
	calib->dig_P4 = (readingBuffer1[13] << 8) | readingBuffer1[12];
	calib->dig_P5 = (readingBuffer1[15] << 8) | readingBuffer1[14];
	calib->dig_P6 = (readingBuffer1[17] << 8) | readingBuffer1[16];
	calib->dig_P7 = (readingBuffer1[19] << 8) | readingBuffer1[18];
	calib->dig_P8 = (readingBuffer1[21] << 8) | readingBuffer1[20];
	calib->dig_P9 = (readingBuffer1[23] << 8) | readingBuffer1[22];
	calib->dig_H1 = readingBuffer1[25];


	//read second calibration block
	uint8_t readingBuffer2[7];
	HAL_I2C_Mem_Read(hi2c, 0xEC, 0xE1, I2C_MEMADD_SIZE_8BIT, readingBuffer2, 7, HAL_MAX_DELAY);
	calib->dig_H2 = (readingBuffer2[1] << 8) | readingBuffer2[0];
	calib->dig_H3 = readingBuffer2[2];
	calib->dig_H4 = (readingBuffer2[4] << 8) | readingBuffer2[3];
	calib->dig_H5 = (readingBuffer2[6] << 8) | readingBuffer2[5];
	calib->dig_H6 = readingBuffer2[6];


}

