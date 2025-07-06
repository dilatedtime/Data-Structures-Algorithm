#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    vector<int> dp(n, -1);
    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0]);

    if (n == 2)
        return dp[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    return dp[n - 1];
}

int main()

{
    vector<int> arr = {15, 2, 3, 8, 4, 5, 6, 7};
    cout << rob(arr);
}