#include <stdlib.h>

void backtrack(int* nums, int numsSize, int* visited, 
               int* curr, int currSize,
               int** result, int* returnSize, int** returnColumnSizes)
{
    if (currSize == numsSize) {
        int* perm = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++)
            perm[i] = curr[i];
        
        result[*returnSize] = perm;
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        // Skip used elements
        if (visited[i]) continue;

        // Skip duplicates:
        // If current element == previous element and previous hasn't been used in this position
        if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

        visited[i] = 1;
        curr[currSize] = nums[i];

        backtrack(nums, numsSize, visited, curr, currSize + 1,
                  result, returnSize, returnColumnSizes);

        visited[i] = 0;
    }
}

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    // Sort to bring duplicates next to each other
    qsort(nums, numsSize, sizeof(int), cmpInt);

    int maxPerms = 720; // upper bound for n<=6 on LeetCode
    int** result = (int**)malloc(sizeof(int*) * maxPerms);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxPerms);

    int* curr = (int*)malloc(sizeof(int) * numsSize);
    int* visited = (int*)calloc(numsSize, sizeof(int));

    backtrack(nums, numsSize, visited, curr, 0,
              result, returnSize, returnColumnSizes);

    free(curr);
    free(visited);

    return result;
}

