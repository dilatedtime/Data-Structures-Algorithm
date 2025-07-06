#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    long long MOD = 998244353;
    long long t;
    cin >> t;
    int a, b, c, d;
    while (t--)

    {
        cin >> a >> b >> c >> d;

        if (min(b, d) > min(a, c))
            cout << "Flower"<<endl;
        else
            cout << "Gellyfish"<<endl;
    }

    return 0;
}