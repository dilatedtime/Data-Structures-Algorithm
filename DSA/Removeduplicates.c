#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize <= 1) // No duplicates possible for arrays of size <= 1
        return numsSize;

    int k = 1; // Start with one unique element

    for (int i = 1; i < numsSize; i++)
    {
        int isDuplicate = 0;

        for (int j = 0; j < k; j++)
        {
            if (nums[i] == nums[j])
            {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate)
        {
            nums[k] = nums[i]; // Move the unique element to its correct position
            k++;               // Increment the index only for unique elements
        }
    }

    return k;
}
