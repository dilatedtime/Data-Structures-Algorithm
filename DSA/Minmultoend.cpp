#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <tuple>
#include <limits.h>
using namespace std;

int minimumMultiplications(vector<int> &roads, int start, int end)
{

    if (start == end)
        return 0;

    int MOD = 100000;
    int n = roads.size();
    vector<long long> dist(MOD, -1);
    queue<pair<long long, int>> st;
    
    dist[start] = 0;
    st.emplace(start, 0);

    while (!st.empty())
    {

        int price = st.front().first;
        int count = st.front().second;
        st.pop();

        for (int j = 0; j < n; j++)
        {
            int val = roads[j];
            long long nd = price * val % MOD;

            {
                if (dist[nd] == -1)
                {
                    dist[nd] = count + 1;

                    if (nd == end)
                        return dist[nd];

                    st.push({nd, count + 1});
                }
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> mat = {2, 5, 7};
    cout << minimumMultiplications(mat, 3, 1470);

    return 0;
}
