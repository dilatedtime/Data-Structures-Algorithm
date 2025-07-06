#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int k = g.size();
    int n = s.size();

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int count = 0;
    int i = 0, j = 0;

    while (i < k && j < n)
    {
        if (g[i] <= s[j])
        {
            count++;
            i++;
        }
        j++;
    }

    return count;
}

int main()

{
    // vector<vector<int>> chocolates = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    vector<int> g = {
        1,
        2,
        3,
        4,
        5,
        8,
        3,
        9,
        6};
    vector<int> s = {3, 4, 8, 7, 5, 6, 9, 4, 2};

    cout << findContentChildren(g, s);
}