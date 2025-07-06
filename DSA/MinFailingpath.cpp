#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    if (n == 1)
        return *min_element(matrix[0].begin(), matrix[0].end());

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {

            if (j != 0 && j!=n-1)
                matrix[i][j] = matrix[i][j] + min(matrix[i - 1][j - 1],min(matrix[i - 1][j],matrix[i - 1][j+1]));

            else if (j == 0 )
                matrix[i][j] = matrix[i][j] + min(matrix[i - 1][j],matrix[i - 1][j+1]);
            else if (j==n-1)
                matrix[i][j] = matrix[i][j] + min(matrix[i - 1][j],matrix[i - 1][j-1]);
        }
    }

    return *min_element(matrix[n-1].begin(), matrix[n-1].end());
}


int main()

{
    // vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    vector<vector<int>> matrix = {{-19,57},{-40,5}};
    cout << minimumTotal(matrix);
}