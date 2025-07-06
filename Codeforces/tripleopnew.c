#include <stdio.h>
#include <math.h>

long long makezero(int x, int y)
{
    int i, l = 0, k = 0, strt = x, end = y;
    long long result;

    // Calculate the highest power of 3 less than or equal to x
    while (x > 0)
    {
        x = x / 3;
        k++;
    }

    while (y > 0)
    {
        y = y / 3;
        l++;
    }

    x = strt;
    y = end;

    result = 2 * k +  (long long)(pow(3, k) - x - 1) * k + (long long)((y + 1) - round(pow(3, l - 1))) * l;

    for (int i = k; i <= l-2; i++)
    {
        result += (long long)(pow(3, i + 1) - pow(3, i)) * (i + 1);
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
        printf("%lld\n", makezero(x, y));
    }

    return 0;
}
