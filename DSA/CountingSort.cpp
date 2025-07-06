#include <iostream>
using namespace std;

void CountingSort(int arr[], int n)
{

    int pfreq[100] = {0};
    int nfreq[100] = {0};

    for (int i = 0; i < 100; i++)
    {
        if (arr[i] >= 0)
            pfreq[arr[i]]++;

        else
            nfreq[arr[i] * (-1)]++;
    }

    int sorted[200];

    for (int i = 0, k = 99; i < 100, k > 0; i++, k--)
    {
        sorted[i] = nfreq[k];
    }
    for (int i = 100, k = 0 ; i < 200, k < 100; i++, k++)
    {
        sorted[i] = pfreq[k];
    }

    for (int j = 0; j < 200; j++)
    {
        if (sorted[j]!=0)
            cout<<sorted[j]<<",";

    }
    
}

int main()
{

    int arr[] = {-2, 3, 4, 5, 3, 2, 1, 4, 7, 9, -5, -3, -6, -4, 0, -7};
    int n = sizeof(arr) / sizeof(int);

    CountingSort(arr, n);

    // for (int k = 0; k < n; k++)
    // {
    //     cout << arr[k] << ",";
    // }

    return 0;
}