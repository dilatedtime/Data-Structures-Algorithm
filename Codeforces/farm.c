#include <stdio.h>
int main()
{

    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%d\n", (n / 4) + ((n % 4) / 2));
    }

    return 0;
}