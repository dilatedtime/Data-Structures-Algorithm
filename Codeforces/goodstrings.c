#include <stdio.h>

int main()
{
    int t, n;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        char A[n];

        scanf("%s", A);

        if (A[0] == A[n - 1])
            printf("NO\n");
        else
            printf("YES\n");
    }
}