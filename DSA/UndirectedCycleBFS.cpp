#include <iostream>
#include <queue>
#include <vector>
using namespace std;


bool isCycle(int v, vector<vector<int>> &edges)
{
    vector<int> visarr(v, 0);
    vector<vector<int>> adj(v);
    queue<pair<int, int>> q;  // (node, parent)

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < v; i++)
    {
        if (!visarr[i])
        {
             
             q.push({i, -1});
             visarr[i] = 1;

            while (!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (auto val : adj[node])
                {

                    if (!visarr[val])
                    {
                        visarr[val] = 1;
                        q.push({val, node});

                    }

                    else if (val != parent)
                        return 1;
                }
            }

        }
    }

    return false;
}

int main()
{

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {4, 5}};
    cout << isCycle(6, edges);
    return 0;
}
