#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfsrecur(vector<vector<int>> &graph, vector<int> &vis, int i, vector<int> &arr)
{
    vis[i] = 1;
    for (int j = 0; j < graph[i].size(); j++)
    {
        int val = graph[i][j];
        if (!vis[val])
        {
            if (arr[val] == -1)
            {
                arr[val] = 1 - arr[i];
                if (!dfsrecur(graph, vis, graph[i][j], arr))
                    return 0;
            }
            else if (arr[val] == arr[i])
            {
                // neighbor already colored with the same color → conflict
                return 0;
            }
        }

         else
        {
            // Even if `val` was already visited, we still must check the coloring.
            if (arr[val] == arr[i])
                return false;
        }

        
    }

    return 1;
}

    bool isBipartite(vector<vector<int>> & graph)
    {
        int v = graph.size();
        vector<int> vis(v, 0);
        vector<int> arr(v, -1);

        arr[0] = 0;
        for (int i = 0; i < v; i++)
        {
            if (arr[i] == -1)
            {
                arr[i] = 0;
            }

            if (!vis[i])
            {
                if (!dfsrecur(graph, vis, i, arr))
                    return 0;
            }
        }

        return 1;
    }

    int main()
    {

        vector<vector<int>> mat = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

        cout << isBipartite(mat);

        return 0;
    }

    // bool fillzero(vector<vector<int>> &graph, int i, vector<int> &arr)
    // {
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         if (arr[graph[i][j]] == -1 || arr[graph[i][j]] == 0)
    //         {
    //             arr[graph[i][j]] = 0;
    //         }

    //         else
    //             return 0;
    //     }

    //     return 1;
    // }

    // bool fillone(vector<vector<int>> &graph, int i, vector<int> &arr)
    // {
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         if (arr[graph[i][j]] == -1 || arr[graph[i][j]] == 1)
    //         {
    //             arr[graph[i][j]] = 1;
    //         }

    //         else
    //             return 0;
    //     }

    //     return 1;
    // }

    // bool isBipartite(vector<vector<int>> &graph)
    // {

    //     int v = graph.size();
    //

    //     arr[0] = 0;

    //     for (int i = 0; i < v; i++)
    //     {

    //         if (arr[i] == -1)
    //         {
    //             arr[i] = 0;
    //         }

    //         if (arr[i] == 0)

    //         {
    //             if (!fillone(graph, i, arr))
    //                 return 0;
    //         }
    //         else if (arr[i]==1)
    //         {
    //             if (!fillzero(graph, i, arr))
    //                 return 0;
    //         }
    //     }

    //     // for (int i = 0; i < arr.size(); i++)
    //     // {
    //     //     cout << arr[i] << ",";
    //     // }

    //     return 1;
    // }

    // int main()
    // {

    //     vector<vector<int>> mat = {{1},{0,3},{3},{1,2}};

    //     cout << isBipartite(mat);

    //     return 0;
    // }
