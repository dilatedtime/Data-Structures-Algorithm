#include <iostream>
#include <vector>
using namespace std;

int linsearch(const vector<int>& A, int s, int e, int val)
{
    if (s == e)
    {
        if (A[s] >= val)
            return s;
        else
            return s + 1;
    }

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (A[mid] == val)
            return mid;
        if (A[mid] < val)
            return linsearch(A, mid + 1, e, val);
        else
            return linsearch(A, s, mid - 1, val);
    }

    return s; // Default return to avoid warning/error
}

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int>& nums, int x) {
        int n = nums.size();  
        vector<int> v(2, -1); // Initialize with -1 for default

        int pos = linsearch(nums, 0, n - 1, x);

        // Ceil
        if (pos < n)
            v[1] = nums[pos];

        // Floor
        if (pos == n) v[0] = nums[n - 1];
        else if (nums[pos] == x) v[0] = nums[pos];
        else if (pos > 0) v[0] = nums[pos - 1];

        return v;
    }
};

int main()
{
    vector<int> arr = {1, 3, 5, 9, 20, 25, 26, 27, 28};
    Solution sol;

    vector<int> res = sol.getFloorAndCeil(arr, 23);
    cout << "Floor: " << res[0] << ", Ceil: " << res[1] << endl;

    return 0;
}
