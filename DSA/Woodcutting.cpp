// #include <iostream>
// using namespace std;

// int calval(int *A, int index, int val, int n)
// {
//     int B = 0;
//     int i;
//     for ( i = index; i < n; i++)
//     {

//         int B = B + (A[i] - B);
//     }

//     return B;
// }

// int findH(int *A, int low, int high, int val)
// {

//     if (low == high)
//     {
//         if (calval(A, low, val, high) >= val)
//             return low;
//     }

//     int mid = low + (high - low) / 2;

//     if (calval(A,low, mid, val) == val)
//         return mid;

//     else if (calval(A, low, mid, val) < val)
//         return findH(A, low, mid - 1, val);
//     else
//         return findH(A, mid + 1, high, val);

// }

// int solve(int *A, int n1, int B)
// {
//     return findH(A, 0, n1, B);
// }

// int main()
// {
//     int arr[] = {20, 15, 10, 17};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Maximum value of H" << ": " << solve(arr, n, 7) << endl;

//     return 0;
//     return 0;
// }




#include <iostream>
using namespace std;


int big (int a, int b){

    if (a>b)
    return a;
    return b;
}


int ispossible(int *A, int slength, int n, int val)

{
    int cwood = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        if (A[i] >= slength)
            cwood = cwood + (A[i] - slength);
    }

    if (cwood >= val)
        return 1;
    else
        return 0;
}

int findweight(int *A, int s, int e, int n, int val)
{
    int result = 0;

    if (s == e && !ispossible(A, s + 1, n, val))
        return s;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (ispossible(A, mid, n, val))
        {
            result = mid;
            s = mid + 1;
        }

        else
            e = mid - 1;
    }

    // cout << ispossible(A, 38, n, val);

    return result;
}

int solve(int *A, int n1, int B)
{

    int i;
    int high = 0;
    for (i = 0; i < n1; i++)
    {
        high = big(high, A[i]);
    }

    return findweight(A, 0, high, n1, B);
}

int main()
{
    int arr[] = {20, 15, 10, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum height" << ":" << solve(arr, n, 7) << endl;

    return 0;
}

