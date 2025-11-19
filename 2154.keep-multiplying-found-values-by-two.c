/*
 * @lc app=leetcode id=2154 lang=c
 *
 * [2154] Keep Multiplying Found Values by Two
 */

#include <stdbool.h>
// @lc code=start
bool search(int *nums, int numsSize, int to_find){
	for(int i = 0; i < numsSize; i++){
		if(nums[i] == to_find)
			return true;
	}
	return false;
}

int findFinalValue(int* nums, int numsSize, int original) {
	if(search(nums, numsSize, original) == true)
		original = findFinalValue(nums, numsSize, original * 2);
	return original;
}


// @lc code=end