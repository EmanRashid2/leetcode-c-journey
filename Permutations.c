#include <stdlib.h>

void backtrack(int* nums, int numsSize, int start, 
               int** result, int* returnSize, int** returnColumnSizes) 
{
    // If we placed all numbers, store the permutation
    if (start == numsSize) {
        int* perm = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++)
            perm[i] = nums[i];

        result[*returnSize] = perm;
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    // Generate permutations by swapping
    for (int i = start; i < numsSize; i++) {
        // swap
        int temp = nums[start];
        nums[start] = nums[i];
        nums[i] = temp;

        backtrack(nu

