#include <iostream>
using namespace std;
#include <cmath>

// #define MOD 10000003

// int isFeasible(int arr[], int n, int k, long long maxTime) {
//     int painters = 1;
//     long long total = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] > maxTime) return 0;
//         if (total + arr[i] <= maxTime) {
//             total += arr[i];
//         } else {
//             painters++;
//             total = arr[i];
//         }
//     }
//     return (int)painters <= k;
// }

// int findMin(int p, int t, int *C, int n) {
//     long long low = 0, high = 0;
//     for (int i = 0; i < n; i++) {
//         high += C[i];
//     }

//     long long result = high;
//     while (low <= high) {
//         long long mid = (low + high) / 2;
//         if (isFeasible(C, n, p, mid)) {
//             result = mid;
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }

//     return (int)((result % MOD) * (t % MOD) % MOD);
// }

// int paint(int A, int B, int *C, int n3) {
//     return findMin(A, B, C, n3);
// }

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int findMin(int p, int t, int *C, int n)
{
    const int MOD = 10000003;

    if (p >= n)
    {
        int largest = -1;
        int i;
        for (i = 0; i < n; i++)
        {
            largest = max(largest, C[i]);
        }
        // Apply modulo only at the end
        return (int)((1LL * t * largest) % MOD);
    }

    long long sum = 0;
    int largest = -1;
    int i;
    for (i = 0; i < n; i++)
    {

        sum += C[i]; // no modulo here
    }

    double avg = (double)sum / p;

    long long time = -1;
    long long current = 0;
    long long painters = 0;

    int k = 0;

    for (k = 0; k < n; k++)
    {

        if (time != -1 && current + C[k] < time && k < n)
        {
            current += C[k];
            if (k >= n)
                break;
        }

        if (k < n && abs((double)(avg - current)) >= abs((double)(avg - ((double)current + C[k]))))
            current += C[k];
        else
        {

            time = max((int)time, (int)current);
            cout << current << endl;
            current = C[k];
        }
    }

    // while (k < n) {
    //     // while current + C[k] < time
    //     while (time != -1 && current + C[k] < time && k < n) {
    //         current += C[k];
    //         k++;
    //         if (k >= n) break;
    //     }

    //     while (k < n && abs(avg - current) >= abs(avg - (current + C[k]))) {
    //         current += C[k];
    //         k++;
    //     }

    //     time = max((int)time, (int)current);
    //     current = 0;
    // }

    return (int)((1LL * t * time) % MOD);
}

int paint(int A, int B, int *C, int n3)
{
    return findMin(A, B, C, n3);
}

int main()
{
    int arr[] = {18, 13, 3, 5, 9, 12, 7, 6, 5, 8, 12, 16};
    // {13, 5, 7, 9, 12, 8, 10, 5, 4, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // A painters and B time
    cout << "Minimum time" << ": " << paint(7, 1, arr, n) << endl;

    return 0;
}
