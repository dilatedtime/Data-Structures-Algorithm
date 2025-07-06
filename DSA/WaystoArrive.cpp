#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <tuple>
#include <limits.h>
using namespace std;



int countPaths(int n, vector<vector<int>> &roads)
{
    long long MOD= 1000000007;
    int dst = n - 1;
    int e = roads.size();
    vector<long long> fare(n, INT_MAX);
    vector<long long> ways(n, 0);
    set<pair<long long, int>> st;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < e; i++)
    {

        int u = roads[i][0];
        int l = roads[i][1];
        int w = roads[i][2];

        adj[u].push_back({w, l});
        adj[l].push_back({w, u});
    }

    fare[0] = 0;
    ways[0] = 1;
    st.emplace(0, 0);

    while (!st.empty())
    {

        int price = st.begin()->first;
        int node = st.begin()->second;
        st.erase(st.begin());

        // if (price > fare[node]) continue;

        for (int j = 0; j < adj[node].size(); j++)
        {
            long long  nd = price + adj[node][j].first;
            int val = adj[node][j].second;

            {

                if (fare[val] == INT_MAX)
                {
                    ways[val] = ways[node]%MOD;
                    fare[val] = nd;
                    st.emplace(fare[val], val);
                }
                else if (fare[val] > (nd))
                {
                    ways[val] = ways[node]%MOD;
                    st.erase({fare[val], val});
                    fare[val] = nd;
                    st.emplace(fare[val], val);
                }
                else if (fare[val] == (nd))
                {
                    ways[val] = (ways[val] + ways[node]%MOD)%MOD;
                }
            }
        }
    }

    return (fare[dst] == INT_MAX ? -1 : (int) ways[dst]%MOD);

}

int main()
{
    // vector<vector<int>> mat = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    vector<vector<int>> mat = {{0, 5, 8}, {0, 2, 2}, {0, 1, 1}, {1, 3, 3}, {1, 2, 3}, {2, 5, 6}, {3, 4, 2}, {4, 5, 2}};
    cout << countPaths(6, mat);

    return 0;
}

