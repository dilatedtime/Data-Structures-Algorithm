#include<bits/stdc++.h>
using namespace std;


// void solve(){
    
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    long long t; cin>>t;
    while(t--) 
    {
        cin>>n>>k;

        for (int i = 0; i < k; i++)
        {
            cout<<"1";
        }
        
        for (int j = 0; j < n-k; j++)
        {
            cout<<"0";
        }
        cout<<endl;



    }
    // solve();
    return 0;
}