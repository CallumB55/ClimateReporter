#include "pch.h"
#include <stdint.h>

extern "C" {
#include "oledFont.h" 
}

// Set your specific I2C display data control byte here
#define CONTROL_BYTE 0x40

TEST(FontRendererTest, ConvertsSingleCharToCorrectHexBytes) {
    uint8_t buffer[7] = { 0 };
    char testString[] = "A";

    stringToBytes(testString, buffer);

    EXPECT_EQ(buffer[0], CONTROL_BYTE);
    EXPECT_EQ(buffer[1], 0x7E);
    EXPECT_EQ(buffer[2], 0x11);
    EXPECT_EQ(buffer[3], 0x11);
    EXPECT_EQ(buffer[4], 0x11);
    EXPECT_EQ(buffer[5], 0x7E);
    EXPECT_EQ(buffer[6], 0x00);
}

TEST(FontRendererTest, ConvertsMultipleCharacters) {
    uint8_t buffer[19] = { 0 };
    char testString[] = "ABC";

    stringToBytes(testString, buffer);

    EXPECT_EQ(buffer[0], CONTROL_BYTE);

    EXPECT_EQ(buffer[1], 0x7E);
    EXPECT_EQ(buffer[2], 0x11);
    EXPECT_EQ(buffer[3], 0x11);
    EXPECT_EQ(buffer[4], 0x11);
    EXPECT_EQ(buffer[5], 0x7E);
    EXPECT_EQ(buffer[6], 0x00);

    EXPECT_EQ(buffer[7], 0x7F);
    EXPECT_EQ(buffer[8], 0x49);
    EXPECT_EQ(buffer[9], 0x49);
    EXPECT_EQ(buffer[10], 0x49);
    EXPECT_EQ(buffer[11], 0x36);
    EXPECT_EQ(buffer[12], 0x00);

    EXPECT_EQ(buffer[13], 0x3E);
    EXPECT_EQ(buffer[14], 0x41);
    EXPECT_EQ(buffer[15], 0x41);
    EXPECT_EQ(buffer[16], 0x41);
    EXPECT_EQ(buffer[17], 0x22);
    EXPECT_EQ(buffer[18], 0x00);
}


TEST(FontRendererTest, HandlesEmptyString) {
    uint8_t buffer[7] = { CONTROL_BYTE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }; //default data to check it remains unchanged.
    char testString[] = "";

    stringToBytes(testString, buffer);

    EXPECT_EQ(buffer[0], CONTROL_BYTE);

    //should be the same as before
    for (int i = 1; i < 7; i++) {
        EXPECT_EQ(buffer[i], 0xFF);
    }
}


TEST(FontRendererTest, HandlesSpaceCharacter) {
    uint8_t buffer[7] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    char testString[] = " ";

    stringToBytes(testString, buffer);

    EXPECT_EQ(buffer[0], CONTROL_BYTE);

    // All pages should be blank
    for (int i = 1; i < 7; i++) {
        EXPECT_EQ(buffer[i], 0x00);
    }
}


TEST(FontRendererTest, HandlesUnsupportedCharacters) {
    uint8_t buffer[7] = { 0 };
    // highest ascii value accepted is 122, this is 123
    char testString[] = "{";

    stringToBytes(testString, buffer);

    EXPECT_EQ(buffer[0], CONTROL_BYTE);
    //create negative space x
    EXPECT_EQ(buffer[1], 0x3E);
    EXPECT_EQ(buffer[2], 0x49);
    EXPECT_EQ(buffer[3], 0x77);
    EXPECT_EQ(buffer[4], 0x49);
    EXPECT_EQ(buffer[5], 0x3E);
    EXPECT_EQ(buffer[6], 0x00);
}

TEST(FontRendererTest, HandlesHighestSupportedAscii) {
    uint8_t buffer[7] = { 0 };
    // highest ascii value accepted is 122, this is 122
    char testString[] = "z";

    stringToBytes(testString, buffer);

    EXPECT_EQ(buffer[0], CONTROL_BYTE);
    //create negative space x
    EXPECT_EQ(buffer[1], 0x44);
    EXPECT_EQ(buffer[2], 0x64);
    EXPECT_EQ(buffer[3], 0x54);
    EXPECT_EQ(buffer[4], 0x4C);
    EXPECT_EQ(buffer[5], 0x44);
    EXPECT_EQ(buffer[6], 0x00);
}