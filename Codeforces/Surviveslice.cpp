#include <iostream>
using namespace std;

int div(int a)
{

    int count = 0;
    while (a > 1)
    {
        count++;
        if (a % 2 == 0)
            a = a / 2;
        else
            a = (a / 2) + 1;
    }

    return count;
}

void findk(int n, int m, int a, int b)
{
    int row = n;
    int col = m;
    row = min(a - 1, n - a) + 1;
    int ans = div(row) + div(m) + 1;

    col = min(b - 1, m - b) + 1;

    cout << min(ans, div(n) + div(col) + 1) << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int m, n, a, b;
        cin >> n;
        cin >> m;
        cin >> a;
        cin >> b;

        findk(n, m, a, b);
    }

    return 0;
}
