/*
 * @lc app=leetcode id=3234 lang=c
 *
 * [3234] Count the Number of Substrings With Dominant Ones
 */
// @lc code=start

#include <string.h>
#include <math.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int numberOfSubstrings(char* s) {
	int len = strlen(s);
	int *pref0 = malloc(len * sizeof(int));
	int *pref1 = malloc(len * sizeof(int));
	int count0 = 0;
	int count1 = 0;
	int skip = 0;
	int count = 0;

	pref0[0] = (s[0] == '0');
	pref1[0] = (s[0] == '1');
	for(int i = 1; i < len; i++){
		pref0[i] = pref0[i - 1] + (s[i] == '0');
		pref1[i] = pref1[i - 1] + (s[i] == '1');
	}

	for(int i = 0; i < len; i++){
		for(int j = i; j < len;){
			count0 = pref0[j] - (i ? pref0[i - 1] : 0);
			count1 = pref1[j] - (i ? pref1[i - 1] : 0);

			if(count1 >= (count0 * count0)){
				skip = max((int)sqrt(count1) - count0, 1);
				count += min(skip, (len - j));
			}
			else {
				skip = (count0 * count0) - count1;
			}
			j += skip;
		}
	}
	free(pref0);
	free(pref1);
	return (count);
}


// @lc code=end

/*
REVIEW OF THE CODE:

variabily overview:
->len:					is the length of the strign.
->pref0:				is the string wich counts the number of zeros in a precise index.
->pref1:				is the string wich counts the number of ones in a precise index.

example: string "110010"
Position:	0  1  2  3  4  5
String:		1  1  0  0  1  0
pref0:		0  0  1  2  2  3
pref1:		1  2  2  2  3  3

->count0:				a variable needed to count the number of zeros in a taken substring.
->count1:				a variable needed to count the number of unos in a taken substring.

This two varaibles are calculated by the difference of the relative pref# array in the substring starting position
and the end of the substring.

->skip					this is the variable that is needed to do jump in the array without checking every
						single character of a substring, because we can know how much we can skip based on
						the manteined status of dominant or non-dominant.

->count					this variable is the total number of the dominant substrings that fit in the string.

This is calculeted with this reasoning:
Assuming that we have foung a valid substring we would like to know how many s[i + 1], s[i + 2], ... , s[i + k]
indexes we can skip without losing the dominant substring.
So we have the condition:
	ones >= zeros^2
So in the worst case scenario we have all zeros, so k-zeros:
	ones >= (zeros + k)^2
So if we want to know how much we can surely skip we have:
	sqrt(ones) >= zeros + k
That become:
	k <= sqrt(ones) - zeros

In code became:
	skip = max((int)sqrt(count1) - count0, 1);

because we want to be sure that at least one we can procede.

So the count is:
	count += min(skip, len - j);

because we don't want to go beyond the length of the string, in this case "len - j" rapresent the number of character
remained in the string, if our substring length's calculated is larger than the remaining character is obvius that
we can take all the character remaining because we are sure that those doesn't change the status of dominant substring
*/