#include <iostream>
#include <vector>
using namespace std;

void dfsrecur(vector<vector<int>> &isConnected, vector<int> &visarr, int i)
{
    visarr[i] = 1;
    for (int j = 0; j < isConnected.size(); j++)
    {
        if (isConnected[i][j] == 1 && !visarr[j])
        {
            dfsrecur(isConnected, visarr, j);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    vector<int> visarr(isConnected.size(), 0);
    int count = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (visarr[i] == 0)
        {
            dfsrecur(isConnected, visarr, i);
            count++;
        }
    }
    return count;
}

int main()
{
}

class Solution
{
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &isConnected)
    {
        visited[node] = 1;
        for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor)
        {
            if (isConnected[node][neighbor] == 1)
            {
                if (!visited[neighbor])
                {
                    dfs(neighbor, visited, isConnected);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // int start = 0;
        int count = 0;
        vector<int> visited(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, isConnected);
                count++;
            }
        }

        return count;
    }
};