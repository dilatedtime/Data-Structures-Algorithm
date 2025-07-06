// // #include <bits/stdc++.h>
// // using namespace std;

// // vector<pair<int, int>> ops;

// // void swap_adj(vector<int>& arr, int idx, int arr_id) {
// //     swap(arr[idx], arr[idx + 1]);
// //     ops.emplace_back(arr_id, idx + 1);
// // }

// // void swap_cross(vector<int>& a, vector<int>& b, int i) {
// //     swap(a[i], b[i]);
// //     ops.emplace_back(3, i + 1);
// // }

// // void sort_with_operations(vector<int>& arr, int arr_id) {
// //     int n = arr.size();
// //     for (int pass = 0; pass < n; ++pass) {
// //         for (int i = 0; i + 1 < n; ++i) {
// //             if (arr[i] > arr[i + 1]) {
// //                 swap_adj(arr, i, arr_id);
// //             }
// //         }
// //     }
// // }

// // void solve_test_case(int n, vector<int> a, vector<int> b) {
// //     ops.clear();

// //     for (int i = 0; i < n; ++i) {
// //         if (a[i] > b[i]) {
// //             swap_cross(a, b, i);
// //         }
// //     }
// //     sort_with_operations(a, 1);
// //     sort_with_operations(b, 2);

// //     for (int i = 0; i < n; ++i) {
// //         if (a[i] > b[i]) {
// //             swap_cross(a, b, i);
// //         }
// //     }

// //     sort_with_operations(a, 1);
// //     sort_with_operations(b, 2);

// //     cout << ops.size() << '\n';
// //     for (auto [type, idx] : ops) {
// //         cout << type << ' ' << idx << '\n';
// //     }
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         int n;
// //         cin >> n;
// //         vector<int> a(n), b(n);
// //         for (int& x : a) cin >> x;
// //         for (int& x : b) cin >> x;

// //         solve_test_case(n, a, b);
// //     }
// //     return 0;
// // }



// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int,int>> op; // store ops

// void f1(vector<int>& x,int p){ x[p] > x[p+1] ? swap(x[p],x[p+1]), op.push_back({1,p+1}) : void(); }

// void f2(vector<int>& u, vector<int>& v,int j){ swap(u[j],v[j]); op.push_back({3,j+1}); }

// void f3(vector<int>& c,int id){
//  int m=c.size();
//  for(int s=0;s<m;s++){
//   for(int t=0;t+1<m;t++)
//     if(c[t] > c[t+1]){
//         swap(c[t],c[t+1]);
//         op.push_back({ id, t+1 });
//     }
//  }
// }

// void solveIt(){
//  int n;cin>> n;
//  vector<int>a(n),b(n);
//  for(auto &e:a)cin>>e; for(auto &e:b)cin>>e;

//  // first pass cross
//  for(int i=0;i<n;i++){
//     if(a[i] > b[i]) f2(a,b,i);
//  }
//  // sort
//  f3(a,1);
//  f3(b,2);
//  // second cross
//  for(int i=0;i<n;i++){
//     if( a[i] > b[i] ){
//         swap(a[i], b[i]); op.push_back({3,i+1});
//     }
//  }
//  f3(a,1);
//  f3(b,2);

//  cout<< op.size() <<"\n";
//  for(auto &pp:op){ cout<< pp.first << " " << pp.second <<"\n"; }
// }

// int main(){
//  ios::sync_with_stdio(false);
//  cin.tie(NULL);
//  int tt;
//  cin>>tt;
//  while(tt--){ op.clear(); solveIt(); }
//  return 0;
// }
    

#include <bits/stdc++.h>
using namespace std;



vector<pair<int,int>> opsLog;



void sw1(vector<int>&arr1,int idx){
    if(arr1[idx]>arr1[idx+1]){
        swap(arr1[idx], arr1[idx+1]);
        opsLog.push_back({1, idx+1});
    }
}

void sw3(vector<int>&u, vector<int>&v, int pos){
    swap(u[pos], v[pos]);
    opsLog.push_back({3, pos+1});
}

void bubbleList(vector<int>&lst, int id){
    int len=lst.size();
    for(int a=0;a<len;++a){
        for(int b=0;b+1<len;b++){
            if(lst[b]>lst[b+1]){
                swap(lst[b], lst[b+1]);
                opsLog.push_back({id, b+1});
            }
        }
    }
}

void doCase(){
    int sz; cin>>sz;
    vector<int>A(sz),B(sz);
    for(int i=0;i<sz;i++)cin>>A[i];
    for(int i=0;i<sz;i++)cin>>B[i];
    for(int i=0;i<sz;i++)if(A[i]>B[i])sw3(A,B,i);
    bubbleList(A,1);
    bubbleList(B,2);
    for(int i=0;i<sz;i++){
        if(A[i]>B[i]){
            swap(A[i], B[i]);
            opsLog.push_back({3, i+1});
        }
    }
    bubbleList(A,1);
    bubbleList(B,2);
    cout<<opsLog.size()<<"\n";
    for(auto&p:opsLog)cout<<p.first<<" "<<p.second<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        opsLog.clear();
        doCase();
    }
    return 0;
}