#include<stdio.h>

int main()
{

    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        int A[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);

            if (A[i] == n)
                printf("1 ");
            else
                printf("%d ", A[i] + 1);
        }
    }
    return 0;
}