/*
 * @lc app=leetcode id=2536 lang=c
 *
 * [2536] Increment Submatrices by One
 */

#include <stddef.h>

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes) {
	//creating the matrix
	int **mat = malloc(sizeof(int *) * n);
	for(int i = 0; i < n; i++){
		mat[i] = malloc(sizeof(int) * n);
	}
	//filling the matrix
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = 0;

	//adding to the submatrix
	for(int k = 0; k < queriesSize; k++){
		int row1	= queries[k][0];
		int col1	= queries[k][1];
		int row2	= queries[k][2];
		int col2	= queries[k][3];

		mat[row1][col1]++;
		if(col2 + 1 < n)
			mat[row1][col2+ 1 ]--;
		if(row2 + 1 < n)
			mat[row2 + 1][col1]--;
		if(row2 + 1 < n && col2 + 1 < n)
			mat[row2 + 1][col2 + 1]++;
	}

	//calculating the cumulative sum in row
	for(int i = 0; i < n; i++)
		for(int j = 1; j < n; j++)
			mat[i][j] += mat[i][j-1];


	//calculating the cumulative sum in columns
	for(int i = 1; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] += mat[i-1][j];

	//setting all the arguments
	*returnSize = n;
	*returnColumnSizes = malloc(n * sizeof(int));
	for(int i = 0; i < *returnSize; i++)
		(*returnColumnSizes)[i] = n;
	//returning the matrix
	return mat;
}
// @lc code=end

 

/*
EXPLANATION:
beginning with an example:
Query: [1, 1, 2, 2]

first step:		identifieng the angles of the submatrix and we will obtain this matrix:

[0,  0,  0,  0]
[0, +1,  0, -1]
[0,  0,  0,  0]
[0, -1,  0, +1]


				and this is the piece of code that do this:

34.		 mat[row1][col1]++;
		if(col2 + 1 < n)
			mat[row1][col2+ 1 ]--;
		if(row2 + 1 < n)
			mat[row2 + 1][col1]--;
		if(row2 + 1 < n && col2 + 1 < n)
40.			mat[row2 + 1][col2 + 1]++;


second step:	now we can add the left column to the right's ones so we press the side to the actual border of the submatrix
				and adding one to the first and last rows.

44.		for(int i = 0; i < n; i++)
			for(int j = 1; j < n; j++)
46.				mat[i][j] += mat[i][j-1];

third step:		now we are in this situation:

[0,  0,  0,  0]
[0,  1,  1,  0]
[0,  0,  0,  0]
[0, -1, -1,  0]

				so we have completed the first row and adding the firsts row to the immediately after ones, we can complete the submatrix and
				set to zero the last row


50.		for(int i = 1; i < n; i++)
				for(int j = 0; j < n; j++)
52.					mat[i][j] += mat[i-1][j];

				and we will have, finally, this matrix:

[0, 0, 0, 0]
[0, 1, 1, 0]
[0, 1, 1, 0]
[0, 0, 0, 0]

*/