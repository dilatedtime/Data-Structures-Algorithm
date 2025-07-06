#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

long long power(long long x, long long n, long long d)
{
    if (n == 0)
        return 1 % d;

    if (n == 1)
        return x % d;

    if (n % 2 == 0)
    {
        long long temp = power((x * x) % d, n / 2, d);
        return temp % d;
    }
    else
    {
        long long temp = power((x * x) % d, n / 2, d);
        return (x % d * temp % d) % d;
    }
}

long long powmod(long long x, long long n, long long d)
{
    long long result = power(x, n, d);

    if (result >= 0)
        return result;
    else
    {
        while (result < 0)
        {
            result += d;
        }
        return result;
    }
}

int main()
{

    cout << powmod(71045970, 41535484, 64735492);
}




1 5 8 10 15 17

 2 3 7 14
 
 1 2 3 5 7 8 10 14 15 17