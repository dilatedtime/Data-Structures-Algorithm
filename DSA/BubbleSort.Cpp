#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{

    int arr[] = {-2, 3, 4, 5, 3, 2, 1, 4, 7, 9, -5, -3, -6, -4, 0, -7};
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);

    for (int k = 0; k < n ; k++)
    {
        cout<<arr[k]<<",";
    }
    

        return 0;
}