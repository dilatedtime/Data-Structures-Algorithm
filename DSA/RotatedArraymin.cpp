#include <iostream>
#include <vector>
using namespace std;

int linsearch(vector <int> A, int s, int e)
{
    if (s == e)
        return s;

    int mid = (s + e) / 2;

    if (mid - 1 >= s && A[mid] < A[mid - 1])
        return mid;
    if (mid + 1 <= e && A[mid] > A[mid + 1])
        return mid + 1;

    if (A[mid] > A[s])
        return linsearch(A, mid + 1, e);
    else
        return linsearch(A, s, mid - 1);
}

// int findMin(const int *A, int n1)
// {
//     if (A[0] <= A[n1 - 1])
//         return A[0];

//     return A[linsearch(A, 0, n1 - 1)];
// }

int findMin(vector<int> &A)
{

    int n1 = A.size();
    if (A[0] <= A[n1 - 1])
        return A[0];

    return A[linsearch(A, 0, n1 - 1)];
}

int main()
{
    vector <int> arr  = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum Value" << ": " << findMin(arr) << endl;

    return 0;
}
