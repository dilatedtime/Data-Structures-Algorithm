/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int *arr = (int *)malloc((digitsSize + 1) * sizeof(int));
    int num = 0, count = 0, temp = 1;

    if (digits[digitsSize - 1] < 9)
    {
        digits[digitsSize - 1]++;
        *returnSize = digitsSize;
        return digits;
    }

    else
    {

          
        for (int i = 0; i < digitsSize; i++)
        {
            arr[i+1]=digits[i];
        }

        for (int i = digitsSize - 1; i >= 0; i--)
        {
            if (digits[i] == 9 && temp == 1)
            {
                arr[i + 1] = 0;
                temp = 1;
            }

            else if (digits[i] < 9 && temp == 1)
            {
                arr[i + 1] = digits[i] + 1;
                temp = 0;
            }

            if (temp == 0)
                break;
        }

        
        if (temp == 1)
        {
            arr[0] = 1;
            *returnSize = digitsSize + 1;
            return arr;
        }
        else
        {
            arr[0]=0;
            *returnSize = digitsSize;
            
            if (arr[0]!=0)
            return arr;
            else 
            return arr+1;


        }

       
    }
     free(arr);
}

