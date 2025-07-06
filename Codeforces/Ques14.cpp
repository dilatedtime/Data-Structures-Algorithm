// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int z, x, y;
//     long long t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> x >> y >> z;
//         int n = x + y + z;
//         if (y + 2 * z >= n)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
//     // solve();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

#define lol return
#define bb break

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int TC;  cin>>TC;
    while(TC--){
        int x0,x1,x2;
        cin>>x0>>x1>>x2;
        bool flag=false;
        int slots=x2+1;
        if(x1>0){
            int freeSlots=slots-x0;
            flag = freeSlots>0;
        } else {
            flag = x0<=slots;
        }
        if(flag) cout<<"Yes\n";
        else     cout<<"No\n";
    }
    lol 0;
}
