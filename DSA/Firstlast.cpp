#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int slinsearch(const vector<int>& A, int s, int e, int val) {
        if (s == e && A[s] == val)
            return s;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (A[mid] == val) {
                if (mid == 0 || A[mid - 1] != val)
                    return mid;
                else
                    return slinsearch(A, s, mid - 1, val);
            }

            if (A[mid] > val)
                return slinsearch(A, s, mid - 1, val);
            else
                return slinsearch(A, mid + 1, e, val);
        }

        return -1;
    }

    int elinsearch(const vector<int>& A, int s, int e, int val) {
        if (s == e && A[s] == val)
            return s;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (A[mid] == val) {
                if (mid == A.size() - 1 || A[mid + 1] != val)
                    return mid;
                else
                    return elinsearch(A, mid + 1, e, val);
            }

            if (A[mid] > val)
                return elinsearch(A, s, mid - 1, val);
            else
                return elinsearch(A, mid + 1, e, val);
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = slinsearch(nums, 0, nums.size() - 1, target);
        int end = elinsearch(nums, 0, nums.size() - 1, target);
        return {start, end};
    }
};

// Sample usage
int main() {
    Solution sol;
    vector<int> arr = {5, 7, 7, 8, 8, 8, 8, 9, 10, 10, 10};
    int target = 6;

    vector<int> result = sol.searchRange(arr, target);
    cout << "Start and End Index: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
