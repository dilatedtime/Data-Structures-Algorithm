
#include <stdio.h>

int makezero(int x)

{
    int k = 0;

    while (x > 0)

    {
        x = x / 3;
        k++;
    }
 
    return k;
}

int main()

{
    int t, l, r, result = 0;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {

        scanf("%d %d", &l, &r);

        result = 2 * makezero(l);

        for (int k = l + 1; k <= r; k++)
        {
            result = result + makezero(k);
        }
        printf("%d\n", result);
    }



    return 0;
}