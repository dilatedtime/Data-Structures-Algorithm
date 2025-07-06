#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj)
{

    vector<int> bfsres;
    vector<int> visarr(adj.size(), 0);
    visarr[0] = 1;
    queue<int> q;

    q.push(0);

    while (!q.empty())
    {

        int node = q.front();
        q.pop();
        bfsres.push_back(node);

        for (int val : adj[node]) {
            if (visarr[val] == 0) {
                visarr[val] = 1;
                q.push(val);
            }
        }
    }

    return bfsres;
}

int main()
{

    return 0;
}