#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool dfsrecur(vector<vector<int>> &adj, int i, vector<int> &path, vector<int> &vis)
{
    vis[i] = 1;
    path.push_back(i);
    // cout << i << ",";
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (!vis[adj[i][j]])
        {
            if (!dfsrecur(adj, adj[i][j], path, vis))
                return 0;
        }
        if (vis[adj[i][j]] && find(path.begin(), path.end(), adj[i][j]) != path.end())
            return 0;
    }
    path.pop_back();
    return 1;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
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
            if (!dfsrecur(adj, i, path, vis))
                return 0;
        }
        else if (vis[i] && find(path.begin(), path.end(), i) != path.end())
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << canFinish(numCourses, prerequisites);

    return 0;
}
    // }
    // #include <iostream>
    // #include <vector>
    // #include <algorithm>
    // using namespace std;

    // bool dfsrecur(const vector<vector<int>> &adj, int u, vector<int> &path, vector<int> &vis)
    // {
    //     vis[u] = 1;
    //     path.push_back(u);

    //     for (int v : adj[u])
    //     {
    //         if (!vis[v])
    //         {
    //             // if exploring v finds a cycle, we bubble the failure immediately
    //             if (!dfsrecur(adj, v, path, vis))
    //                 return false;
    //         }
    //         else
    //         {
    //             // vis[v] == 1 means v is still in our current path—cycle!
    //             if (find(path.begin(), path.end(), v) != path.end())
    //                 return false;
    //         }
    //     }

    //     // finished exploring all children of u, backtrack
    //     path.pop_back();
    //     return true;
    // }

    // bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    // {
    //     vector<vector<int>> adj(numCourses);
    //     for (auto &p : prerequisites)
    //     {
    //         // to take course p[0] you must first take p[1]
    //         adj[p[1]].push_back(p[0]);
    //     }

    //     vector<int> vis(numCourses, 0);
    //     for (int i = 0; i < numCourses; i++)
    //     {
    //         if (!vis[i])
    //         {
    //             vector<int> path;
    //             if (!dfsrecur(adj, i, path, vis))
    //                 return false;
    //         }
    //     }
    //     return true;
    // }

    // int main()
    // {
    //     int numCourses = 3;
    //     vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {0, 2}};
    //     cout << (canFinish(numCourses, prerequisites) ? "true" : "false") << "\n";
    //     return 0;
    // }
