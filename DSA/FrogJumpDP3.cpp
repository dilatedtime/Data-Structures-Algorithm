#include <iostream>
#include <vector>
using namespace std;

// long long cost(int n, vector<int> &dp, vector<int> &arr)
// {

//     if (n == 0)
//         return n;
    

//     if (dp[n] != -1)
//         return dp[n];

//     return dp[n] = min(dp[n-1]+abs(arr[n]-arr[n-1]),dp[n-2]+abs(arr[n]-arr[n-2]));
// }

int minCost(vector<int> &arr)
{
    int n = arr.size();
    if (n==1)
        return 0; 
    vector<int> dp(n, -1);
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
    }

    return dp[n-1];
}

int main()

{
    vector<int> arr = {20, 30, 40, 20};
    cout << minCost(arr);
}