#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findpse(vector<int> &heights)

{
    stack<int> st;
    int n = heights.size();
    vector<int> pse(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[i] < heights[st.top()])
        {
            st.pop();
        }

        if (!st.empty() && heights[i] > heights[st.top()])
        {

            pse[i] = st.top();
        }

        if (!st.empty() && heights[i] == heights[st.top()])
        {

            pse[i] = pse[i - 1];
        }

        st.push(i);
    }

    return pse;
}

vector<int> findnse(vector<int> &heights)

{

    stack<int> st;
    int n = heights.size();
    vector<int> nse(n, n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[i] <= heights[st.top()])
        {

            st.pop();
        }

        if (!st.empty() && heights[i] > heights[st.top()])
        {

            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> pse = findpse(heights);
    vector<int> nse = findnse(heights);
    int n = heights.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, heights[i] * ((i - pse[i] - 1) + (nse[i] - i)));
    }

    return res;
}

int maximalRectangle(vector<vector<char>> &matrix)
{

    int nr = matrix.size();
    int nc = matrix[0].size();
    int temp = 0;
    int res = 0;
    vector<vector<int>> prefixsummatrix(nr, vector<int>(nc, 0));
    ;

    for (int i = 0; i < nc; i++)
    {

        for (int j = 0; j < nr; j++)
        {
            if (matrix[j][i] == '0')
                temp = 0;

            prefixsummatrix[j][i] = temp + matrix[j][i] - '0';
            temp = temp + matrix[j][i] - '0';
        }

        temp = 0;
    }

    for (int i = 0; i < nr; i++)
    {

        res = max(res, largestRectangleArea(prefixsummatrix[i]));
    }

    return res;
}
int main()

{

    vector<vector<char>> matrix = {{'0', '1', '1', '0'},
                                   {'1', '1', '1', '1'},
                                   {'1', '1', '1', '1'},
                                   {'1', '1', '0', '0'}};
    // = {{'1', '0', '1', '0', '0'},
    //     {'1', '0', '1', '1', '1'},
    //     {'1', '1', '1', '1', '1'},
    //     {'1', '0', '0', '1', '0'}};
    // vector<int> nse = findpse(heights);

    // cout << nse[0] << "," << nse[1] << "," << nse[2] << "," << nse[3] << "," << nse[4] << "," << nse[5] << endl;
    cout << maximalRectangle(matrix);
    return 0;
}
