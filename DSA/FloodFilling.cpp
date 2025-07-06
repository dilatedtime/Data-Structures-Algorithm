
#include <iostream>
#include <vector>
using namespace std;

// LEETCODE

void dfsrecur(vector<vector<int>> &image, int i, int j, vector<vector<int>> &nimage, int color, int n, int m)
{
    nimage[i][j] = color;

    int dx[] = {0, -1, 1, 0};
    int dy[] = {-1, 0, 0, 1};

    for (int d = 0; d < 4; d++)
    {
        int k = i + dx[d];
        int l = j + dy[d];
        
        if (k >= 0 && k < n && l >= 0 && l < m)
        {
            if (nimage[k][l] != color && image[k][l] == image[i][j])
            {

                dfsrecur(image, k, l, nimage, color, n, m);
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> nimage = image;
    dfsrecur(image, sr, sc, nimage, color, n, m);

    return nimage;
}

int main()
{

    vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> nimage = floodFill(image, sr, sc, color);

    cout << "{";
    for (int i = 0; i < nimage.size(); i++)
    {
        for (int j = 0; j < nimage[0].size(); j++)
        {
            cout << nimage[i][j] << ",";
        }

        cout << endl;
    }

    cout << "}";

    return 0;
}
