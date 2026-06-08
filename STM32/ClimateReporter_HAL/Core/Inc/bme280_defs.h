/*
 * bme280_defs.h
 *
 *  Created on: 8 Jun 2026
 *      Author: CallumBinns
 */

#ifndef INC_BME280_DEFS_H_
#define INC_BME280_DEFS_H_

#include <stdint.h>
//abstracted the calibration struct out of the bme280 class for the purpose of my testing proj
typedef struct {
	uint16_t dig_T1;
	int16_t dig_T2;
	int16_t dig_T3;
	uint16_t dig_P1;
	int16_t dig_P2;
	int16_t dig_P3;
	int16_t dig_P4;
	int16_t dig_P5;
	int16_t dig_P6;
	int16_t dig_P7;
	int16_t dig_P8;
	int16_t dig_P9;
	uint8_t dig_H1;
	int16_t dig_H2;
	uint8_t dig_H3;
	uint16_t dig_H4;
	uint16_t dig_H5;
	int8_t dig_H6;


} BME280_Calib_t;


#endif /* INC_BME280_DEFS_H_ */
