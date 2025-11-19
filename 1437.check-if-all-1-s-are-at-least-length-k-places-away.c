/*
 * @lc app=leetcode id=1437 lang=c
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
 */

#include <stdbool.h>

// @lc code=start
bool	kLengthApart(int* nums, int numsSize, int k){
	int	i = 0;
	int	last_one = -k - 1;

	while (i < numsSize) {
		if(nums[i] == 1) {
			if(i - last_one <= k)
				return false;
			last_one = i;
		}
		i++;
	}
	return (true);
}

// @lc code=end

