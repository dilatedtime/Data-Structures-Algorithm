#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <tuple>
#include <limits.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &edges, int src, int dst, int k)
{
    int e = edges.size();
    vector<int> fare(n, INT_MAX);
    set<tuple<int, int, int>> st;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < e; i++)
    {

        int u = edges[i][0];
        int l = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({w, l});
    }

    fare[src] = 0;
    st.emplace(0, 0, src);

    while (!st.empty())
    {
        auto it = st.begin();
        int stops = get<0>(*it);
        int price = get<1>(*it);
        int node = get<2>(*it);
        st.erase(it);

        // int price = st.begin()->first;
        // int node = st.begin()->second;
        // st.erase(st.begin());

        for (int j = 0; j < adj[node].size(); j++)
        {
            int nd = price + adj[node][j].first;
            int val = adj[node][j].second;

            //  if (price > fare[node])
            //     continue;

            if (val == dst && stops <= k+1 )
            {
                fare[val] = min(nd, fare[val]);
            }

            else if(stops<k)
            {

                if (fare[val] == INT_MAX)
                {
                    fare[val] = nd;
                    st.emplace(stops + 1, fare[val], val);
                }
                else if (fare[val] > (nd))
                {
                    st.erase({stops+1, fare[val], val});
                    fare[val] = nd;
                    st.emplace(stops+1, fare[val], val);
                }
            }
        }
    }
    if (fare[dst] != INT_MAX)
        return fare[dst];

    return -1;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    // vector<vector<int>> mat = {{0,1,100},{1, 2, 100},{0,2,500}};
    // vector<vector<int>> mat = {{0,1,5},{1, 2, 5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    

    cout << findCheapestPrice(4, mat, 0, 3, 1);

    return 0;
}


