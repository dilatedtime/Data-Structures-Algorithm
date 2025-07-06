#include <stdio.h>

int main()
{
    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        char s[n + 1];
        int A[26] = {0};
        scanf("%s", s);

        // Count the frequency of each character
        for (int k = 0; k < n; k++)
        {
            A[(int)s[k] - 'a']++;
        }

        // Print characters with frequency > 1 (one less time than their frequency)
        for (int j = 0; j < 26; j++)
        {
            if (A[j] > 1)
            {
                for (int k = 0; k < A[j] - 1; k++)
                {
                    printf("%c", (char)(j + 'a'));
                }
            }
        }

        // Print characters with frequency <= 1
        for (int j = 0; j < 26; j++)
        {
            if (A[j] > 0)
            {
                printf("%c", (char)(j + 'a'));
            }
        }

        printf("\n");
    }

    return 0;
}
