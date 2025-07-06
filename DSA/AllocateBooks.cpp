#include <iostream>
using namespace std;

int ispossible(int *A, int n, int pages, int students)

{
    int rstudents = 0;
    int current = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        if (A[i] > pages)
            return 0;

        if (current + A[i] <= pages)
            current += A[i];

        else
        {
            rstudents++;
            current = A[i];
        }
    }

    if (rstudents + 1 <= students)
        return 1;
    else
        return 0;
}

int findweight(int *A, int s, int e, int n, int students)
{
    int result;

    if (s == e)
        return s;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (ispossible(A, n, mid, students))
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

int books(int *A, int n1, int B)
{

    if (n1 < B)
        return -1;

    int i;
    int sum = 0;
    for (i = 0; i < n1; i++)
    {
        sum += A[i];
    }

    return findweight(A, 0, sum, n1, B);
}

int main()
{
    int arr[] = {5, 17, 100, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum Weight" << ":" << books(arr, n, 4) << endl;

    return 0;
}
    