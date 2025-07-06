#include <stdio.h>

int fbn(int n)
{

    if (n <= 1)
        return n;

    int s = 1;
    int t1 = 1;
    int t0 = 1;

    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

int rfbn(int n)
{

    if (n == 1)
        return 1;
    if (n == 2)
        return 1;

    return fbn(n - 2) + fbn(n - 1);
}

int arr[100];

int mfbn(int n)
{

    if (n <= 1)
    {
        arr[n] = n ;
        return n;
    }

    if (arr[n] > 0)
        return arr[n];

    else
        arr[n] = fbn(n - 2) + fbn(n - 1);
    return fbn(n - 2) + fbn(n - 1);
}

int main()
{

    for (int i = 0; i < 100; i++)
    {
        arr[i] = -1;
    }

    printf("%d", mfbn(6));
}