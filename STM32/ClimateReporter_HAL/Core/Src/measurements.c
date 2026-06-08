/*
 * measurements.c
 *
 *  Created on: 3 Jun 2026
 *      Author: CallumBinns
 */

#include "bme280_defs.h"
#include <stdint.h>

void formatMeasurements(BME280_Calib_t *data, uint8_t *rawBuffer,char *tempOut, char *pressOut, char *humOut){
	//uint16_t tempMSB;//keeping these for later
	//uint16_t tempLSB;
	//uint16_t tempXLSB;
	//uint16_t pressMSB;
	//uint16_t pressLSB;
	//uint16_t pressXLSB;
	//uint16_t humMSB;
	//uint16_t humLSB;

	//not implemented
}

void tempCalcRawValue(BME280_Calib_t *data, uint8_t *rawBuffer,uint32_t *numericTempOut){
	//not implemented
}

void pressCalcRawValue(BME280_Calib_t *data, uint8_t *rawBuffer,uint32_t *numericPressOut){
	//not implemented
}

void humCalcRawValue(BME280_Calib_t *data, uint8_t *rawBuffer,uint32_t *numericHumOut){
	//not implemented
}

void tempRawToFormatted(uint32_t *numericTempIn, char *tempOut){
	//not implemented
}

void pressRawToFormatted(uint32_t *numericPressIn, char *pressOut){
	//not implemented
}

void humRawToFormatted(uint32_t *numericHumIn, char *humOut){
	//not implemented
}


