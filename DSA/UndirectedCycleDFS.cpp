#include <iostream>
#include <queue>
// #include <algorithm>
#include <vector>
using namespace std;

// LEETCODE

bool dfsrecur(vector<vector<int>> &adj, int i, int parent, vector<int> &visarr)
{
    visarr[i] = 1;

    for (int j = 0; j < adj[i].size(); j++)
    {
        if (!visarr[adj[i][j]])
        {
            if (dfsrecur(adj, adj[i][j], i, visarr))
                return 1;
        }

        else if(adj[i][j]!=parent)
            return 1;
    }

    return 0;
}

bool isCycle(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(v);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visarr(v, 0);
    for (int i = 0; i < v; i++) {
        if (!visarr[i]) {
            if (dfsrecur(adj, i, -1, visarr)) 
                return true;
        }
    }
    return false;
}




int main()
{

    vector<vector<int>> edges = {{0, 1},{0,2}, {1, 2}, {2, 3}};
    cout << isCycle(4, edges);
    return 0;
}
