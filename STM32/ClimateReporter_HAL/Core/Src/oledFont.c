/*
 * oledFont.c
 *
 *  Created on: 4 Apr 2026
 *      Author: CallumBinns
 */
#include <stdint.h>
#include <string.h>
#include "oledFont.h"
void stringToBytes(char input[], uint8_t* outputBuffer){
	//determine length of output array
	uint8_t len = strlen(input);



	//int to keep track of actual array index
	uint8_t index = 0;

	//loop to grab char bytes and append them to list with spacing

	//inner loop to insert 5 character bytes to the array
}

uint8_t* charToDisplayByte(char input){
	//populate the 2D array
	//if else validation and return logic
	//return type is fine to be that pointer because it's pointing to the flash that won't get deallocated

}
