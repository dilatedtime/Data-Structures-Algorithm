#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <tuple>
#include <limits.h>
using namespace std;

int findTheCity(int n, vector<vector<int>> &edges, int limit)
{
    int e = edges.size();

    vector<int> count(n, 0);
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < e; i++)
    {

        int u = edges[i][0];
        int l = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({w, l});
        adj[l].push_back({w, u});
    }

    for (int i = 0; i < n; i++)
    {
        set<pair<int, int>> st;
        vector<int> fare(n, INT_MAX);
        fare[i] = 0;
        st.emplace(0, i);
        // vector<int> vis(n, 0);

        while (!st.empty())
        {

            int price = st.begin()->first;
            int node = st.begin()->second;
            st.erase(st.begin());

            // if (price > fare[node]) continue;

            for (int j = 0; j < adj[node].size(); j++)
            {
                int nd = price + adj[node][j].first;
                int val = adj[node][j].second;

                {

                    if (fare[val] == INT_MAX && nd <= limit)
                    {
                        count[node]++;
                        fare[val] = nd;
                        st.emplace(fare[val], val);
                    }
                    else if (fare[val] > (nd))
                    {
                        // if (nd <= limit)
                        // {
                        //     count[node]++;
                        // }
                        // else
                        // continue;

                        st.erase({fare[val], val});
                        fare[val] = nd;
                        st.emplace(fare[val], val);
                    }
                    // else if (fare[val] == (nd))
                    // {
                    //     ways[val] = (ways[val] + ways[node]);
                    // }
                }
            }

            // for (int i = 0; i < adj[node].size(); i++)
            // {
            //     count[node]+=count[(adj[node][i]).second];
            // }
            

            
        }
    }

    int city;
    int neighbors = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (count[i] <= neighbors)
        {
            neighbors = count[i];
            city = i;
        }
    }
    cout<<count[0]<<count[1]<<count[2]<<count[3];

    return city;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    // vector<vector<int>> mat = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    // vector<vector<int>> mat = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    cout << findTheCity(4, mat, 4);

    return 0;
}
..