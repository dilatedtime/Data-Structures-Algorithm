#include <iostream>
#include <vector>
#include <set>
using namespace std;

// LEETCODE

void dfsrecur(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visarr, int n, int m,set<vector<int>> &patterns, vector <int> &seq )
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
            if (visarr[k][l] == 0 && grid[k][l] == 1)
            {
                seq.push_back(d);
                dfsrecur(grid, k, l, visarr, n, m, patterns,seq);
                seq.push_back(d + 4);
            }
        }
    }
    // patterns.insert(seq);


}

int countDistinctIslands(vector<vector<int>> &grid)
{
    
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> visarr(n, vector<int>(m, 0));
    set<vector<int>> patterns;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)

        {

            if (visarr[i][j] == 0 && grid[i][j] == 1)
            {
                vector <int> seq;
                
                
                dfsrecur(grid, i, j, visarr, n, m, patterns,seq);
                patterns.insert(seq);
            }
        }
    }

    return patterns.size();
}

int main()
{

    // vector<vector<char>> grid = {{1,1,0,1,1}, {1,0,0,0,0}, {0,0,0,0,1}, {1,1,0,1,1}};
    vector<vector<int>> grid = {{1,1},{1,0},{0,0},{1,0},{1,1}}; 
    cout << countDistinctIslands(grid);
    return 0;
}
