// // #include<bits/stdc++.h>
// // using namespace std;


// // void solve(){
    
// // }

// // int main(){
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);
// //     cout.tie(nullptr);

// //     long long t; cin>>t;
// //     while(t--) solve();
// //     return 0;
// // }



// #include <bits/stdc++.h>
// using namespace std;

// #define all(a) (a).begin(), (a).end()
// #define endl "\n"
// #define vec vector
// #define pii pair<int, int>
// #define se second
// #define fi first
// #define pb push_back
// #define maxel(v) *max_element(v.begin(), v.end())
// #define minel(v) *min_element(v.begin(), v.end())
// #define yes cout << "YES\n";
// #define m1 cout << "-1\n";
// #define no cout << "NO\n";
// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double ld;
// const ll mod = 1e9 + 7;
// const ll mod2 = 1e9 + 9;
// const ll mod3 = 998244353;
// const double pi = 3.141592653589793238;
// const long double EPS = 1e-9;
// const int MAXN = 1e5 * 5;
// const int LOGN = __lg(MAXN) + 1;

// void solve() {
//     int n, s;
//     cin >> n >> s;
//     int res = 0;
//     for (int i = 0; i < n; ++i) {
//         int dx, dy, xi, yi;
//         cin >> dx >> dy >> xi >> yi;
//         if (dx == dy) {
//             if ((xi - yi) % s == 0) {
//                 res++;
//             }
//         } else {
//             if ((xi + yi) % s == 0) {
//                 res++;
//             }
//         }
//     }
//     cout << res << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

int T; // test cases

void slv()
{
 int n,s;cin>>n>>s;
 int r=0;
 for(int i=0;i<n;i++)
 {
  int a,b,p,q; cin>>a>>b>>p>>q;

  if(a==b)
  {
   int d=p-q;
   if(d%s==0) r++;
  }
  else
  {
   int d=p+q;
   if(d%s==0) r++;
  }
 }
 cout<<r<<"\n";
}

int main( )
{
 ios_base::sync_with_stdio(false);
 cin.tie(0);

 cin>>T;
 while(T--)
 {
  slv();
 }

 return 0;
}

