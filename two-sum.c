#include <stdio.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

    int main()
{

    int twoSumArray[5] = {3, 5, 2, 7, 9};
    int target = 16;
    int result = twoSum(twoSumArray, 5, target, 2);

    for (int i = 0; i < 2; i++)
    {
        printf("%d", *result[i]);
    }

    return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize);
{

    // target - num[i] is the number we would like to find
    // if we can find the number, then we can find the position.

    int *result = malloc(returnSize * sizeof(int));
    for (int = 0; i < numSize; i++)
    {
        int map = {};
        int complement = target - nums[i];
        if (complement && complement > 0)
        {
            return {map(complement), i};
        }
        else
        {
            map[nums[i]] = i;
        }
    }
}