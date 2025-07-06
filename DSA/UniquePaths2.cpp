#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

const int MOD = 2000000009;
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    if (obstacleGrid[n-1][m-1]==1)
        return 0;
    if (n == 1 && m == 1)
        return 1;

    vector<vector<int>> ways(n, vector<int>(m, 0));
    ways[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j] != 1)
            {
                if (i + 1 < n)
                    ways[i + 1][j] = ways[i + 1][j] + ways[i][j] % MOD;
                if (j + 1 < m)
                    ways[i][j + 1] = ways[i][j + 1] + ways[i][j] % MOD;
            }
        }
    }

    return ways[n - 1][m - 1] % MOD;
}

int main()

{
    vector<vector<int>> arr = {{0, 0}, {0, 1}};
    cout << uniquePathsWithObstacles(arr);
}