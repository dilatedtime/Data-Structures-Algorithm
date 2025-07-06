#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <tuple>
#include <limits.h>
using namespace std;
int networkDelayTime(vector<vector<int>> &edges, int v, int k)
{
    int e = edges.size();
    vector<int> dis(v, INT_MAX);
    set<pair<int, int>> st;
    vector<vector<pair<int, int>>> adj(v);

    for (int i = 0; i < e; i++)
    {

        int u = edges[i][0] - 1;
        int l = edges[i][1] - 1;
        int w = edges[i][2];

        adj[u].push_back({w, l});
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

    // dfsrecur(adj,k,vis,dis);

    dis[k - 1] = 0;
    st.insert({0, k - 1});

    while (!st.empty())
    {
        int far = st.begin()->first;
        int node = st.begin()->second;
        st.erase(st.begin());

        for (int j = 0; j < adj[node].size(); j++)
        {
            int nd =far + adj[node][j].first;
            int val = adj[node][j].second;
            if (dis[val] == INT_MAX)
            {
                dis[val] = nd ;
                st.insert({dis[val], val});
            }
            else if (dis[val] > (nd))
            {
                st.erase({dis[val], val});
                dis[val] = nd;
                st.insert({dis[val], val});
            }
        }
    }
    int larger = -1;
    for (int i = 0; i < v; i++)
    {
        if (dis[i] == INT_MAX)
            return -1;
        else
            larger = max(larger, dis[i]);
    }

    return larger;
}
int main()
{
    // vector<vector<int>> mat = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
    vector<vector<int>> mat = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    // vector<vector<int>> mat = {{1, 2, 1}};
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

    cout << networkDelayTime(mat, 4, 2);

    return 0;
}
