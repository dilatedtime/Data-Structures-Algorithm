#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int countPartitions(vector<int> &arr, int d)
{
    int n = arr.size();
    int target = 0;
    for (int i = 0; i < n; i++)
    {
        target += arr[i];
    }

    if (d>target)
        return 0;
    if ((target - d) % 2)
        return 0;

    int sum = (target - d) / 2;

    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        for (int j = sum; j >= x; j--)
        {
            dp[j] += dp[j - arr[i]];
         
        }
    }

    return (int)dp[sum];
}

int main()

{
    // vector<vector<int>> chocolates = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    vector<int> matrix = {2, 3, 5, 1, 3, 4, 5, 4, 4, 5, 2, 4, 1, 1};

    cout << countPartitions(matrix, 48);
}