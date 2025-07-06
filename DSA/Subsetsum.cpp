#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

bool isSubsetSum(vector<int> &arr, int sum)
{
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int val = j + arr[i];
            if (dp[j] == 1 && val <= sum && dp[val]==0)
                dp[val] = 2;
        }

        for (int k = 0; k <= sum; k++)
        {
             if (dp[k] == 2)
                dp[k] = 1;
        }
        
    }

    return dp[sum];
}

int main()

{
    // vector<vector<int>> chocolates = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    vector<int> matrix = {3, 34, 4, 12, 5, 2};

    cout << isSubsetSum(matrix, 9);
}