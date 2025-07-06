#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int arr[10];
    int n;

    cin >> n;

    int count = 0;
    int num = 0;
    int k = n;

    while (n > 0)
    {
        arr[count] = n % 10;
        n = n / 10;
        count++;
    }

    for (int i = 0; i < count; i++)
    {

        num = num + pow(arr[i], count);
    }

    if (num == k)
        cout << "True";
    else
        cout << "False";
    return 0;
}