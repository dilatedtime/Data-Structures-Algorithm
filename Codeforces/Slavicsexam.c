#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    char s1[1000000];
    char s2[1000000];

    scanf("%d", &t);
    while (t--)
    {
        scanf("%s %s", s1, s2);
        int len1 = strlen(s1);
        int len2 = strlen(s2);

        int i = 0, j = 0;

        while (i < len1 && j < len2)
        {
            if (s1[i] == s2[j] || s1[i] == '?')
            {
                if (s1[i] == '?')
                {
                    s1[i] = s2[j];
                }
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        // If all characters in s2 are matched
        if (j == len2)
        {
            // Replace any remaining '?' in s1
            while (i < len1)
            {
                if (s1[i] == '?')
                {
                    s1[i] = 'a';
                }
                i++;
            }
            printf("YES\n");
            printf("%s\n", s1);
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {

//     int i, j, t, flag = 1;
//     char s1[1000000];
//     char s2[1000000];

//     scanf("%d", &t);
//     for (int k = 0; k < t; k++)

//     {

//         scanf("%s %s", s1, s2);

//         for (i = 0, j = 0; i < strlen(s1) && j < strlen(s2);)
//         {

//             if (s2[j] == s1[i])
//             {
//                 i++;
//                 j++;
//             }

//             else if (s1[i] == '?')
//             {
//                 s1[i] = s2[j];
//                 i++;
//                 j++;
//             }

//             else if (s1[i] != s2[j])
//             {

//                 i++;
//             }

//             if (j == strlen(s2))
//             {

//                 for (i; i < strlen(s1); i++)
//                 {
//                     if (s1[i] == '?')
//                     {
//                         s1[i] = 'a';
//                     }
//                 }
//                 break;
//             }
//         }
//         if (j == strlen(s2))
//         {
//             printf("YES\n");
//             printf("%s\n", s1);
//         }
//         else
//             printf("NO\n");
//     }

//     return 0;
// }
