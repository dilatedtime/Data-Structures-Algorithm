// #include <bits/stdc++.h>
// #include <vector>
// using namespace std;


// int fbn(int n)
// {
//     if (n <= 1)
//     {
//         return n;
//     }
//     return fbn(n - 1) + fbn(n - 2);
// }


// int solve(int n, int w, int l, int h)
// {
//     if (h >= fbn(n) + fbn(n - 1) && w >= fbn(n) && l >= fbn(n))
//         return 1;
//     else
//         return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     long long t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin>>n>>m;
//         int w, l, h;
//         vector<int>s;
//         for (int i = 0; i < m; i++)
//         {
//             cin >> w >> l >> h;
//             s.push_back(solve(n, w, l, h));
//         }

       
//     }
    
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

// Efficient Fibonacci using memoization
int fbn(int n) {
    if (n == 1 || n== 0) return 1;
    else
    return fbn (n-2) + fbn(n - 1);
}

// Check if box fits based on Fibonacci
int solve(int n, int w, int l, int h) {
    int f1 = fbn(n);
    int f2 = fbn(n - 1);
    if (h >= (f1 + f2) && w >= f1 && l >= f1 || l >= (f1 + f2) && h >= f1 && w >= f1 || w >= (f1 + f2) && h >= f1 && l >= f1  ) 
    return 1;
    else 
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> s(m);

        for (int i = 0; i < m; i++) {
            int w, l, h;
            cin >> w >> l >> h;
            s[i] = to_string(solve(n, w, l, h));
        }
        
        for (const auto &val : s) {
            cout << val;
        }
        cout << "\n";
    }

    return 0;
}
