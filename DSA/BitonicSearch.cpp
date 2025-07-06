#include <iostream>
using namespace std;

int binsearch(const int *A, int s, int e, int val)

{
    int mid = (s + e) / 2;

    if (A[mid] == val)
        return mid;

    if (A[s] < A[e]) // increasing
    {

        if (A[mid] > val)
            return binsearch(A, s, mid - 1, val);
        else
            return binsearch(A, mid + 1, e, val);
    }

    if (A[s] > A[e]) // decreasing
    {
        if (A[mid] < val)
            return binsearch(A, s, mid - 1, val);
        else
            return binsearch(A, mid + 1, e, val);
    }

    return -1;
}

int finsearch(const int *A, int s, int p, int e, int val)

{

    if (A[s] <= val && binsearch(A, s, p, val) >= 0)
    {
        // cout << "binsearch" << s << p << val << endl;
        return binsearch(A, s, p, val);
    }
    if (A[e] <= val && binsearch(A, p + 1, e, val) >= 0)
    {
        // cout << "binsearch" << p + 1 << e << val << endl;
        return binsearch(A, p + 1, e, val);
    }

    return -1;
}

int linsearch(const int *A, int s, int e)
{
    if (s == e)
        return s;

    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (mid - 1 >= s && mid + 1 <= e && A[mid] > A[mid - 1] && A[mid + 1] < A[mid])
            return mid;

        if (A[mid + 1] > A[mid])
            return linsearch(A, mid + 1, e);
        else
            return linsearch(A, s, mid - 1);
    }
}

int solve(int *A, int n1, int B)
{

    return finsearch(A, 0, linsearch(A, 0, n1 - 1), n1 - 1, B);
}

int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Index" << ": " << solve(arr, n, 30) << endl;

    return 0;
}
