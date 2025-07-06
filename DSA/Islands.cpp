
#include <iostream>
#include <vector>
using namespace std;

// LEETCODE

void dfsrecur(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &visarr, int &count, int n, int m)
{
    visarr[i][j] = 1;

    int dx[] = {0, -1, 1, 0};
    int dy[] = {-1, 0, 0, 1};

   
    for (int d = 0; d < 4; d++)
    {
        int k = i + dx[d];
        int l = j + dy[d];


        if (k >= 0 && k < n && l >= 0 && l < m)
        {
            if (visarr[k][l] == 0 && grid[k][l] == '1')
            {

                dfsrecur(grid, k, l, visarr, count, n, m);
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visarr(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)

        {

            if (visarr[i][j] == 0 && grid[i][j] == '1')
            {
                count++;
                dfsrecur(grid, i, j, visarr, count, n, m);
            }
        }
    }

    return count;
}

int main()
{

    vector<vector<char>> grid = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
    cout << numIslands(grid);
    return 0;
}

// GEEKSFORGEEKS

// void dfsrecur(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &visarr, int &count, int n, int m)
// {

//     visarr[i][j] = 1;
//     for (int k = i - 1; k <= i + 1; k++)
//     {
//         for (int l = j - 1; l <= j + 1; l++)
//         {
//             if (l == j && k == i)
//                 continue;

//             if (k >= 0 && k < n && l >= 0 && l < m)
//             {
//                 if (visarr[k][l] == 0 && grid[k][l] == '1')
//                 {

//                     dfsrecur(grid, k, l, visarr, count, n, m);
//                 }
//             }
//         }
//     }
// }

// int numIslands(vector<vector<char>> &grid)
// {
//     int count = 0;
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> visarr(n, vector<int>(m, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)

//         {

//             if (visarr[i][j] == 0 && grid[i][j] == '1')
//             {
//                 count++;
//                 dfsrecur(grid, i, j, visarr, count, n, m);
//             }
//         }
//     }

//     return count;
// }

// int main()
// {

//     vector<vector<char>> grid = {{'L', 'L', 'W', 'W', 'W'}, {'W', 'L', 'W', 'W', 'L'}, {'L', 'W', 'W', 'L', 'L'}, {'W', 'W', 'W', 'W', 'W'}, {'L', 'W', 'L', 'L', 'W'}};
//     cout << numIslands(grid);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// void dfsrecur(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &visarr, int n, int m)
// {
//     visarr[i][j] = 1;

//     // Explore all 8 directions (optional; you can limit to 4 if needed)
//     int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
//     int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//     for (int d = 0; d < 8; d++)
//     {
//         int ni = i + dx[d];
//         int nj = j + dy[d];

//         if (ni >= 0 && ni < n && nj >= 0 && nj < m)
//         {
//             if (visarr[ni][nj] == 0 && grid[ni][nj] == 'L')
//             {
//                 dfsrecur(grid, ni, nj, visarr, n, m);
//             }
//         }
//     }
// }

// int numIslands(vector<vector<char>> &grid)
// {
//     int count = 0;
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> visarr(n, vector<int>(m, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (visarr[i][j] == 0 && grid[i][j] == 'L')
//             {
//                 count++; // New island found
//                 dfsrecur(grid, i, j, visarr, n, m);
//             }
//         }
//     }

//     return count;
// }

// int main()
// {
//     vector<vector<char>> grid = {
//         {'L', 'L', 'W', 'W', 'W'},
//         {'W', 'L', 'W', 'W', 'L'},
//         {'L', 'W', 'W', 'L', 'L'},
//         {'W', 'W', 'W', 'W', 'W'},
//         {'L', 'W', 'L', 'L', 'W'}};

//     cout << numIslands(grid) << endl;
//     return 0;
// }
