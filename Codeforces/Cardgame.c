#include <stdio.h>

int win(int x, int y)
{
    if (x > y)
        return 1;
    else if (x < y)
        return -1;

    return 0;
}

int rnd(int a1, int a2, int b1, int b2)
{
    if (win(a1, b1) + win(a2, b2) > 0)
        return 1;

    else if (win(a1, b1) + win(a2, b2) < 0)
        return -1;

    return 0;
}

int main()
{

    int t, a1, a2, b1, b2;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);

        if (rnd(a1, a2, b1, b2) + rnd(a1, a2, b2, b1) + rnd(a2, a1, b1, b2) + rnd(a2, a1, b2, b1) > 0)
        {
            printf("%d\n", rnd(a1, a2, b1, b2) + rnd(a1, a2, b2, b1) + rnd(a2, a1, b1, b2) + rnd(a2, a1, b2, b1));
        }
        else
            printf("0\n");
    }
    return 0;
}
