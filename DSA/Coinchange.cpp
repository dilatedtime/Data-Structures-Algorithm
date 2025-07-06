#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int coinChange(vector<int> &coins, int amounts)
{
    vector<pair<int, int>> dp(amounts + 1, {0, 1e7});
    dp[0] = {1, 0};
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = 0; j <= amounts; j++)
        {
            int val = j + coins[i];
            if (dp[j].first == 1 && val <= amounts && dp[val].first == 0)
            {
                dp[val].first = 1;
                dp[val].second = dp[j].second + 1;
            }
            else if (dp[j].first == 1 && val <= amounts)
          
               dp[val].second = min(dp[val].second, dp[j].second + 1);
        }
    }

    int final = dp[amounts].second ;
    return final >= 1e7 ? -1 : final;
}

int main()

{
    vector<int> coins = {1,2,5};

    cout << coinChange(coins, 11);
}