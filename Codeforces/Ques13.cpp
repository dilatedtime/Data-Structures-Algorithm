#include <bits/stdc++.h>
using namespace std;

void solve()
{
}

int hcf(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return hcf(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, y;
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        if (x % 2 == 0 && y % 2 == 0 || hcf(x, y) > 1)
            cout << 0 << endl;
        else if (hcf(x + 1, y) > 1 || hcf(x, y + 1) > 1)
            cout << 1 << endl;
        else
            cout << 2<<endl;
    }
    // solve();
    return 0;
}
