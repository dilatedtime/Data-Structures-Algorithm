#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

bool ispossible(vector<int> &arr, int n, int sum)
{

    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int val = j + arr[i];
            if (dp[j] == 1 && val <= sum && dp[val] == 0)
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

int minimumDifference(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    int maxp=0;
    for (int l = 0; l < n; l++)
    {
        sum += arr[l];
        if(arr[l]>0)
        maxp=maxp+arr[l];
    }

    if (sum==0 && maxp!=0)
    return 2*maxp;

    for (int i = sum / 2; i >= 0; i--)
    {
        if (ispossible(arr, n, i))
            return abs((sum - i) - i);
    }

    return 0;
}

int main()

{
    // vector<int> matrix = {2, -1, 0, 4, -2, -9};
    vector<int> matrix = {76,8,45,20,74,84,28,1};

    cout << minimumDifference(matrix);..
}