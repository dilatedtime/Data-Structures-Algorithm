#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(const vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    const int INF = 1e7;

    vector<vector<int>> dis(n, vector<int>(m, INF));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    // 1) Enqueue all zero-cells first
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                dis[i][j] = 0;
                vis[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    // 2) Multi-source BFS
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};

    while (!q.empty())
    {
        int i = q.front().first,
            j = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ni = i + dx[d], nj = j + dy[d];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;

            if (!vis[ni][nj])
            {
                // we found a neighbor at distance dis[i][j] + 1
                dis[ni][nj] = dis[i][j] + 1;
                vis[ni][nj] = 1;
                q.push({ni, nj});
            }
        }
    }

    return dis;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 1, 1, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 0, 1, 0, 1, 0, 1, 1}, {0, 0, 1, 0, 1, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 1, 1, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 1, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 1, 0}, {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}};

    // vector<vector<int>> mat = {
    //     {1, 1, 0, 0, 1, 0, 0, 1, 1, 0},
    //     {1, 0, 0, 1, 0, 1, 1, 1, 1, 1},
    //     {1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
    //     {0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    //     {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    //     {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    //     {0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
    //     {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    //     {0, 1, 0, 1, 1, 0, 1, 1, 1, 1},
    //     {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};

    auto dis = updateMatrix(mat);
    for (auto &row : dis)
    {
        cout << "{ ";
        for (int x : row)
            cout << x << " ";
        cout << "}\n";
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;


// vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
// {
//     int n = mat.size();
//     int m = mat[0].size();
//     vector<vector<int>> dis(n, vector<int>(m, 10000000));
//     vector<vector<int>> vis(n, vector<int>(m, 0));
//     queue<int> q;
//     for (int i = 0; i < n; i++)
//     {

//         for (int j = 0; j < m; j++)
//         {

//             if (mat[i][j] == 0)
//             {
//                 dis[i][j] = 0;
//                 continue;
//             }
//             else if (mat[i][j] != 0 && !vis[i][j])
//             {
//                 q.push(mat[i][j]);

//                 while (!q.empty())
//                 {
//                     int node = q.front();
//                     q.pop();

//                     int dx[] = {0, -1, 1, 0};
//                     int dy[] = {-1, 0, 0, 1};

//                     for (int d = 0; d < 4; d++)
//                     {
//                         int k = i + dx[d];
//                         int l = j + dy[d];

//                         if (k >= 0 && k < n && l >= 0 && l < m)
//                         {
//                             if (mat[k][l] == 0)
//                             {
//                                 dis[i][j] = min(dis[i][j], 1);
//                             }
//                             else if (!vis[k][l])
//                             {
//                                 q.push(mat[i][j]);
//                             }

//                             if (vis[k][l] && dis[k][l] != 10000000)
//                                 dis[i][j] = min(dis[i][j], 1 + dis[k][l]);
//                         }
//                     }
//                 }
//             }

//             vis[i][j] = 1;
//         }

//     }

//     return dis;
// }

// int main()
// {

//     // vector<vector<int>> mat = {{1,0,1,1,0,0,1,0,0,1},{0,1,1,0,1,0,1,0,1,1},{0,0,1,0,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,1},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,1,1,1,0,1,0},{0,1,0,1,0,1,0,0,1,1},{1,0,0,0,1,1,1,1,0,1},{1,1,1,1,1,1,1,0,1,0},{1,1,1,1,0,1,0,0,1,1}};
//     // vector<vector<int>> mat = {{1, 1, 1}, {1, 1, 1}, {1, 0, 1}};
//     vector<vector<int>> mat = {{1, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};
//     vector<vector<int>> dis = updateMatrix(mat);
//     for (int i = 0; i < dis.size(); i++)
//     {

//         cout << "{";
//         for (int j = 0; j < dis[0].size(); j++)
//         {
//             cout << "," << dis[i][j];
//         }
//         cout << "}" << ",";
//     }

//     return 0;
// }

// void dfsrecur(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dis, int n, int m, vector<vector<int>> &vis)

// {
//     vis[i][j] = 1;

//     int dx[] = {0, -1, 1, 0};
//     int dy[] = {-1, 0, 0, 1};

//     for (int d = 0; d < 4; d++)
//     {
//         int k = i + dx[d];
//         int l = j + dy[d];

//         if (k >= 0 && k < n && l >= 0 && l < m)
//         {
//             if (mat[k][l] == 0)
//             {
//                 dis[i][j] = min(dis[i][j], 1);
//             }
//             else if (!vis[k][l])
//             {
//                 dfsrecur(k, l, mat, dis, n, m, vis);
//             }

//             if (vis[k][l] && dis[k][l] != 10000000)
//                 dis[i][j] = min(dis[i][j], 1 + dis[k][l]);
//         }
//     }

//     vis[i][j] = 0;
// }

// vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
// {
//     int n = mat.size();
//     int m = mat[0].size();
//     vector<vector<int>> dis(n, vector<int>(m, 10000000));
//     vector<vector<int>> vis(n, vector<int>(m, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {

//             if (mat[i][j] == 0)
//             {
//                 dis[i][j] = 0;
//                 continue;
//             }
//             else if (mat[i][j] != 0 && !vis[i][j])
//                 dfsrecur(i, j, mat, dis, n, m, vis);
//                 // vis[i][j] = 1;
//         }
//     }

//     return dis;
// }

// int main()
// {

//     // vector<vector<int>> mat = {{1,0,1,1,0,0,1,0,0,1},{0,1,1,0,1,0,1,0,1,1},{0,0,1,0,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,1},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,1,1,1,0,1,0},{0,1,0,1,0,1,0,0,1,1},{1,0,0,0,1,1,1,1,0,1},{1,1,1,1,1,1,1,0,1,0},{1,1,1,1,0,1,0,0,1,1}};
//     // vector<vector<int>> mat = {{1, 1, 1}, {1, 1, 1}, {1, 0, 1}};
//     vector<vector<int>> mat = {{1,1,0,0,1,0,0,1,1,0},{1,0,0,1,0,1,1,1,1,1},{1,1,1,0,0,1,1,1,1,0},{0,1,1,1,0,1,1,1,1,1},{0,0,1,1,1,1,1,1,1,0},{1,1,1,1,1,1,0,1,1,1},{0,1,1,1,1,1,1,0,0,1},{1,1,1,1,1,0,0,1,1,1},{0,1,0,1,1,0,1,1,1,1},{1,1,1,0,1,0,1,1,1,1}};
//     vector<vector<int>> dis = updateMatrix(mat);
//     for (int i = 0; i < dis.size(); i++)
//     {

//         cout << "{";
//         for (int j = 0; j < dis[0].size(); j++)
//         {
//             cout << "," << dis[i][j];
//         }
//         cout << "}" << ",";
//     }

//     return 0;
// }