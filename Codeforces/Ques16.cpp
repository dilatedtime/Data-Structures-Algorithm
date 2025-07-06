#include <bits/stdc++.h>
using namespace std;
typedef long long L;

bool chk(L M, const vector<L>& a, const vector<L>& b) {
    L tot = 0;
    int n = a.size();
    vector<L> cap(n);
    for(int i=0;i<n;i++){
        L canSelf = 0;
        if (M > a[i]) {
            canSelf = M - a[i];
            if (canSelf > b[i]) canSelf = b[i];
        }
        tot += (b[i] - canSelf);
        L apr = a[i] + canSelf;
        L c = (M - apr) / 2;
        if (c < 0) c = 0;
        cap[i] = c;
    }
    L s = 0;
    for (L c: cap) {
        s += c;
        if (s >= tot) return true;
    }
    return s >= tot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin>>t)) return 0;
    while (t--)  {
        int n;
        cin>>n;
        vector<L> a(n), b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        // find lower bound: max of a[]
        L mx=LLONG_MIN;
        for(int i=0;i<n;i++){
            if(a[i]>mx) mx=a[i];
        }
        L lo = mx;
        L hi = mx;
        for(int i=0;i<n;i++){
            hi += b[i];
        }
        L ans = hi;

        while (lo <= hi) {
            L mid = lo + (hi - lo)/2;
            bool ok = chk(mid, a, b);
            if (ok) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // Print answer
        cout<<ans;
        if (t>0) cout<<"\n";
    }
    return 0;
}
