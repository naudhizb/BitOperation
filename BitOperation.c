/*
 * BitOperation.c
 *
 *  Created on: 2020. 10. 14.
 *      Author: mjlee2
 */



#include "BitOperation.h"

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

uint64_t BitOp_GetBitMaskWithOffset(uint32_t length, uint32_t offset){
	uint64_t bitmask = ~0;
	bitmask = bitmask << length;
	bitmask = ~bitmask;
	bitmask = bitmask << offset;
	return bitmask;
}

uint64_t BitOp_GetBitMask(uint32_t length){
	uint64_t bitmask = ~0;
	bitmask = bitmask << length;
	bitmask = ~bitmask;
	return bitmask;
}

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
