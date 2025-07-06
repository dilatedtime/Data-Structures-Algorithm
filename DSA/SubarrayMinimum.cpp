
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int MOD=1000000007;

vector<int> findNSE(vector<int> &nums)
{

    stack<int> st;
    int n = nums.size();
    vector<int> nse(n, n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[i] <= nums[st.top()])
        {
            st.pop();
        }
        
        if (!st.empty() && nums[i] > nums[st.top()])
        {

            nse[i] = st.top();
        }

        

        st.push(i);
    }

    return nse;
}

vector<int> findPSEE(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> psee(n, -1);

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && nums[i] < nums[st.top()])
        {
            st.pop();
        }

        if (!st.empty() && nums[i] >= nums[st.top()])
        {

            psee[i] = st.top();
        }

        st.push(i);
    }

    return psee;
}

int sumSubarrayMins(vector<int> &nums)
{

    int sum = 0;
    int n = nums.size();
    vector<int> psee = findPSEE(nums);
    vector<int> nse = findNSE(nums);
    for (int i = 0; i < n; i++)
    {
        sum = sum + (nums[i] * ((i - psee[i]) * (nse[i] - i))%MOD)%MOD;
    }
    
    return sum%MOD;
}

int main()
{

    vector<int> nums = {4,-2,-3,4,1};

    // int res = sumSubarrayMins(nums);
    vector <int> hey = findNSE(nums);
    vector <int> he = findPSEE(nums);

    cout << hey[0] << "," << hey[1] << "," << hey[2] << "," << hey[3] << "," << hey[4] << endl;
    cout << he[0] << "," << he[1] << "," << he[2] << "," << he[3] << "," << he[4] << endl;
    // cout<<res;

    return 0;
}