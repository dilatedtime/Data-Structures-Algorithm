#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool dfsrecur(vector<vector<int>> &adj, int i, vector<int> &path, vector<int> &vis, stack<int> &seq)
{
    vis[i] = 1;
    path.push_back(i);
    // cout << i << ",";
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (!vis[adj[i][j]])
        {
            if (!dfsrecur(adj, adj[i][j], path, vis, seq))
                return 0;
        }
        if (vis[adj[i][j]] && find(path.begin(), path.end(), adj[i][j]) != path.end())
            return 0;
    }

    seq.push(i);
    path.pop_back();
    return 1;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites, stack<int> &seq)
{

    vector<int> vis(numCourses, 0);

    vector<vector<int>> adj(numCourses);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];

        adj[v].push_back(u); // Directed Graph
    }

    for (int i = 0; i < adj.size(); i++)
    {

        vector<int> path;
        if (!vis[i])
        {
            if (!dfsrecur(adj, i, path, vis, seq))
                return 0;
        }
        else if (vis[i] && find(path.begin(), path.end(), i) != path.end())
        {
            return 0;
        }
    }

    return 1;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    stack<int> seq;
    vector<int> order;

    if (canFinish(numCourses, prerequisites, seq))
    {

        while (!seq.empty())
        {
            order.push_back(seq.top());
            seq.pop();
        }
    }

    return order;
}

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = { {1,0},
                                          {2, 0},
                                          {3,1},
                                          {3,2},
                                        //   {1,4},
                                        //   {5,1}
                                        };
vector<int> order = findOrder(numCourses, prerequisites);

for (int i = 0; i < order.size(); i++)
{
    cout << order[i] << ",";
}

return 0;
}