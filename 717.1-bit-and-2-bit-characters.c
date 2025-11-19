/*
 * @lc app=leetcode id=717 lang=c
 *
 * [717] 1-bit and 2-bit Characters
 */

#include <stdbool.h>

// @lc code=start
bool isOneBitCharacter(int* bits, int bitsSize) {
	int i = 0;

	while(i < bitsSize-1){
		i += bits[i] + 1;
	}
	return i == bitsSize-1;
}

// @lc code=end

