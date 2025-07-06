#include <iostream>
using namespace std;

int slinsearch(const int *A, int s, int e, int val)
{

    if (s == e && A[s] == val)
        return s;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (A[mid] == val)
        {
            if (A[mid - 1] != val)
                return mid;

            if (A[mid - 1] == val)
                return slinsearch(A, s, mid - 1, val);
        }

        if (A[mid] > val)
            return slinsearch(A, s, mid - 1, val);

        else
            return slinsearch(A, mid + 1, e, val);
    }
    return -1;
}

int elinsearch(const int *A, int s, int e, int val)
{

    if (s == e && A[s] == val)
        return s;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (A[mid] == val)
        {
            if (A[mid + 1] != val)
                return mid;

            if (A[mid + 1] == val)
                return elinsearch(A, mid + 1, e, val);
        }

        if (A[mid] > val)
            return elinsearch(A, s, mid - 1, val);

        else
            return elinsearch(A, mid + 1, e, val);
    }
    return -1;
}



int* searchRange(const int *A, int n1, int B, int *len1)
{

    int *len2;
    len2 = (int *)malloc(2 * sizeof(int));
    len2[0] = slinsearch(A, 0, n1 - 1, B);
    len2[1] = elinsearch(A, 0, n1 - 1, B);
    *len1 = 2;

    return len2;
}

int main()
{
    int arr[] = {5, 7, 7, 8, 8, 8, 8, 9, 10, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *len1;
    len1 = (int *)malloc(2 * sizeof(int));

    cout << "Index Value" << ": " << searchRange(arr, n, 8, len1)[0]<<"," << searchRange(arr, n, 8, len1)[1]<< endl;

    return 0;
}
