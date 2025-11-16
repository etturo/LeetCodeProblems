/*
 * @lc app=leetcode id=1513 lang=c
 *
 * [1513] Number of Substrings With Only 1s
 */
// @lc code=start

#define mod 1000000007

int numSub(char* s) {
	unsigned long long int i = 0;
	unsigned long long int sub_len;
	unsigned long long int count = 0;

	while(s[i] != '\0')
	{
		sub_len = 0;
		while(s[sub_len + i] == '1'){
			sub_len++;
		}
		count += (sub_len * (sub_len + 1) / 2) % mod;
		if(sub_len != 0)
			i += sub_len;
		else
			i++;
	}
	return (int)count;
}


// @lc code=end