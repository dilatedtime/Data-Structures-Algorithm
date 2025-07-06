#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; 
      cin>>T;
    while(T--){
       int n,q; 
         cin>>n>>q;  // q is always 0 here tho
       string r0,r1; 
       cin>>r0>>r1;

       vector<int> p0, p1;
         for(int i=0;i<n;i++){
           if(r0[i]=='1') p0.push_back(i);
           if(r1[i]=='1') p1.push_back(i);
         }

       if(p0.empty()||p1.empty()|| (int)(p0.size()+p1.size()) < n+1){
           cout<<-1<<"\n";
           continue;
       }

       int k0 = p0.size(), k1 = p1.size();
       vector<long long> f0(k0+1,0), b1(k1+1,0);

        // build front-cost for row0
       for(int x=1; x<=k0; x++){
         long long d = llabs( p0[x-1] - (x-1) );
         f0[x] = f0[x-1] + d;
       }

        // build back-cost for row1
       for(int y=1; y<=k1; y++){
         long long d = llabs( p1[k1-y] - (n-y) );
         b1[y] = b1[y-1] + d;
       }

       long long ans = LLONG_MAX;
         for(int i=1;i<=n;i++){
           int t0 = i;
           int t1 = n+1-i;
           if(t0<=k0 && t1<=k1){
             long long c = f0[t0] + b1[t1];
             if(c < ans) ans = c;
           }
         }

       if(ans==LLONG_MAX) cout<<-1<<"\n";
       else             cout<<ans<<"\n";
    }

    return 0;
}
