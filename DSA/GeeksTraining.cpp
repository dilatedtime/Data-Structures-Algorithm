#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int maximumPoints(vector<vector<int>>& arr)
{
    int n = arr.size();
    if (n == 1)
        return max(arr[0][0], max(arr[0][1], arr[0][2]));
    tuple <int,int,int> maxpoint(arr[0][0],arr[0][1], arr[0][2]);

    for (int i = 1; i < n; i++)
    {
        int a = max(get<1>(maxpoint),get<2>(maxpoint));
        int b = max(get<0>(maxpoint),get<2>(maxpoint));
        int c = max(get<1>(maxpoint),get<0>(maxpoint));

        maxpoint = make_tuple(arr[i][0]+a,arr[i][1]+b,arr[i][2]+c);
    }

    return max(get<1>(maxpoint),max(get<2>(maxpoint), get<0>(maxpoint)));
}

int main()

{
    vector<vector<int>> arr = {{18, 11, 19}, {4, 13, 7}, {1, 8, 13}};
    cout << maximumPoints(arr);
}