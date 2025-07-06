#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int perfectSum(vector<int> &arr, int sum)
{
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];
        for (int j = sum; j >= x; j--)
        {
            dp[j] += dp[j - x];
            // dp[j] += dp[j + x];
        }

        for (int k = 0; k <= sum; k++)
        {
            if (dp[k] == -1)
                dp[k] = 1;
        }
    }
    return (int)dp[sum];
}

int main()

{
    // vector<vector<int>> chocolates = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    vector<int> matrix = {2, 5, 1, 4, 3};

    cout << perfectSum(matrix, 10);
}