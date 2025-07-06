#include <stdio.h>

int main()
{

    int t, a, b, c;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)

    {
        scanf("%d %d", &a, &b);

        if (a == 1 && b == 3)
            printf("1\n");

        else if (a % 2 == 1 && b % 2 == 1)
        {
            c = (b - a + 1);
            if (c < 6)
                printf("%d\n", c / 4);

            else
                printf("%d\n", (c / 4 + 1));
        }

        else
        {

            c = (b - a + 1) / 4;

            printf("%d\n", c);
        }
    }

    return 0;
}