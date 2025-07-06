// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // int max(int a, int b)
// // {

// //     if (a > b)
// //         return a;
// //     return b;
// // }

// int dfsrecur(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visarr, int &count, int r, int c)

// {

//     visarr[i][j] = 1;

//     int dx[] = {0, -1, 1, 0};
//     int dy[] = {-1, 0, 0, 1};

//     for (int d = 0; d < 4; d++)
//     {
//         int di = i + dx[d];
//         int dj = j + dy[d];

//         if (di >= 0 && dj >= 0 && di < r && dj < c)
//         {

//             if (visarr[di][dj] == 0 && grid[di][dj] == 1)
//             {
//                 grid[di][dj] = 2;
//                 count = max(count, dfsrecur(grid, di, dj, visarr, count, r, c));
//             }
//         }
//     }

//     return count;
// }

// int orangesRotting(vector<vector<int>> &grid)
// {

//     int count = 0;

//     int r = grid.size();
//     int c = grid[0].size();
//     vector<vector<int>> visarr(r, vector<int>(c, 0));

//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {

//             if (visarr[i][j] == 0 && grid[i][j] == 2)
//             {
//                 count++;
//                 count = max(count, dfsrecur(grid, i, j, visarr, count, r, c));
//             }
//         }
//     }

//     return count;

// }


// int main()
// {

//     vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
//     cout << orangesRotting(grid);
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

// Perform DFS and track rotting time (depth)
void dfsrecur(vector<vector<int>> &grid, int i, int j, int time, vector<vector<int>> &depth, int r, int c)
{
    // Boundary and invalid checks
    if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 0)
        return;

    // If this cell is already visited with less or equal time, skip
    if (depth[i][j] != -1 && time >= depth[i][j])
        return;

    // Set time for this cell
    depth[i][j] = time;

    // Directions: up, down, left, right
    int dx[] = {0, -1, 1, 0};
    int dy[] = {-1, 0, 0, 1};

    // Recursive DFS for all 4 directions
    for (int d = 0; d < 4; d++)
    {
        int ni = i + dx[d];
        int nj = j + dy[d];
        dfsrecur(grid, ni, nj, time + 1, depth, r, c);
    }
}

int orangesRotting(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> depth(r, vector<int>(c, -1));

    // Start DFS from all initially rotten oranges
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 2)
            {
                dfsrecur(grid, i, j, 0, depth, r, c);
            }
        }
    }

    int maxTime = 0;

    // Check result
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                // Unreachable fresh orange
                if (depth[i][j] == -1)
                    return -1;

                maxTime = max(maxTime, depth[i][j]);
            }
        }
    }

    return maxTime;
}

int main()
{
    vector<vector<int>> grid = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };

    cout << orangesRotting(grid) << endl; // Expected: 4
    return 0;
}

