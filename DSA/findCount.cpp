#include <iostream>
using namespace std;

int linsearch(const int *A, int s, int e, int B)
{

    int count = 0;

    if (s >= e)
        return 0;

    int mid = (s + e) / 2;

    if (A[mid] == B) {
        int count = 1;

        // Count left side
        int left = mid - 1;
        while (left >= s && A[left] == B) {
            count++;
            left--;
        }

        // Count right side
        int right = mid + 1;
        while (right < e && A[right] == B) {
            count++;
            right++;
        }

        return count;
    }
    else if (A[mid] < B) {
        return linsearch(A, mid + 1, e, B);
    }
    else {
        return linsearch(A, s, mid, B);
    }

    return count;
}

int findCount(const int *A, int n1, int B)
{

    return linsearch(A, 0, n1, B);
}

int main()
{
    int arr[] = {4, 7, 7, 7, 8, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    cout << "Count of " << target << ": " << findCount(arr, n, target) << endl;

    return 0;
}
