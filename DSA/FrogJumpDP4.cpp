#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// long long cost(int n, vector<int> &dp, vector<int> &arr)
// {

//     if (n == 0)
//         return n;
    

//     if (dp[n] != -1)
//         return dp[n];

//     return dp[n] = min(dp[n-1]+abs(arr[n]-arr[n-1]),dp[n-2]+abs(arr[n]-arr[n-2]));
// }

int minCost(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n==1)
        return 0; 
    vector<int> dp(n, INT_MAX);
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);


    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i-j>=0)
                dp[i] = min(dp[i],dp[i-j]+abs(arr[i]-arr[i-j]));
        }
        
        
    }

    return dp[n-1];
}

int main()

{
    vector<int> arr = {10, 5, 20, 0, 15};
    cout << minCost(arr,2);
}