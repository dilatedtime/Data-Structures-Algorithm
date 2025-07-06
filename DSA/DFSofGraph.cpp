#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfsrecur(vector<vector<int>> &adj, int node, vector<int> &dfsres, vector<int> &visarr)
{
    visarr[node] = 1;
    dfsres.push_back(node);

    for (auto val : adj[node])
    {
        if (visarr[val] == 0)
        {

            dfsrecur(adj, val, dfsres, visarr);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj)
{

    vector<int> dfsres;
    vector<int> visarr(adj.size(), 0);

    dfsrecur(adj, 0, dfsres, visarr);
    return dfsres;
}

int main()
{

    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    vector<int> res = dfs(adj);

    for (auto val : res)

    {
        cout << val << ",";
    }

    return 0;
}