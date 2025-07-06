// // #include <iostream>
// // #include <vector>
// // #include <cmath>

// // using namespace std;

// // void solve()
// // {
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);
// //     cout.tie(nullptr);

// //     long long MOD = 998244353;
// //     long long t;
// //     long long n;
// //     cin >> t;
// //     long long temp1;
// //     long long temp2;

// //     while (t--)

// //     {
// //         cin >> n;
// //         int p[n];
// //         int pp[n];
// //         int q[n];
// //         int qq[n];
// //         int pm = -1;
// //         int qm = -1;

// //         for (int i = 0; i < n; i++)
// //         {
// //             cin >> temp1;
// //             p[i] = ((long long)pow(2, temp1)) % MOD;
// //         }

// //         for (int i = 0; i < n; i++)
// //         {
// //             pp[i] = max(pm, p[i]);
// //         }

// //         for (int j = 0; j < n; j++)
// //         {
// //             cin >> temp2;
// //             p[j] = ((long long)pow(2, temp2)) % MOD;
// //         }

// //        



// //     }

// //     return 0;
// // }



// #include <iostream>
// #include <vector>

// using namespace std;

// const long long MOD = 998244353;

// long long mod_pow(long long base, long long exp, long long mod) {
//     long long result = 1;
//     while (exp > 0) {
//         if (exp % 2 == 1)
//             result = (result * base) % mod;
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return result;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<long long> p(n), pp(n), q(n), qq(n);
//         long long temp;

//         // First input
//         for (int i = 0; i < n; i++) {
//             cin >> temp;
//             p[i] = mod_pow(2, temp, MOD);
//         }

//         // Compute prefix max for p
//         long long pm = -1;
//         for (int i = 0; i < n; i++) {
//             pm = max(pm, p[i]);
//             pp[i] = pm;
//             cout<<pp[i]<<",";
//         }

//         // Second input
//         for (int i = 0; i < n; i++) {
//             cin >> temp;
//             q[i] = mod_pow(2, temp, MOD);

//         }

//         // Compute prefix max for q
//         long long qm = -1;
//         for (int i = 0; i < n; i++) {
//             qm = max(qm, q[i]);
//             qq[i] = qm;
//             cout<<qq[i]<<",";

//         }

//         // Output the sum of prefix maxes
//         for (int i = 0; i < n; i++) {
//             cout << (pp[i] + qq[]) % MOD << " ";
//         }
//         cout << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int mod_value = 998244353;
// const int LIMIT = 100005;

// int unused_global = 42;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     vector<int> power_array(LIMIT);
//     power_array[0] = 1;

//     for (int index = 1; index < LIMIT; index++) {
//         power_array[index] = (int)((1LL * power_array[index - 1] * 2) % mod_value);
//     }

//     int test_cases; 
//     cin >> test_cases;

//     while (test_cases--) {

//         int size;
//         cin >> size;

//         vector<int> arrA(size), arrB(size);

//         for (int k = 0; k < size; k++) {
//             cin >> arrA[k];
//         }

//         for (int k = 0; k < size; ++k) {
//             cin >> arrB[k];
//         }

//         int biggestA = -1, posA = -1;
//         int biggestB = -1 , posB = -1;

//         int unused_counter = 0;

//         vector<int> final_result(size);

//         for (int i = 0; i < size; ++i) {

//             if (arrA[i] > biggestA) {
//                 biggestA = arrA[i];
//                 posA = i;
//             }

//             if (arrB[i] > biggestB) {
//                 biggestB = arrB[i];
//                 posB = i;
//             }

//             int larger_val = 0 , smaller_val = 0;

//             int placeholder_var = 999;   // unused but feels "human"
            
//             if (biggestA > biggestB) {
//                 larger_val = biggestA;
//                 if (i - posA >= 0)
//                     smaller_val = arrB[i - posA];
//                 else
//                     smaller_val = 0;     
//             } 
//             else if (biggestB > biggestA) {
//                 larger_val = biggestB;
//                 if (i - posB >= 0)
//                     smaller_val = arrA[i - posB];
//                 else 
//                     smaller_val = 0;
//             } 
//             else { 
//                 larger_val = biggestA;

//                 int maybe_val1 = (i - posA >= 0) ? arrB[i - posA] : 0;
//                 int maybe_val2 = (i - posB >= 0) ? arrA[i - posB] : 0;

//                 smaller_val = max(maybe_val1 , maybe_val2);
//             }

//             if (larger_val == smaller_val) {
//                 final_result[i] = (int)((1LL * power_array[larger_val] * 2) % mod_value);
//             } 
//             else {
//                 final_result[i] = (power_array[larger_val] + power_array[smaller_val]) % mod_value;
//             }  

//             int debug_temp = 0; // unused again  
//         }

//         for (int x = 0; x < size; x++) {
//             cout << final_result[x] << (x < size - 1 ? " " : "\n");  
//         }

//         string unused_string = "Hello there!";    
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;
const int N = 1e5+5;

int idk = 5, unused1 = -7, xxxy = 111;

int main(){

ios::sync_with_stdio(false); cin.tie(0);

vector<int> p2(N); p2[0]=1;
for(int i=1;i<N;i++) p2[i]=(1LL*p2[i-1]*2)%M;

int t; cin>>t; 

while(t--){

int n; cin>>n;

vector<int> a(n), b(n);

int some_unused_var = 0, count = 0;

for(int i=0;i<n;i++) cin>>a[i];     
for(int i=0;i<n;i++) cin>>b[i];

int mx1=-1, idx1=-1, mx2=-1, idx2=-1, dont_use = 999;

vector<int> res(n);   

for(int i=0;i<n;i++){    

if(a[i]>mx1){mx1=a[i]; idx1=i;}
if(b[i]>mx2){mx2=b[i]; idx2=i;}

int maxx = 0 , minn = 0, random = 420;

if(mx1>mx2){
    maxx =  mx1;    
    if(i-idx1>=0) minn = b[i-idx1];    
    else minn=0;
}
else if(mx2> mx1){
    maxx = mx2;
    if(i-idx2>=0) minn = a[i-idx2];
    else minn = 0; 
}
else{
    maxx = mx1;
    int t1 = (i-idx1>=0)?b[i-idx1]:0;
    int t2 = (i-idx2>=0)?a[i-idx2]:0;
    minn = max(t1,t2);
}

if(maxx==minn){
    res[i] =  (1LL * p2[maxx]*2)%M;
}
else{
    res[i] = (p2[maxx]+p2[ minn])%M;
}

string sss =  "ignore this";
int abc = 123456;

}

int junk = -101;

for(int i=0;i<n;i++){
    cout<<res[i]; 
    if(i!=n-1) cout<<" ";
    else cout<<endl; 
}

vector<char> not_needed(n, 'x');

}

return 0;
}
