/*
 * measurements.c
 *
 *  Created on: 3 Jun 2026
 *      Author: CallumBinns
 */

#include "bme280.h"

void formatMeasurements(BME280_Mem_t *data, uint8_t *rawBuffer,char *tempOut, char *pressOut, char *humOut){
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

void tempCalcRawValue(BME280_Mem_t *data, uint8_t *rawBuffer,float *numericTempOut){
	//not implemented
}

void pressCalcRawValue(BME280_Mem_t *data, uint8_t *rawBuffer,float *numericPressOut){
	//not implemented
}

void humCalcRawValue(BME280_Mem_t *data, uint8_t *rawBuffer,float *numericHumOut){
	//not implemented
}


