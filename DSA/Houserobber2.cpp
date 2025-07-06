#include <iostream>
#include <vector>
using namespace std;

int robLinear(vector<int> &arr)
{
    int n = arr.size();
    int flag = 0;
    if (n == 1)
        return arr[0];
    // vector<int> dp(n, -1);
    // dp[0] = arr[0];
    int prev2 = arr[0];
    int prev1 = max(arr[1], arr[0]);
    int curr = 0;
    if (n == 2)
        return prev1;

    for (int i = 2; i <= n; i++)
    {
        curr = max(prev1, prev2 + arr[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}



int rob(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    if (n == 2)
        return max(arr[0], arr[1]);

    // Create two subarrays: [0..n-2] and [1..n-1]
    vector<int> arr1(arr.begin(), arr.end() - 1); // exclude last
    vector<int> arr2(arr.begin() + 1, arr.end()); // exclude first

    return max(robLinear(arr1), robLinear(arr2));
}

int main()

{
    vector<int> arr = {2, 15, 14, 3, 8, 4, 5, 6, 7};
    // vector<int> arr = {2, 3, 2};

    cout << rob(arr);
}
