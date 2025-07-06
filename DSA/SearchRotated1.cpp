#include <iostream>
using namespace std;

int linsearch(const int *A, int s, int e, int val)
{
    if (s == e && A[s] == val)
        return s;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (A[mid] == val)
            return mid;
        if (A[s] == val)
            return s;
        if (A[e] == val)
            return e;
        if (A[mid] >= A[s])
        {
            // Left half is sorted
            if (val >= A[s] && val < A[mid])
                return linsearch(A, s + 1, mid - 1, val);
            else
                return linsearch(A, mid + 1, e - 1, val);
        }
        else
        {
            // Right half is sorted
            if (val > A[mid] && val <= A[e])
                return linsearch(A, mid + 1, e - 1, val);
            else
                return linsearch(A, s + 1, mid - 1, val);
        }
    }
    return -1;
}

int search(int *A, int n1, int B)
{

    return linsearch(A, 0, n1 - 1, B);
}
int main()
{
    int arr[] = {192, 194, 197, 198, 199, 200, 201, 203, 204, 2, 3, 4, 7, 9, 10, 11, 14, 15, 16, 17, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 33, 34, 35, 36, 39, 40, 42, 43, 46, 47, 50, 51, 52, 53, 55, 57, 59, 60, 64, 66, 68, 70, 71, 72, 75, 76, 78, 85, 86, 87, 91, 92, 94, 95, 96, 99, 102, 105, 106, 107, 109, 111, 113, 114, 115, 119, 120, 121, 123, 125, 129, 130, 131, 133, 134, 137, 138, 139, 140, 141, 142, 143, 145, 146, 149, 151, 152, 156, 160, 161, 165, 167, 168, 170, 171, 176, 177, 178, 179, 180, 181, 182, 185, 186, 190};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Index Value" << ": " << search(arr, n, 210) << endl;

    return 0;
}
