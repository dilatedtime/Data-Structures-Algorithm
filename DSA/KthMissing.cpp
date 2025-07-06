#include <iostream>
#include <vector>
using namespace std;

int miss(int e, vector<int> &arr)
{

    return arr[e] - (e + 1);
}



int findKthPositive(vector<int> &arr, int k)
{

    int n = arr.size();
    // int pos = findnum(0, n - 1, arr, k);

    if (k > miss(n-1,arr))
    return arr[n-1] + (k - miss(n-1,arr));

    int s=0, e=n-1;

    while (s < e)
    {
        int mid = (s + e) / 2;

        if (miss(mid,arr) < k)
        s = mid + 1;
        else
        e = mid;
    }

    return k + s;


    // return arr[pos] + k - miss(pos, arr);
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 1;

    cout << findKthPositive(arr, k);
}