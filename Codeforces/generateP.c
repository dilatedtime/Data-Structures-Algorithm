#include <stdio.h>

int main()
{

    int n, t, k;

    scanf("%d", &t);
    for (int j = 0; j < t; j++)
    {
        scanf("%d", &n);


         if (n==1)
         printf("1\n");


         else if (n % 2 == 0)
        {

            printf("-1\n");
        }

        else
        {
            for (int i = n; i >= 1; i = i - 2)
            {
                printf("%d ", i);

            }
            

            
            for (int i = 2; i < n; i = i + 2)
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}