#include <iostream>
using namespace std;

int linsearch(const int *A, int s, int e, int val)
{
    if (s == e)

    {
        if (A[s] >= val)
            return s;
        else
            return s + 1;
    }

    while (s <= e)
    {

        int mid = (s + e) / 2;

        if (A[mid] == val)
            return mid;
        if (A[mid] < val)
            return linsearch(A, mid + 1, e, val);
        else
            return linsearch(A, s, mid - 1, val);
    }
}

int searchInsert(int *A, int n1, int B)
{

    return linsearch(A, 0, n1 - 1, B);
}

int main()
{
    int arr[] = {1, 3, 5, 9, 20, 25, 26, 27, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Index" << ": " << searchInsert(arr, n, 20) << endl;

    return 0;
}
