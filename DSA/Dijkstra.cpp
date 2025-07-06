#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>
#include <limits.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>> &edges, int src)
{
    int e = edges.size();
    vector<int> dis(n, INT_MAX);
    set<pair<int, int>> st;
    vector<vector<pair<int, int>>> adj(n);
    dis[src] = 0;
    st.insert({0, src});

    for (int i = 0; i < e; i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[v].push_back({w, u});
        adj[u].push_back({w, v});
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

    while (!st.empty())
    {
        int u = st.begin()->second;
        st.erase(st.begin());

        for (int j = 0; j < adj[u].size(); j++)
        {

            int val = adj[u][j].second;

            if (dis[val]==INT_MAX)
            {
                dis[val] = adj[u][j].first + dis[u];
                st.insert({dis[val], val});

            }

            else if (dis[val] > adj[u][j].first + dis[u])
            {
                st.erase({dis[val],val});
                dis[val] = adj[u][j].first + dis[u];
                st.insert({dis[val], val});
            }
            else if (dis[val] <= adj[u][j].first + dis[u])

            {
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dis[i] == INT_MAX)
            dis[i] = -1;
    }

    return dis;
}
int main()
{
    // vector<vector<int>> adj = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    vector<vector<int>> adj = {{0, 1, 1}, {1, 2, 3},{0,2,6}};
    vector<int> order = dijkstra(3, adj, 2);

    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << ",";
    }

    return 0;
}