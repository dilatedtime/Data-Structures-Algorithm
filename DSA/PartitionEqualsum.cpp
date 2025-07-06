#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

bool canPartition(vector<int> &arr)
{
    int n = arr.size();
    int sum=0;
    for (int l = 0; l < n; l++)
    {
        sum+=arr[l];
    }

    if (sum%2==1)
        return 0;
    else 
        sum=sum/2;

    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
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
    vector<int> matrix = {1,2,3,5};

    cout << canPartition(matrix);
}