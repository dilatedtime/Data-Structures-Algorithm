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
        double sq = sqrt(n);

        cout << floor(sq) * floor(sq);
    }
    // solve();
    return 0;
}

