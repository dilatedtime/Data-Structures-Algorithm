#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    if (n == 1)
        return triangle[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j < triangle[i - 1].size() && j - 1 < triangle[i - 1].size())
                triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j - 1], triangle[i - 1][j]);

            else if (j < triangle[i - 1].size())
                triangle[i][j] = (triangle[i][j] + triangle[i - 1][j]);
            else if (j - 1 < triangle[i - 1].size())
                triangle[i][j] = (triangle[i][j] + triangle[i - 1][j - 1]);
        }
    }

    return *min_element(triangle[n-1].begin(), triangle[n-1].end());
}

int main()

{
    // vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    vector<vector<int>> triangle = {{-10}};
    cout << minimumTotal(triangle);
}