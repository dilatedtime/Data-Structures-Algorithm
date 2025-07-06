#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <tuple>
#include <limits.h>
using namespace std;

vector<int> bellmanFord(int v, vector<vector<int>> &edges, int src)
{
    int e = edges.size();
    vector<int> dis(v, 100000000);
    dis[src] = 0;
    // vector<vector<pair<int, int>>> adj(v);
    // for (int i = 0; i < e; i++)
    // {

    //     int u = edges[i][0] - 1;
    //     int l = edges[i][1] - 1;
    //     int w = edges[i][2];

    //     adj[u].push_back({w, l});
    // }

    // queue<pair<long long, int>> st;

    for (int j = 0; j < v - 1; j++)
    {
        bool changed = false;

        for (int i = 0; i < edges.size(); i++)
        {

            int u = edges[i][0];
            int k = edges[i][1];
            int w = edges[i][2];

            if (dis[u] != 100000000 && dis[u] + w < dis[k])

            {
                dis[k] = dis[u] + w;
                changed = true;
            }
        }

        if (!changed)
            break;
    }

    int flag = 1;
    vector<int> last;
    last.push_back(-1);
    for (auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        if (dis[u] != 100000000 && dis[u] + w < dis[v])
        {
            return last;
        }
    }

    return dis;
}

int main()
{
    vector<vector<int>> mat = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};

    vector<int> final = bellmanFord(5, mat, 0);

    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i] << ",";
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <limits.h>
// using namespace std;

// vector<int> bellmanFord(int n, const vector<vector<int>>& edges, int src) {
//     const int INF = 100000000;
//     vector<int> dis(n, INF);
//     dis[src] = 0;

//     // Relax all edges (n-1) times
//     for (int pass = 0; pass < n - 1; ++pass) {
//         bool changed = false;
//         for (auto& e : edges) {
//             int u = e[0];
//             int v = e[1];
//             int w = e[2];
//             // only relax if u is reachable
//             if (dis[u] != INF && dis[u] + w < dis[v]) {
//                 dis[v] = dis[u] + w;
//                 changed = true;
//             }
//         }
//         if (!changed) break;  // no update in this pass → done early
//     }

//     // (Optional) detect negative cycles
//     for (auto& e : edges) {
//         int u = e[0], v = e[1], w = e[2];
//         if (dis[u] != INF && dis[u] + w < dis[v]) {
//             cerr << "Negative cycle detected\n";
//             break;
//         }
//     }

//     return dis;
// }

// int main() {
//     vector<vector<int>> mat = {
//         {1, 3,  2},
//         {4, 3, -1},
//         {2, 4,  1},
//         {1, 2,  1},
//         {0, 1,  5}
//     };

//     auto final = bellmanFord(5, mat, /*src=*/0);

//     for (int d : final) {
//         if (d == 100000000) cout << "INF,";
//         else           cout << d << ",";
//     }
//     cout << "\n";
//     return 0;
// }
