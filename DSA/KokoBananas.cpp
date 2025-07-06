#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

// bool ispossible(int *A, int n, int hrs, int k)

// {
//     int rhrs = 0;
//     int current = 0;
//     int i;

//     for (i = 0; i < n; i++)
//     {

//         current = A[i];

//         if (A[i] <= k)
//         {
//             rhrs++;
//             continue;
//         }

//         else if (A[i] > k && current > 0 )
//         {
//             while (current > 0)
//             {
//                 current = current - k;
//                 rhrs++;
//             }
//         }
//     }

//     if (rhrs <= hrs)
//         return 1;
//     else
//         return 0;
// }

bool ispossible(int *A, int n, int hrs, int k)
{
    if (k == 0) return 0;
    long long totalHrs = 0;
    for (int i = 0; i < n; i++)
    {

        if (A[i] < k)
        {
            totalHrs++;
            continue;
        }
        
        totalHrs += ceil((double)A[i] / k); // ceil(A[i] / k)
        // cout<<totalHrs<<",";
    }
    return totalHrs <= hrs;
}

int findweight(int *A, int s, int e, int n, int days)
{
    int result = INT_MAX;

    if (s == e)
        return s;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (ispossible(A, n, days, mid))
        {
            result = mid;
            e = mid - 1;
        }

        else
            s = mid + 1;
    }

    return result;
}

int minEatingSpeed(int *A, int n1, int B)
{

    return findweight(A, 0, INT_MAX, n1, B);
}

int main()
{
    int arr[] = {805306368,805306368,805306368};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << ispossible(arr, n, 1000000000, 3  );
    // cout << "Minimum Weight" << ":" << minEatingSpeed(arr, n, 1000000000) << endl;

    return 0;
}
