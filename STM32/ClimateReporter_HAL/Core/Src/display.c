/*
 * display.c
 *
 *  Created on: 4 Apr 2026
 *      Author: CallumBinns
 */
#include "stm32f4xx_hal.h"
#include "oledFont.h"
#include <stdint.h>
#include <string.h>
void displayInit(I2C_HandleTypeDef *hi2c) {
	__HAL_RCC_GPIOB_CLK_ENABLE();

	__HAL_RCC_I2C1_CLK_ENABLE();

	GPIO_InitTypeDef SDAPullUp = { 0 };

	SDAPullUp.Pin = GPIO_PIN_9;

	SDAPullUp.Mode = GPIO_MODE_AF_OD;

	SDAPullUp.Pull = GPIO_PULLUP;

	SDAPullUp.Alternate = GPIO_AF4_I2C1;

	HAL_GPIO_Init(GPIOB, &SDAPullUp);

	GPIO_InitTypeDef SCLPullUp = { 0 };

	SCLPullUp.Pin = GPIO_PIN_8;

	SCLPullUp.Mode = GPIO_MODE_AF_OD;

	SCLPullUp.Pull = GPIO_PULLUP;

	SCLPullUp.Alternate = GPIO_AF4_I2C1;

	HAL_GPIO_Init(GPIOB, &SCLPullUp);

	hi2c->Instance = I2C1;

	hi2c->Init.ClockSpeed = 100000;

	hi2c->Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;

	HAL_I2C_Init(hi2c);
}


void displayClear(I2C_HandleTypeDef *hi2c) {

	uint8_t initCommands[] = { 0x00, // Control Byte: "The following are commands"

			0xAE,       // Display OFF (Sleep Mode)

			0xD5, 0x80, // Set Display Clock Divide Ratio

			0xA8, 0x3F, // Set Multiplex Ratio (64 lines for 128x64)

			0xD3, 0x00, // Set Display Offset to 0

			0x40,       // Set Display Start Line to 0

			0x8D, 0x14, // Enable the internal charge pump (High Voltage)

			0x20, 0x00, // Set Memory Addressing Mode to Horizontal

			0x21, 0x00, 0x7F, // Explicitly set Column Address bounds (0 to 127)

			0x22, 0x00, 0x07, // Explicitly set Page Address bounds (0 to 7)

			0xA1,       // Set Segment Re-map (Flips screen horizontally)

			0xC8,     // Set COM Output Scan Direction (Flips screen vertically)

			0xDA, 0x12, // Set COM Pins Hardware Configuration

			0x81, 0x7F, // Set Contrast to default

			0xA4,       // Entire Display ON (Resume to RAM content)

			0xA6,       // Set Normal Display (Not inverted)

			0xAF        // Display ON (Wake Up)

			};

	HAL_I2C_Master_Transmit(hi2c, 0x78, initCommands, sizeof(initCommands), HAL_MAX_DELAY);       //Handle, Address, Data_Pointer, Size, Timeout

	uint8_t clearDisplay[1025] = { 0 }; //this already sets all data to zero

	clearDisplay[0] = 0x40; //set control byte

	HAL_I2C_Master_Transmit(hi2c, 0x78, clearDisplay, sizeof(clearDisplay), HAL_MAX_DELAY);
}



void stringToDisplayBytes(char input[], uint8_t* outputBuffer){
	stringToBytes(input,outputBuffer); //have removed this functionality from display to allow for tdd without hardware emulation
}

void writeTextToDisplay(I2C_HandleTypeDef *hi2c, char input[]){
	uint8_t outputBuffer[(strlen(input)*6)+1];
	stringToDisplayBytes(input,outputBuffer);
	HAL_I2C_Master_Transmit(hi2c, 0x78, outputBuffer, sizeof(outputBuffer), HAL_MAX_DELAY);
}

void setPage(I2C_HandleTypeDef *hi2c,uint8_t lowerBound,uint8_t upperBound){
	uint8_t pageCommand[4] = {0x00,0x22,lowerBound,upperBound};
	HAL_I2C_Master_Transmit(hi2c, 0x78, pageCommand, sizeof(pageCommand), HAL_MAX_DELAY);
}
void setColumns(I2C_HandleTypeDef *hi2c,uint8_t lowerBound,uint8_t upperBound){
	uint8_t columnCommand[4] = {0x00,0x21,lowerBound,upperBound};
	HAL_I2C_Master_Transmit(hi2c, 0x78, columnCommand, sizeof(columnCommand), HAL_MAX_DELAY);
}



