#include <stdio.h>

int main()
{

    int t, n, k;

    scanf("%d", &t);
    for (int p = 0; p < t; p++)
    {

        scanf("%d %d", &n, &k);
        int temp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%1d", &temp);

                if (i % k == 0 && j % k == 0)
                {
                    printf("%d", temp);
                }
            }
            if (i % k == 0)
            {
                printf("\n");
            }
        }
    }
    return 0;
}