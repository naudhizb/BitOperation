/**
 * @file BitOperation.c
 * @author naudhizb (naudhizb@gmail.com)
 * @brief this file contains bit operation functions.
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "BitOperation.h"

/**
 * @brief get bits with automatically shifted by mask LSB
 * 
 * @param data input data up to 64bit
 * @param mask mask data up to 64bit
 * @return uint64_t same as GitBits but it is automatically shifted value
 */
uint64_t BitOp_GetBitsWithShift(uint64_t data, uint64_t mask){
	uint64_t res = BitOp_GetBits(data, mask);
	int32_t offset = BitOp_GetLSBOffset(mask);
	if(0 < offset){
		return res >> offset;
	} else {
		// mask invalid
	}
	return 0;
}

/**
 * @brief get bitmask length of "length" but offseted with "offset"
 * 
 * @param length length of bitmask (e.g. length 3 --> 0b111)
 * @param offset offset of bitmask (3.g. length 3, offset 2 -->  0b11100) 
 * @return uint64_t value of return up to 64bits
 */
uint64_t BitOp_GetBitMaskWithOffset(uint32_t length, uint32_t offset){
	uint64_t bitmask = ~0;
	bitmask = bitmask << length;
	bitmask = ~bitmask;
	bitmask = bitmask << offset;
	return bitmask;
}

/**
 * @brief get bitmask length of "length"
 * 
 * @param length length of bitmask (e.g. length 3 --> 0b111)
 * @return uint64_t value of return up to 64bits
 */
uint64_t BitOp_GetBitMask(uint32_t length){
	uint64_t bitmask = ~0;
	bitmask = bitmask << length;
	bitmask = ~bitmask;
	return bitmask;
}

/**
 * @brief get offset of (activated) least significant bits
 * 
 * @param data input data up to 64bits
 * @return int32_t offset of first LSB Bit. if data is 0, return -1
 */
int32_t BitOp_GetLSBOffset(uint64_t data){
	int32_t res = -1;
	for(uint32_t i = 0; i < 64; i++){
		if(data & 0x1){
			res = i;
			break;
		}
		data >>= 1;
	}
	return res;
}

/**
 * @brief Change Endianess of Data(Swap bytes)
 * 
 * @param ptr start pointer of swap bytes
 * @param len length of swap bytes
 */
void BitOp_SwapBytes(uint8_t *ptr, uint32_t len){
	uint8_t tmp = 0;
	uint8_t *head = ptr;
	uint8_t *tail = ptr + len - 1;
	for(int32_t index = 0; index < len/2; index++){
		tmp = *head;
		*head = *tail;
		*tail = tmp;
		head++;
		tail--;
	}
}
