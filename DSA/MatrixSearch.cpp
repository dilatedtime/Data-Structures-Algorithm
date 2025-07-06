#include <iostream>
using namespace std;

int searchMatrix(int** A, int n11, int n12, int B) {
    int low = 0;
    int high = n11 * n12 - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / n12;
        int col = mid % n12;

        if (A[row][col] == B)
            return 1;
        else if (A[row][col] < B)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}
int main()
{
    int arr[7][5] = {

        {2, 3, 11, 12, 14},
        {16, 17, 30, 34, 35},
        {45, 48, 49, 50, 52},
        {56, 59, 63, 63, 65},
        {67, 71, 72, 73, 79},
        {80, 84, 85, 85, 88},
        {88, 91, 92, 93, 94}};

    int n = sizeof(arr) / sizeof(arr[0][0]);

    int* rowPointers[7];
    for (int i = 0; i < 7; ++i) {
        rowPointers[i] = arr[i];
    }

    int result = searchMatrix(rowPointers, 7, 5, 94);  // Searching for 4

    cout << "Index: " << result << endl;

    return 0;
}
