#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int dfsrecur(vector<vector<int>> &adj, int i, vector<int> &safe, vector<int> &vis)
{
    vis[i] = 1;

    for (int j = 0; j < adj[i].size(); j++)
    {

        if (safe[adj[i][j]] == 1)
        {
            continue;
        }
        if (vis[adj[i][j]] && safe[adj[i][j]] != 1)
        {
            safe[adj[i][j]] = 0;
            return 0;
        }

        if (!vis[adj[i][j]])
        {

            if (!dfsrecur(adj, adj[i][j], safe, vis))
                return 0;
        }
    }

    safe[i] = 1;
    return 1;
}

vector<int> eventualSafeNodes(vector<vector<int>> &adj)
{

    int v = adj.size();
    vector<int> vis(v, 0);
    vector<int> safe(v, -1);
    // int safe;
    vector<int> final;

    for (int i = 0; i < v; i++)
    {
        if (adj[i].size() == 0)
        {
            safe[i] = 1;
        }
    }

    for (int i = 0; i < v; i++)
    {

        if (!vis[i])
        {
            if (dfsrecur(adj, i, safe, vis))
                safe[i] = 1;

            else
                safe[i] = 0;
        }
    }

    for (int i = 0; i < safe.size(); i++)
    {
        if (safe[i]==1)
            final.push_back(i);
    }

    return final;
}

int main()
{
    // vector<vector<int>> adj = {{1, 2},
    //                            {2, 3},
    //                            {5},
    //                            {0},
    //                            {5},
    //                            {},
    //                            {}};
    vector<vector<int>> adj = {
        {1, 2}, // 0
        {3},    // 1
        {3},    // 2
        {0}     // 3  ← back-edge, cycle among {0,1,3} and also {0,2,3}
        };

    vector<int> order = eventualSafeNodes(adj);

    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << ",";
    }

    return 0;
}