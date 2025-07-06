#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int recur(const vector<int> &price, int n, vector<int> &dp)
{

    if (dp[n] != -1)
        return dp[n];

    int price1, price2, best = price[n-1];

    for (int i = 1; i <= n; i++)
    {
        price1 = price[i-1];
        price2 = recur(price, n - i, dp);
        best = max(best, price1 + price2);
    }

    return dp[n] = best;
}
int cutRod(const vector<int> &price)
{
    int n = price.size();
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = price[0];
    int profit = recur(price, n, dp);

    return profit;
}

int main()

{
    // vector<vector<int>> chocolates = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    // vector<int> price = {3, 5, 8, 9, 10, 17, 17, 20};
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    // vector<int> price = {1, 4, 6, 1, 1};

    cout << cutRod(price);
}