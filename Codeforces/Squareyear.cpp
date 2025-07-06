#include <iostream>
#include <cmath>
using namespace std;

bool issquare(int n)
{
    double num = sqrt(n);
    return floor(num) == num;
}

int main()
{
    int t;
    cin >> t;
    int w;
    while (t--)
    {
        cin >> w;

        if (issquare(w))
        {
            cout << 0 << " " << sqrt(w) << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}
