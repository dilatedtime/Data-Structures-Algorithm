#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isCyclic(int numCourses, vector<vector<int>> &edges, vector<int> &order)
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
        order.push_back(q.front());
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

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{

    vector<int> order;
    vector<int> empty;

    if (!isCyclic(numCourses, prerequisites, order))
    {
        reverse(order.begin(), order.end());
        return order;
    }

    else
        return empty;
}

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> order = findOrder(numCourses, prerequisites);

    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << ",";
    }

    return 0;
}