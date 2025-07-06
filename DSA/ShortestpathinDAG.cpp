#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>
#include <limits.h>
using namespace std;

void toposort(vector<vector<pair<int, int>>> &adj, int i, vector<int> &vis, stack<int> &st)
{
    // int src = 0;
    vis[i] = 1;
    for (int j = 0; j < adj[i].size(); j++)
    {

        int val = adj[i][j].first;
        if (!vis[val])
        {
            toposort(adj, val, vis, st);
        }
    }
    st.push(i);
}

vector<int> shortestPath(int n, int e, vector<vector<int>> &edges)
{
    vector<int> vis(n, 0);
    vector<int> dis(n, INT_MAX);
    stack<int> st;
    // vector<int> topo;
    vector<vector<pair<int, int>>> adj(n);
    // st.push(0);
    dis[0] = 0;
    // vis[0] = 1;

    for (int i = 0; i < e; i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
    }

    // for (int i = 0; i < v; i++)
    // {
    //     cout<<"{";
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout<<"{"<<adj[i][j].first<<","<<adj[i][j].second<<"}"<<",";
    //     }
    //     cout<<"}";

    // }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            toposort(adj, i, vis, st);
        }
    }

    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (dis[u] == INT_MAX)
            continue; // unreachable prefix
        for (auto &p : adj[u])
        {
            int v = p.first;
            int w = p.second;
            dis[v] = min(dis[v], dis[u] + w);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(dis[i]==INT_MAX)
            dis[i]=-1;
    }
    

    return dis;
}
int main()
{
    // vector<vector<int>> adj = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vector<vector<int>> adj = {{0, 1, 2}, {0, 2, 1}};
    vector<int> order = shortestPath(4, 2, adj);

    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << ",";
    }

    return 0;
}