#include <stdio.h>

int makezero(int x, int y)
{
    int i, k = 0, strt = x, result;
    float temp = 1.0/3.0;

    // Calculate the highest power of 3 less than or equal to x
    while (x > 0)
    {
        x = x / 3;
        temp = temp * 3;
        k++;
    }

    x = strt; // Reset x to its original value

    //temp = temp / 3;
    int A[10];
    A[0] = temp;
    result = 2 * k;

    // Populate array A
    for (i = 1; i < 10; i++)
    {
        if (temp * 3 < y)
        {
            A[i] = temp * 3;
            temp = temp * 3;
        }
        else
        {
            break; // Stop filling the array if we exceed y
        }
    }
    A[i] = temp * 3;
    i = 1; // Start checking intervals from A[1] onward

    for (int l = x + 1; l <= y; l++)
    {
        if (l < A[i])
        {
            result = result + i + k - 1;
        }
        else if (l >= A[i])
        {
            i++;
            result = result + i + k - 1;
        }
    }

    return result;
}

int main()
{

    int t, x, y;
    scanf("%d", &t);
    for (int m = 0; m < t; m++)

    {
        scanf("%d %d", &x, &y);
        printf("%d\n", makezero(x, y));
    }

    return 0;
}

