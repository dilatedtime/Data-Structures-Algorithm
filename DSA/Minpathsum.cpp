#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minPathSum(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    if (n == 1 && m == 1)
        return arr[0][0];
    
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0]=arr[0][0];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n)
                dis[i + 1][j] = min(dis[i + 1][j], dis[i][j] + arr[i + 1][j]);
            if (j + 1 < m)
                dis[i][j + 1] = min(dis[i][j + 1], dis[i][j] + arr[i][j + 1]);
        }

    }

    return dis[n-1][m-1];
}


int main()

{
    // vector<vector<int>> arr = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(arr);
}