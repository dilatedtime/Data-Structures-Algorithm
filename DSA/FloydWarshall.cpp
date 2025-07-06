#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <tuple>
#include <limits.h>
using namespace std;

void floydWarshall(vector<vector<int>> &dist)
{
    int n = dist.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                

                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                
            }
        }
    }
}

int main()
{
    vector<vector<int>> mat = {{0, 4, 100000000, 5, 100000000}, {100000000, 0, 1, 100000000, 6}, {2, 100000000, 0, 3, 100000000}, {100000000, 100000000, 1, 0, 2}, {1, 100000000, 100000000, 4, 0}};
    floydWarshall(mat);
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j]<<",";
        }
        cout<<endl;
    }

    return 0;
}
