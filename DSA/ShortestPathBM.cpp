#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    const int INF = 1e7;

    if (mat[n-1][n-1]!=0)
        return -1;

    vector<vector<int>> dis(n, vector<int>(n, INF));
    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    vis[n-1][n-1] = 1;
    dis[n-1][n-1] = 1;
    q.push({n-1,n-1});



    // 2) Multi-source BFS
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    while (!q.empty())
    {
        int i = q.front().first,
            j = q.front().second;
            q.pop();

        for (int d = 0; d < 8; d++)
        {
            int ni = i + dx[d], nj = j + dy[d];
            if (ni < 0 || ni >= n || nj < 0 || nj >= n)
                continue;

            if (mat[ni][nj]==0 && !vis[ni][nj])
            {
                // we found a neighbor at distance dis[i][j] + 1
                dis[ni][nj] = dis[i][j] + 1;
                vis[ni][nj] = 1;
                q.push({ni, nj});
            }
        }
    }

    if (dis[0][0]==INF)
        return -1;
    return dis[0][0];
}

int main()
{
    // vector<vector<int>> mat = {{1, 0, 1, 1, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 0, 1, 0, 1, 0, 1, 1}, {0, 0, 1, 0, 1, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 1, 1, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 1, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 1, 0}, {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}};
    // vector<vector<int>> mat = {{0, 1}, {1, 0}};
    vector<vector<int>> mat = {{0, 0, 0}, {1, 1, 0 }, {1, 1, 1}};
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

    // auto dis = updateMatrix(mat);
    // for (auto &row : dis)
    // {
    //     cout << "{ ";
    //     for (int x : row)
    //         cout << x << " ";
    //     cout << "}\n";
    // }
    cout<<shortestPathBinaryMatrix(mat);

    return 0;
}
