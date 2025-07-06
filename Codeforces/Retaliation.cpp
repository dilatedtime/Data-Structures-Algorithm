// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int n;
//     long long t;
//     cin >> t;
//     int flag = 1;
//     while (t--)

//     {
//         cin>>n;
//         int x;
//         int y;

//         vector<int> arr(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];

//             if (i - 2 >= 0)
//             {
//                 if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2])
//                 {
//                     flag = 0;
//                     break;
//                 }
//             }
//         }

//         x = arr[1] - arr[0];
//         y = (arr[0] - x) / n;

//         for (int i = 0; i < n; i++)
//         {
//             if ((i+1) * x + (n + 1 - (i+1)) * y != arr[i])
//             {
//                 flag = 0;
//                 break;
//             }
//         }

//         if (flag)
//             cout << "YES";
//         else
//             cout << "NO";
//     }

//     // solve();
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool ok = true;
        if (n == 1) {
            // always OK for single element
            ok = true;
        } else {
            long long num = 2*arr[0] - arr[1];
            long long den = n + 1;

            // must divide evenly
            if (num % den != 0) {
                ok = false;
            } else {
                long long y = num / den;
                long long x = arr[0] - n*y;

                // both must be non-negative
                if (x < 0 || y < 0) {
                    ok = false;
                } else {
                    // check the formula for every i
                    for (int i = 0; i < n; i++) {
                        long long expected = (i+1)*x + (n - i)*y;
                        if (arr[i] != expected) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
