// #include <iostream>
// using namespace std;

// void checkliar(int *arr, int k)
// {

//     int sum = 0;
//     int flag = 0;

//     for (int i = 0; i < k; i++)
//     {

//         sum = sum + arr[i];
//     }

//     for (int l = 0; l < k - 1; l++)
//     {

//         if (arr[l] == 0 && arr[l + 1] == 0)
//             flag = 1;
//     }

//     if (sum > (k - 1))
//         flag = 1;
//     if (sum < (k - 1) / 2)
//         flag = 1;

//       if (flag==1)
//       cout<<"YES"<<endl;
//       else
//       cout<<"NO"<<endl;
        
// }

// int main()
// {

//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int k;
//         cin >> k;
//         int arr[k];

//         for (int j = 0; j < k; j++)
//         {
//             cin >> arr[j];
//         }
//         checkliar(arr, k);
//     }

//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum > n - 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}