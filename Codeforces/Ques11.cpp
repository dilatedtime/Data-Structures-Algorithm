#include <bits/stdc++.h>
using namespace std;

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int left = n % 3;
        if (left == 0)
        {
            cout << 0 << endl;
        }
        else
            cout << 1 << endl;
    }
    // solve();
    return 0;
}