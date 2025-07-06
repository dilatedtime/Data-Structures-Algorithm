// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }


//         ll ans = LLONG_MAX;
//         int i = 0;
//         while (i < n) {

//             int v = a[i];
//             int l = i;
//             int r = i;

//             while (r+1<n && a[r+1]==v) {
//                 r++;
//             }
        
//             ll cost = (ll)l*v + (ll)(n-1-r)*v;
//             ans = min(ans, cost);

//             i = r+1;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(0);cin.tie(0);

int T;cin>>T;
while(T--){

int sz;cin>>sz;
vector<int>v(sz);
for(int k=0;k<sz;++k) cin>>v[k];

ll res=1e18;
int p=0;

while(p<sz){
int cur=v[p],L=p,R=p;

while(R+1<sz && v[R+1]==cur) ++R;

ll left=(ll)L*cur, right=(ll)(sz-1-R)*cur;
res=min(res,left+right);

p=R+1;
}

cout<<res<<'\n';
}
return 0;
}
