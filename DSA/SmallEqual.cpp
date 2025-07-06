#include <iostream>
using namespace std;

int linsearch(const int *A, int s, int e, int val)
{
    if (s == e)
    {
        if (A[s] > val)
        {
            return s;
        }
        if (A[s] < val || A[s]==val )
            return s + 1;
    }

    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (A[mid] == val)
        {
            if (mid + 1 <= e && A[mid + 1] != val)
                return mid+1;
            if (mid + 1 <= e && A[mid + 1] == val)
            {
                return (linsearch(A, mid + 1, e, val));
            }
        }

        if (A[mid] < val)
            return linsearch(A, mid + 1, e, val);
        else
            return linsearch(A, s, mid - 1, val);

    }

    return s;
}

int solve(int *A, int n1, int B)
{

    return linsearch(A, 0, n1 - 1, B);
}

int main()
{
    int arr[] = {1, 2, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Index" << ": " << solve(arr, n, 3) << endl;

    return 0;
}
