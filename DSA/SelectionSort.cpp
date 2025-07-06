#include <iostream>
using namespace std;

int Minarr(int arr[], int n)
{
    int Min = 10000000;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= Min)
        {
            Min = arr[i];
            index = i;
        }
    }

    return index;
}

void Selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        swap(arr[i], arr[Minarr(arr + i, n - i) + i]);
    }
}

int main()
{

    int arr[] = {-2, 3, 4, 5, 3, 2, 1, 4, 7, 9, -5, -3, -6, -4, 0, -7};
    int n = sizeof(arr) / sizeof(int);

    Selectionsort(arr, n);

    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << ",";
    }

    return 0;
}


