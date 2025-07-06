#include <stdio.h>

double ts(int x, int n)
{

    static double f = 1, d = 1;
    static double r;

    if (n == 0)
        return 1;

    r = ts(x, n - 1);
    f = f * x;
    d = d * n;

    return r + f / d;
}

double ts1(double x, double n)
{

    double s = 1;

    for (; n > 0; n--)
    {

        s = 1 + (x / n) * s;
    }

    return s;
}

double ts2(int x, int n)

{
    int i;
    double s = 1;
    double num = 1;
    double den = 1;

    for (i = 1; i <= n; i++)
    {
        num = num * x;
        den = den * i;

        s = s + num / den;
    }
    
    return s;
}

int main()
{

    printf("%lf", ts2(1, 10));

    return 0;
}
