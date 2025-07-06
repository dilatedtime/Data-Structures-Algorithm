#include <bits/stdc++.h>
using namespace std;

// void solve(){

// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k, s, n, x, y;
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (n == 1)

        {
            if (s == arr[0])
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }

        else if (s < arr[n - 1] && s > arr[0])
            cout << min(abs(s - arr[0]), abs(s - arr[n - 1])) * 2 + max(abs(s - arr[0]), abs(s - arr[n - 1])) << endl;
        else if (s <= arr[0])
            cout << arr[n - 1] - s << endl;
        else if (s >= arr[n - 1])
            cout << s - arr[0] << endl;
    }
    // solve();
    return 0;
}