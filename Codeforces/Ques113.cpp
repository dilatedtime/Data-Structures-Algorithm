// #include<bits/stdc++.h>
// using namespace std;


// void solve(){
    
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     long long t; cin>>t;
//     while(t--) solve();
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


static const long long MODX = 1000000007;

void runTest() {
    long long N, M;
    cin >> N >> M;
    
    if (M < N || M > N*(N+1)/2) {
        cout << "-1\n";
        return;
    }

    
    int center = -1;
    for (int idx = 1; idx <= N; ++idx) {
        long long rem = M - idx;
        long long minNeed = N - 1;
        long long maxNeed = (long long)(idx - 1) * idx / 2
                          + (long long)(N - idx) * idx;
        if (rem >= minNeed && rem <= maxNeed) {
            center = idx;
            break;
        }
    }
    if (center < 0) {
        cout << "-1\n";
        return;
    }
    cout << center << "\n";

    vector<pair<long long,int>> gainList;
    gainList.reserve(N-1);
    for (int i = 1; i <= N; ++i) {
        if (i == center) continue;
        long long g = min(i, center) - 1;
        gainList.push_back({g, i});
    }
    sort(gainList.begin(), gainList.end(),
         [](auto &a, auto &b){ return a.first > b.first; });

    long long delta = (M - center) - (N - 1);
    vector<bool> connect(N+2,false), used(N+2,false);

    for (auto &pr : gainList) {
        if (delta >= pr.first) {
            connect[pr.second] = true;
            delta -= pr.first;
        }
    }
    if (delta != 0) {
        cout << "-1\n";
        return;
    }

    used[center] = true;
    int pivot = (center == 1 ? 2 : 1);
    if (pivot == center && N >= 3) pivot = 3;
    vector<pair<int,int>> edges;
    if (N > 1) {
        edges.push_back({center, pivot});
        used[pivot] = true;
    }
    for (int v = 1; v <= N; ++v) {
        if (!used[v] && connect[v]) {
            edges.push_back({center, v});
            used[v] = true;
        }
    }
    for (int v = 1; v <= N; ++v) {
        if (!used[v]) {
            edges.push_back({pivot, v});
        }
    }

    for (auto &e : edges) {
        cout << e.first << " " << e.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests=0;
    cin>>tests;
    while (tests--) runTest();
    return 0;
}
