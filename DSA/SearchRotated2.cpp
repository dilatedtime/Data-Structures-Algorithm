#include <iostream>
using namespace std;

int linsearch(const int *A, int s, int e, int val)
{
    if (s == e && A[s] == val)
        return 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (A[mid] == val)
            return 1;
        if (A[s] == val)
            return 1;
        if (A[e] == val)
            return 1;
        if (A[mid] > A[s])
        {
            // Left half is sorted
            if (val >= A[s] && val < A[mid])
                return linsearch(A, s + 1, mid - 1, val);
            else
                return linsearch(A, mid + 1, e - 1, val);
        }
        else if (A[mid] < A[s])
        {
            // Right half is sorted
            if (val > A[mid] && val <= A[e])
                return linsearch(A, mid + 1, e - 1, val);
            else
                return linsearch(A, s + 1, mid - 1, val);
        }

        else
        {
            return linsearch(A, s + 1, e, val);
        }
    }
    return 0;
}

bool search(int *A, int n1, int B)
{

    return linsearch(A, 0, n1 - 1, B);
}
int main()
{
    int arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Index Value" << ": " << search(arr, n, 13) << endl;

    return 0;
}
