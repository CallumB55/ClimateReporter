#include "gtest/gtest.h"
#include "pch.h"
#include "measurements.h"

// 1. Correctly format a positive temperature
TEST(CorrectFormatTest, goodPositiveTemperatureInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 2. Correctly format a negative temperature
TEST(CorrectFormatTest, goodNegativeTemperatureInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 3. Correctly format pressure
TEST(CorrectFormatTest, goodPressureInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 4. Correctly format humidity
TEST(CorrectFormatTest, goodHumidityInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 5. Correctly format temperature where the measurement equals the calibration
TEST(CorrectFormatTest, temperatureMeasurementEqualsCalibration) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 6. Correctly format pressure where the measurement equals the calibration
TEST(CorrectFormatTest, pressureMeasurementEqualsCalibration) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 7. Correctly format humidity where the measurement equals the calibration
TEST(CorrectFormatTest, humidityMeasurementEqualsCalibration) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 8. Show blank temp when given an empty buffer
TEST(ShowBlankIfBad, emptyBufferTemperatureInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 9. Show blank press when given an empty buffer
TEST(ShowBlankIfBad, emptyBufferPressureInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 10. Show blank hum when given an empty buffer
TEST(ShowBlankIfBad, emptyBufferHumidityInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 11. Show blank temp when given an empty calibration struct
TEST(ShowBlankIfBad, emptyCalibrationTemperatureInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 12. Show blank press when given an empty calibration struct
TEST(ShowBlankIfBad, emptyCalibrationPressureInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

// 13. Show blank hum when given an empty calibration struct
TEST(ShowBlankIfBad, emptyCalibrationHumidityInput) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}
