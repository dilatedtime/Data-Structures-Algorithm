#include <iostream>
using namespace std;

// int linsearch(const int *A, int s, int e)
// {
//     if (s == e )
//         return s;

//     while (s <= e)
//     {
//         int mid = (s + e) / 2;

//         if (A[mid] != A[mid + 1] && A[mid] != A[mid - 1])
//             return mid;

//         if (mid + 1 <= e && A[mid] == A[mid + 1] && (mid - s) % 2 != 0)
//         {
//             return linsearch(A, s , mid - 1);
//         }
//         else if (mid + 1 <= e && A[mid] == A[mid + 1] && (mid - s) % 2 == 0)
//             return linsearch(A, mid + 1, e);

//         else if (mid - 1 >= s && A[mid] == A[mid - 1] && (e - mid) % 2 != 0)
//         {
//             return linsearch(A, mid + 1, e);
//         }
//         else if  (mid - 1 >= s && A[mid] == A[mid - 1] && (e - mid) % 2 == 0)
//             return linsearch(A, s, mid - 1);
//     }
//     return s;
// }

// int singleNonDuplicate(int *A, int n1)
// {

//     return A[linsearch(A, 0, n1 - 1)];
// }

int singleNonDuplicate(int *A, int n1) {
    int s = 0, e = n1 - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (mid % 2 == 1)
            mid--;  // Ensure mid is even

        if (A[mid] == A[mid + 1])
            s = mid + 2;
        else
            e = mid;
    }

    return A[s];
}



int main()
{
    int arr[] = {1,1,2,3,3,4,4,8,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Value" << ": " << singleNonDuplicate(arr, n) << endl;

    return 0;
}
