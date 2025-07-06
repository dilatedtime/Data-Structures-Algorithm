#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
    {
        int x;
        int c = 0;
        cin >> x;
        int i = 0;

        {
            while (i < x)
            {

                i = 2 * i + 1;
                c++;
            }
            cout << 2 * c + 1 << endl;
        }
    }
    return 0;
}