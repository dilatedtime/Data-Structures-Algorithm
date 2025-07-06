#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclic(int numCourses, vector<vector<int>> &edges)
{

    // vector<int> vis(numCourses, 0);
    vector<vector<int>> adj(numCourses);
    queue<int> q;
    vector<int> indegree(adj.size(), 0);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // Directed Graph
        indegree[v]++;
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int removed = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        removed++;

        for (auto val : adj[node])
        {

            if (indegree[val] >= 1)
                indegree[val]--;

            if (!indegree[val])
            {
                q.push(val);
            }
        }
    }

    return (removed != numCourses);
}



int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << isCyclic(numCourses, prerequisites);

    return 0;
}