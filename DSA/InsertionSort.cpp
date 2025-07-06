#include <iostream>
using namespace std;

void Insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {

        for (int k = 1; k <= i; k++)
        {
            if (i - k >= 0)
            {
                while (arr[i - k] > arr[i - k + 1])
                {
                    swap(arr[i - k], arr[i - k + 1]);
                }
            }
        }
    }
}

int main()
{

    int arr[] = {-2, 3, 4, 5, 3, 2, 1, 4, 7, 9, -5, -3, -6, -4, 0, -7};
    int n = sizeof(arr) / sizeof(int);

    Insertionsort(arr, n);

    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << ",";
    }

    return 0;
}
