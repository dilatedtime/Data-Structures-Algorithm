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
    int x;
    // int flag=1;
    long long t;
    cin >> t;
    int temp = 0;

    while (t--)

    {
        int flag = 1;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int j = 0; j < n; j++)
        {

            if (x >= 1 && arr[j] == 1)
            {

                while (x > 0)
                {

                    j++;
                    x--;

                    if (j >= n)
                    {
                        flag = 1;
                        break;
                    }
                }

                j--;
            }

            else if (arr[j] == 1 && x <= 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    // solve();
    return 0;
}