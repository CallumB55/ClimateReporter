#include "gtest/gtest.h"
#include "pch.h"
extern "C" {
#include "measurements.h"
#include "bme280_defs.h"
}
//Temp: 2549, Press : 25705619, Hum : 0
BME280_Calib_t actualCalibData = {
    .dig_T1 = 28241,
    .dig_T2 = 26413,
    .dig_T3 = 50,
    .dig_P1 = 36083,
    .dig_P2 = -10589,
    .dig_P3 = 3024,
    .dig_P4 = 8535,
    .dig_P5 = -92,
    .dig_P6 = -7,
    .dig_P7 = 11700,
    .dig_P8 = -11800,
    .dig_P9 = 5000,
    .dig_H1 = 75,
    .dig_H2 = 373,
    .dig_H3 = 0,
    .dig_H4 = 293,
    .dig_H5 = 50,
    .dig_H6 = 30

};

uint8_t actualRead[8] = { 81,40,0,130,20,0,103,58 };
uint8_t blankRead[8];
BME280_Calib_t blankCalib;

//Temp: 2549, Press: 25705619, Hum: 44539

// 1. Correctly format a positive temperature
TEST(CorrectFormatTest, goodPositiveTemperatureInput) {
    char tempOut[12];
    char humOut[15];
    char pressOut[15];
    formatMeasurements(&actualCalibData, actualRead, tempOut, pressOut, humOut);

    EXPECT_STREQ(tempOut, "25.49C");
    EXPECT_TRUE(true);
}

TEST(CorrectFormatTest, good2DpTemperatureInput) {
    char tempOut[12];
    char humOut[15];
    char pressOut[15];
    uint8_t smallTempRead[8] = { 81,40,0,111,20,0,103,58 };
    formatMeasurements(&actualCalibData, smallTempRead, tempOut, pressOut, humOut);
    EXPECT_STREQ(tempOut, " 0.98C");
    EXPECT_TRUE(true);
}

TEST(CorrectFormatTest, good1DpTemperatureInput) {
    char tempOut[12];
    char humOut[15];
    char pressOut[15];
    uint8_t smallTempRead[8] = { 81,40,0,110,90,0,103,58 };
    formatMeasurements(&actualCalibData, smallTempRead, tempOut, pressOut, humOut);
    EXPECT_STREQ(tempOut, " 0.05C");
    EXPECT_TRUE(true);
}

TEST(CorrectFormatTest, goodNegative2DpTemperatureInput) {
    char tempOut[12];
    char humOut[15];
    char pressOut[15];
    uint8_t smallTempRead[8] = { 81,40,0,110,20,0,103,58 };
    formatMeasurements(&actualCalibData, smallTempRead, tempOut, pressOut, humOut);
    EXPECT_STREQ(tempOut, "-0.31C");
    EXPECT_TRUE(true);
}

// 2. Correctly format a negative temperature
TEST(CorrectFormatTest, goodNegativeTemperatureInput) {
    uint8_t negativeTempRead[8] = { 81,40,0,100,20,0,103,58 };
    char tempOut[12];
    char humOut[15];
    char pressOut[15];
    formatMeasurements(&actualCalibData, negativeTempRead, tempOut, pressOut, humOut);

    EXPECT_STREQ(tempOut, "-13.20C");
    EXPECT_TRUE(true);
}

// 3. Correctly format pressure
TEST(CorrectFormatTest, goodPressureInput) {
    char tempOut[12];
    char humOut[15];
    char pressOut[15];
    formatMeasurements(&actualCalibData, actualRead, tempOut, pressOut, humOut);
    EXPECT_STREQ(pressOut, "1004.125hPa");
    EXPECT_TRUE(true);
}

// 4. Correctly format humidity
TEST(CorrectFormatTest, goodHumidityInput) {
    char tempOut[12];
    char humOut[15];
    char pressOut[15];
    formatMeasurements(&actualCalibData, actualRead, tempOut, pressOut, humOut);
    EXPECT_STREQ(humOut, "43.49%RH");
    EXPECT_TRUE(true);
}


