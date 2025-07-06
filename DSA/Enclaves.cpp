#include <iostream>
#include <vector>
using namespace std;

void dfsrecur(int i, int j, vector<vector<int>> &board, int n, int m, vector<vector<int>> &vis)

{
    vis[i][j] = 1;

    int dx[] = {0, -1, 1, 0};
    int dy[] = {-1, 0, 0, 1};

    for (int d = 0; d < 4; d++)
    {
        int k = i + dx[d];
        int l = j + dy[d];

        if (k >= 0 && k < n && l >= 0 && l < m)
        {

            if (board[k][l] == 1 && vis[k][l] == 0)
            {
                vis[k][l] = 1;
                dfsrecur(k, l, board, n, m, vis);
            }
        }
    }
}

int numEnclaves(vector<vector<int>> &board)
{
    int count = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int i = 0, j = 0;
    // 1) Run DFS from any 1on the four borders
    // Top row (row = 0)
    for (int j = 0; j < m; j++)
    {
        if (board[0][j] == 1 && vis[0][j] == 0)
            dfsrecur(0, j, board, n, m, vis);
    }

    // Bottom row (row = n-1)
    for (int j = 0; j < m; j++)
    {
        if (board[n - 1][j] == 1 && vis[n - 1][j] == 0)
            dfsrecur(n - 1, j, board, n, m, vis);
    }

    // Left column (col = 0)
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 1 && vis[i][0] == 0)
            dfsrecur(i, 0, board, n, m, vis);
    }

    // Right column (col = m-1)
    for (int i = 0; i < n; i++)
    {
        if (board[i][m - 1] == 1 && vis[i][m - 1] == 0)
            dfsrecur(i, m - 1, board, n, m, vis);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1 && vis[i][j] == 0)
            {
                board[i][j] = 0;
                count++;
            }
        }
    }

    return count;
}

int main()
{

    vector<vector<int>> mat = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << numEnclaves(mat);

    return 0;
}
