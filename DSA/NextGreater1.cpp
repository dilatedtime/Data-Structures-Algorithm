#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// class Solution
// {
// public:


vector<int> findnge(vector<int> &nums1, int n1, vector<int> &nums2, int n2)
{

    stack<int> st;
    vector<int> arr(10001, -1);
    for (int i = n2 - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= nums2[i])
        {
            st.pop();
        }

        if (!st.empty())
            arr[nums2[i]] = st.top();

        st.push(nums2[i]);
    }

    return arr;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<int> v (n1,-1);
    vector<int> old = findnge(nums1, n1, nums2, n2);

    for (int i = 0; i < nums1.size(); i++)
    {
        v[i] = old[nums1[i]];
    }

    return v;

}

// };


int main()
{

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector <int> v1= nextGreaterElement(nums1, nums2);

    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<",";
    }
    
}