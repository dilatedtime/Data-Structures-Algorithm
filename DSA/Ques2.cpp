// #include <bits/stdc++.h>
// using namespace std;

// void solve(vector<int> &arr, int n, int k)
// {

//     while (k)
//     {
//         for (int i = 0; i < n; )
//         {
//             int m = pow(2, (ceil(log2(arr[i]))));
//             if (m - 1 != arr[i] && k >= m - 1 - arr[i])
//                 k = k - (m - 1 - arr[i]);

//             else if (k >= 2)
//             {
//                 k = k - 2;
//                 arr[i] = arr[i] + 2;
//             }

//             if (arr[i]>arr[i+1])
//             i++;
//         }
//     }
// }

// int cbit(int n)
// {
//     int count = 0;
//     while (n > 0)
//     {
//         n &= (n - 1);
//         count++;
//     }
//     return count;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int n, k;
//     long long t;
//     cin >> t;
//     int ones = 0;
//     while (t--)
//     {
//         cin >> n >> k;
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];

//             if (arr[i] % 2 == 0 && k)
//             {
//                 arr[i] = arr[i] + 1;
//                 k--;
//             }

//             ones = ones + cbit(arr[i]);
//         }

//         if (k == 0)
//             return ones;

//         sort(arr.begin(), arr.end());
//         solve(arr, n, k);
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        long long size, budget;
        cin >> size >> budget;

        vector<long long> numbers(size);
        for (int j = 0; j < size; j++) {
            cin >> numbers[j];
        }

        long long onesCount = 0;
        priority_queue<long long, vector<long long>, greater<long long>> bitFlipCost;

        for (int i = 0; i < size; i++) {
            long long current = numbers[i];
            for (int power = 60; power >= 0; power--) {
                long long bitMask = 1LL << power;
                if (current & bitMask) {
                    onesCount++;
                } else {
                    bitFlipCost.push(bitMask);
                }
            }
        }

        while (!bitFlipCost.empty() && bitFlipCost.top() <= budget) {
            long long use = bitFlipCost.top();
            bitFlipCost.pop();
            budget -= use;
            onesCount++;
        }

        cout << onesCount << '\n';
    }

    return 0;
}
