#include <iostream>
#include <vector>
using namespace std;

long long fbn(int n, vector<int> &dp)
{

    if (n <= 3)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fbn(n - 1, dp) + fbn(n - 2, dp);
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return (int)fbn(n, dp);
}

int main()

{
    int n = 7;
    cout << climbStairs(n);
}