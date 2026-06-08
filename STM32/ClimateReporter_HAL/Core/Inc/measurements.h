/*
 * measurements.h
 *
 *  Created on: 27 May 2026
 *      Author: CallumBinns
 */

#ifndef INC_MEASUREMENTS_H_
#define INC_MEASUREMENTS_H_
#include <stdint.h>
#include "bme280_defs.h"

void formatMeasurements(BME280_Calib_t *data, uint8_t *rawBuffer,char *tempOut, char *pressOut, char *humOut);


#endif /* INC_MEASUREMENTS_H_ */
