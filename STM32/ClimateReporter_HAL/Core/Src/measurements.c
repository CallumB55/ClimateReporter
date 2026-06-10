/*
 * measurements.c
 *
 *  Created on: 3 Jun 2026
 *      Author: CallumBinns
 */

#include "bme280_defs.h"
#include <stdint.h>

void formatMeasurements(BME280_Calib_t *data, uint8_t *rawBuffer,char *tempOut, char *pressOut, char *humOut){

    //using basically a copy paste of the bosch datasheet code as I am assuming it to be known good.
    //my TDD is on my integration of the below code, not the bosch code itself.
    int32_t t_fine;

    int32_t adc_T = (rawBuffer[3] << 12) | (rawBuffer[4] << 4) | (rawBuffer[5] >> 4);
    int32_t adc_P = (rawBuffer[0] << 12) | (rawBuffer[1] << 4) | (rawBuffer[2] >> 4);
    int32_t adc_H = (rawBuffer[6] << 8) | rawBuffer[7];

    // Returns temperature in DegC, resolution is 0.01 DegC. Output value of "5123" equals 51.23 DegC.
    // t_fine carries fine temperature as global value
    int32_t var1_t, var2_t, T;
    var1_t = ((((adc_T >> 3) - ((int32_t)data->dig_T1 << 1))) * ((int32_t)data->dig_T2)) >> 11;
    var2_t = (((((adc_T >> 4) - ((int32_t)data->dig_T1)) * ((adc_T >> 4) - ((int32_t)data->dig_T1))) >> 12) * ((int32_t)data->dig_T3)) >> 14;
    t_fine = var1_t + var2_t;
    T = (t_fine * 5 + 128) >> 8;

    // Returns pressure in Pa as unsigned 32 bit integer in Q24.8 format (24 integer bits and 8 fractional bits).
    // Output value of "24674867" represents 24674867/256 = 96386.2 Pa = 963.862 hPa
    int64_t var1_p, var2_p, p;
    var1_p = ((int64_t)t_fine) - 128000;
    var2_p = var1_p * var1_p * (int64_t)data->dig_P6;
    var2_p = var2_p + ((var1_p * (int64_t)data->dig_P5) << 17);
    var2_p = var2_p + (((int64_t)data->dig_P4) << 35);
    var1_p = ((var1_p * var1_p * (int64_t)data->dig_P3) >> 8) + ((var1_p * (int64_t)data->dig_P2) << 12);
    var1_p = (((((int64_t)1) << 47) + var1_p)) * ((int64_t)data->dig_P1) >> 33;

    if (var1_p == 0) {
        p = 0; // avoid exception caused by division by zero
    }
    else {
        p = 1048576 - adc_P;
        p = (((p << 31) - var2_p) * 3125) / var1_p;
        var1_p = (((int64_t)data->dig_P9) * (p >> 13) * (p >> 13)) >> 25;
        var2_p = (((int64_t)data->dig_P8) * p) >> 19;
        p = ((p + var1_p + var2_p) >> 8) + (((int64_t)data->dig_P7) << 4);
    }
    uint32_t P = (uint32_t)p;

    // Returns humidity in %RH as unsigned 32 bit integer in Q22.10 format (22 integer and 10 fractional bits).
    // Output value of "47445" represents 47445/1024 = 46.333 %RH
    int32_t v_x1_u32r;
    v_x1_u32r = (t_fine - ((int32_t)76800));
    v_x1_u32r = (((((adc_H << 14) - (((int32_t)data->dig_H4) << 20) - (((int32_t)data->dig_H5) * v_x1_u32r)) + ((int32_t)16384)) >> 15) * (((((((v_x1_u32r * ((int32_t)data->dig_H6)) >> 10) * (((v_x1_u32r * ((int32_t)data->dig_H3)) >> 11) + ((int32_t)32768))) >> 10) + ((int32_t)2097152)) * ((int32_t)data->dig_H2) + 8192) >> 14));
    v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((int32_t)data->dig_H1)) >> 4));
    v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
    v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
    uint32_t H = (uint32_t)(v_x1_u32r >> 12);


}


void tempRawToFormatted(int32_t *numericTempIn, char *tempOut){
	//not implemented
}

void pressRawToFormatted(int32_t *numericPressIn, char *pressOut){
	//not implemented
}

void humRawToFormatted(int32_t *numericHumIn, char *humOut){
	//not implemented
}


