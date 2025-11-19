/*
 * @lc app=leetcode id=3542 lang=c
 *
 * [3542] Minimum Operations to Convert All Elements to Zero
 */

#include <stdio.h>
// @lc code=start

typedef struct Stack{
	int size;
	int TOS;
	int *buffer;
} stack;

void init(stack *stack, int size){
	stack->TOS = 0;
	stack->size = size;
	stack->buffer = (int *)malloc(sizeof(int)*size);
	stack->buffer[stack->TOS] = 0;
}

void push(stack *stack, int value){
	stack->TOS++;
	(stack->buffer)[stack->TOS] = value;
}

void pop(stack *stack){
	if(stack->TOS > 0)
	stack->TOS--;
}

int get_top_value(stack *stack){
	return (stack->buffer[stack->TOS]);
}

int minOperations(int* nums, int numsSize) {
	stack stack;
	int count_operations = 0;

	init(&stack, numsSize + 1);
	for(int i = 0; i < numsSize; i++){
		while(get_top_value(&stack) > nums[i] && stack.TOS > 0)
			pop(&stack);
		if(nums[i] == 0)
			continue;
		if(get_top_value(&stack) < nums[i] || stack.TOS == 0){
			count_operations++;
			push(&stack, nums[i]);
		}
	}
	free(stack.buffer);
	return count_operations;
}

// @lc code=end	