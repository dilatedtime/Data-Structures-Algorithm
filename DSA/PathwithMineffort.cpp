// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cmath>
// #include <set>
// #include <limits.h>
// using namespace std;

// int minimumEffortPath(vector<vector<int>> &mat)
// {
//     int n = mat.size();
//     int m = mat[0].size();

//     vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
//     // vector<vector<int>> vis(n, vector<int>(m, 0));
//     set<vector<int>> st;

//     dis[n - 1][m - 1] = 0;
//     st.insert({0, n - 1, m - 1});

//     int dx[4] = {0, -1, 1, 0};
//     int dy[4] = {-1, 0, 0, 1};

//     while (!st.empty())
//     {
//         vector<int> triple = *st.begin();
//         int i = triple[1];
//         int j = triple[2];
//         st.erase(st.begin());

        

//         for (int d = 0; d < 4; d++)
//         {
//             int eff = triple[0];
//             int ni = i + dx[d], nj = j + dy[d];
//             if (ni < 0 || ni >= n || nj < 0 || nj >= m)
//                 continue;

//             else if (dis[ni][nj] == INT_MAX)
//             {
//                 dis[ni][nj] = max(eff, abs(mat[i][j]-mat[ni][nj]));
//                 st.insert({dis[ni][nj], ni, nj});
//             }
//             else if (dis[ni][nj] > max(eff, abs(mat[i][j]-mat[ni][nj])))
//             {
//                 st.erase({dis[ni][nj], ni, nj});
//                 dis[ni][nj] = max(eff, abs(mat[i][j]-mat[ni][nj]));
//                 st.insert({dis[ni][nj], ni, nj});
//             }
//         }
//     }

//     return dis[0][0];
// }

// int main()
// {
//     // vector<vector<int>> mat = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
//     vector<vector<int>> mat= {{1,2,3},{3,8,2},{5,3,5}};
    
//     // vector<vector<int>> mat = {
//     //     {1, 1, 0, 0, 1, 0, 0, 1, 1, 0},
//     //     {1, 0, 0, 1, 0, 1, 1, 1, 1, 1},
//     //     {1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
//     //     {0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
//     //     {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
//     //     {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
//     //     {0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
//     //     {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
//     //     {0, 1, 0, 1, 1, 0, 1, 1, 1, 1},
//     //     {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};

//     cout << minimumEffortPath(mat);

//     return 0;
// }

#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <limits.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    const int INF = INT_MAX;

    vector<vector<int>> dist(n, vector<int>(m, INF));
    set<tuple<int,int,int>> st;

    // start from bottom-right
    dist[n-1][m-1] = 0;
    st.emplace(0, n-1, m-1);

    const int dx[4] = {0, -1, 1,  0};
    const int dy[4] = {-1, 0, 0,  1};

    while (!st.empty()) {
        // grab the smallest-effort tuple
        auto it = st.begin();
        int eff = get<0>(*it);
        int i   = get<1>(*it);
        int j   = get<2>(*it);
        st.erase(it);

        // early exit if we've reached (0,0)
        if (i == 0 && j == 0)
            return eff;

        // relax 4 neighbors
        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d], nj = j + dy[d];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;

            int edgeCost = abs(mat[i][j] - mat[ni][nj]);
            int nextEff = (eff > edgeCost ? eff : edgeCost);

            if (nextEff < dist[ni][nj]) {
                // remove old entry if present
                if (dist[ni][nj] != INF)
                    st.erase(make_tuple(dist[ni][nj], ni, nj));
                dist[ni][nj] = nextEff;
                st.emplace(nextEff, ni, nj);
            }
        }
    }

    // unreachable case (shouldn't happen)
    return dist[0][0];
}

int main() {
    vector<vector<int>> mat = {
        {1,2,3},
        {3,8,2},
        {5,3,5}
    };
    cout << minimumEffortPath(mat) << "\n";  // prints 2
    return 0;
}
