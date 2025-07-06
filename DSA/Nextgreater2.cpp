#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// class Solution
// {
// public:

vector<int> findnge(vector<int> &nums, int n)
{

    stack<int> st ;

    // for (int i = nums.size()-1 ; i >=0 ; i--)
    // {
    //     st.push(nums[i]);
    // }

    vector<int> arr(n, -1);
    for (int i = 2*n - 1; i >= 0; i--)
    {
        int index = i%n;

        while (!st.empty() && st.top() <= nums[index])
        {
            st.pop();
        }

        if (!st.empty() && index<n)
            arr[index] = st.top();

        st.push(nums[index]);
    }

    return arr;
}

vector<int> nextGreaterElements(vector<int> &nums)
{

    int n = nums.size();

    vector<int> v(n, -1);

    return findnge(nums, n);
}

// };

int main()
{

    vector<int> nums = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};

    vector<int> v1 = nextGreaterElements(nums);

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << ",";
    }
}




