#include <stdio.h>

int fbn(int n)
{

    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    return fbn(n - 2) + fbn(n - 1);
}

int main()
{

    printf("%d", fbn(5));
}