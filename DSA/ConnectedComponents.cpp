
#include <iostream>
#include <vector>
using namespace std;

void dfsrecur(int node, vector<vector<int>> &adj, vector<int> &component, vector<int> &visarr)
{
    visarr[node] = 1;
    component.push_back(node);

    for (auto val : adj[node])
    {
        if (!visarr[val])
        {
            dfsrecur(val, adj, component, visarr);
        }
    }
}

vector<vector<int>> getComponents(int v, vector<vector<int>> &edges)
{

    // Step 1: Build adjacency list
    vector<vector<int>> adj(v);
    for (auto edge : edges)
    {
        int u = edge[0];
        int w = edge[1];
        adj[u].push_back(w);
        adj[w].push_back(u); // Because the graph is undirected
    }

    vector<int> visarr(v, 0);
    vector<vector<int>> dfsres;

    // Step 2: DFS from each unvisited node
    for (int i = 0; i < v; i++)
    {
        if (!visarr[i])
        {
            vector<int> component;
            dfsrecur(i, adj, component, visarr);
            dfsres.push_back(component);
        }
    }

    return dfsres;
}

int main()
{
    vector<vector<int>> edges = {{0, 1},
                                 {6, 0},
                                 {2, 4},
                                 {2, 3},
                                 {3, 4}};

    vector<vector<int>> dfsres = getComponents(7, edges);

    int i = 0;

    for (int i = 0; i < dfsres.size(); i++)
    {

        cout << "{";
        for (int j = 0; j < dfsres[i].size(); j++)
        {
            cout << "," << dfsres[i][j] ;
        }
        cout << "}"<<",";
    }

    return 0;
}