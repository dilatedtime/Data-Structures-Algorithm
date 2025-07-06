// #include <bits/stdc++.h>
// using namespace std;

// int solve(long long a, long b)
// {

//     int count = 0;
//     while (a * b)
//     {
//         if (a % 10 == b % 10)
//         {
//             count++;
//         }
//         a = a / 10;
//         b = b / 10;
//     }
//     return count;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     long long l, r;
//     long long t;
//     cin >> t;
//     while (t--)

//     {
//         cin >> l >> r;
//         int small = 20;
//         for (int i = l; i <= r; i++)
//         {
//             small = min(small, solve(l, i) + solve(i, r));
//         }

//         cout << small << endl;
//     }

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// int doCount(long long p, long long q){  int cc=0;
//  while(p*q){ if(p%10 == q%10) cc++; p/=10; q/=10; }
//  return cc; }

// int main(){
//  ios::sync_with_stdio(false);
//  cin.tie(NULL);

//  long long L, R; int T;
//  cin>>T;
//  while(T--){
//  cin>>L>>R;
//  int mn = 1e9;
//  for(int i=L;i<=R;i++){ 
//   int t1 = doCount(L, i);
//   int t2 = doCount(i, R);
//   int sum = t1 + t2;
//   if(sum < mn) mn = sum; }
//   cout<<mn<<"\n";
//  }
//  return 0; }


#include <bits/stdc++.h>
using namespace std;

int matchCount(long long x, long long y){ int cnt = 0;
    while(x && y){ if((x % 10) == (y % 10)) cnt++; x /= 10; y /= 10; }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        long long L, R;
        cin >> L >> R;
        int best = INT_MAX;
        // brute-force all possible splits
        for(long long i = L; i <= R; ++i){
            int a = matchCount(L, i);
            int b = matchCount(i, R);
            best = min(best, a + b);
            if(best == 0) break; // can't get lower
        }
        cout << best << "\n";
    }
    return 0;
}
