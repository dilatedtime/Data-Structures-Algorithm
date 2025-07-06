#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int cpick(int i, int j1, int j2, int n, int m, vector<vector<int>> &chocolates, vector<vector<vector<int>>> &dp)
{

    if (j1 >= m || j1 < 0 || j2 < 0 || j2 >= m)
        return -1e8;

    if (i == n - 1)
    {
        if (j1 == j2)
            return dp[i][j1][j2] = chocolates[i][j1];
        else
            return dp[i][j1][j2] = chocolates[i][j1] + chocolates[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxii = -10000000;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int val = 0;
            if (j1 == j2)
                val = dp[i][j1][j2] = chocolates[i][j1];
            else
                val = dp[i][j1][j2] = chocolates[i][j1] + chocolates[i][j2];

            maxii = max(maxii, val + cpick(i + 1, j1 + dj1, j2 + dj2, n, m, chocolates, dp));
        }
    }

    return dp[i][j1][j2] = maxii;
}
int maximumChocolates(int n, int m, vector<vector<int>> &chocolates)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return cpick(0, 0, m - 1, n, m, chocolates, dp);
}

int main()

{
    vector<vector<int>> chocolates = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    // vector<vector<int>> matrix = {{-19,57},{-40,5}};
    cout << maximumChocolates(3, 4, chocolates);
}
