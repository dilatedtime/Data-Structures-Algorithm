#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int recur(const vector<int> &val, vector<int> &wt, int capacity, int n, vector<int> &dp)
{

    if (dp[n] != -1)
        return dp[n];

    int price1, price2, best = -1;

    for (int i = 1; i <= capacity; i++)
    {
        price1 = dp[1];
        price2 = recur(val, wt, capacity, capacity - i, dp);
        best = max(best, price1 + price2);
    }

    return dp[capacity] = best;
}
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = wt.size();
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = val[0];
    dp[2] = max(2 * val[0], val[1]);
    int profit = recur(val, wt, capacity, n, dp);

    return profit;
}

int main()
{
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};
    int n = 8;
    cout << knapSack(val, wt, n);
}