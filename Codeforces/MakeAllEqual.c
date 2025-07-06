#include <stdio.h>
int main()
{
    int t, n, num;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);

        int frequency[n + 1]; // Array to store frequencies, initialized to 0

        for (int i = 0; i <= n; i++)
        {
            frequency[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            frequency[num]++;
        }

        // Find the maximum frequency
        int maxFrequency = 0;
        for (int i = 0; i <= n; i++)
        {
            if (frequency[i] > maxFrequency)
            {
                maxFrequency = frequency[i];
            }
        }

        printf("%d\n", n - maxFrequency);
    }

    return 0;
}
