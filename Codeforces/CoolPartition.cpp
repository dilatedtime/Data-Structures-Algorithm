

#include<bits/stdc++.h>
using namespace std;
int main( ) {
ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int k; cin>>k;
        vector<long long> v(k);
        for(int p=0;p<k;++p)
        cin>>v[p];
        
        unordered_set<long long> A,B,C;
        A.insert(v[0]);
        int z=1;
        
        for(int l=1;l<k;++l){
            long long y=v[l];
            
            C.insert(y);
            
            if(A.find(y)!=A.end()){
               { B.insert(y);}
            }
            
            if(B.size()==A.size()){
                {++z;
                A=move(C);
                B.clear();
                C.clear();}
            }
        }
        cout<<z<<"\n";
    }
    return 0;
}
