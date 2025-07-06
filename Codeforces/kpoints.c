#include <stdio.h>

int main()
{

    int x, y, t, k;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {

        scanf("%d %d %d", &x, &y, &k);
        if (k % 2 == 0)
        {
            for (int i = -k / 2; i < 0; i++)
            {
                printf("%d %d\n", x - i, y - i);
                printf("%d %d\n", x + i, y + i);
            }
        }
        else
        {
            // if (k == 1)
            //     printf("%d %d", x, y);
            // else
            {
                for (int i = -k / 2; i < 0; i++)
                {
                    printf("%d %d\n", x - i, y - i);
                    printf("%d %d\n", x + i, y + i);
                }
                printf("%d %d\n", x, y);
            }
        }
    }

    return 0;
}