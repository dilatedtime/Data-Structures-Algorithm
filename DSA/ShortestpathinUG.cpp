#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>
#include <limits.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    int v = adj.size();
    vector<int> vis(v, 0);
    vector<int> dis(v, -1);

    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        for (int j = 0; j < adj[i].size(); j++)
        {
            int val = adj[i][j];
            if (dis[val] == -1)
            {

                // we found a neighbor at distance dis[i][j] + 1
                dis[val] = dis[i] + 1;
                // vis[adj[i][j]] = 1;
                q.push(val);
            }
        }
    }

    return dis;
}
int main()
{
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};

    vector<int> order = shortestPath(adj, 0);

    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << ",";
    }

    return 0;
}