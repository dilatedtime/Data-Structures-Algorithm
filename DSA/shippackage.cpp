#include <iostream>
using namespace std;

bool ispossible(int *A, int n, int days, int w)

{
    int rdays = 0;
    int current = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        if (A[i] > w)
            return 0;

        if (current + A[i] <= w)
            current += A[i];

        else
        {
            rdays++;
            current = A[i];
        }
    }

    if (rdays +1 <= days)
        return 1;
    else
        return 0;
}

int findweight(int *A, int s, int e, int n, int days)
{
    int result = 1000000;

    if (s == e)
        return s + 1;

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
    // cout << ispossible(A, n, 3, 5);

    return result;
}

int solve(int *A, int n1, int B)
{

    int i;
    int sum = 0;
    for (i = 0; i < n1; i++)
    {
        sum += A[i];
    }

    int avg = sum / n1;

    return findweight(A, avg, sum, n1, B);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum Weight" << ":" << solve(arr, n, 5) << endl;

    return 0;
}
