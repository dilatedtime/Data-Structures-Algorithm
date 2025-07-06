#include <iostream>
using namespace std;

// int findrt(int s, int e, int val)
// {
//     if (s == e)
//         return s;

//     int mid = (s + e) / 2;

//     if (mid * mid <= val && (mid + 1) * (mid + 1) > val)
//         return mid;

//     if (mid * mid < val)
//         return findrt(mid + 1, e, val);
//     else
//         return findrt(s, mid - 1, val);
// }

// int sqrt(int A)
// {

//     return findrt(1, A, A);
// }

long long findrt(long long s, long long e,long long val)
{
    if (s == e)
        return s;

    long long mid = (s + e) / 2;

    if (mid * mid <= val && (mid + 1) * (mid + 1) > val)
        return mid;

    if (mid * mid < val)
        return findrt(mid + 1, e, val);
    else
        return findrt(s, mid - 1, val);
}

long long floorSqrt(long long n) { return (long long)findrt(1, n, n); }

int main()
{

    // cout << sqrt() << endl;
    cout<<floorSqrt(8);

        return 0;
}
