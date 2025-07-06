
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> findNGE(vector<int> &nums)
{

    stack<int> st;
    int n = nums.size();
    vector<int> nge(n, n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[i] >= nums[st.top()])
        {
            st.pop();
        }

        if (!st.empty() && nums[i] < nums[st.top()])
        {

            nge[i] = st.top();
        }

        st.push(i);
    }

    return nge;
}

vector<int> findPGEE(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> pgee(n, -1);

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && nums[i] > nums[st.top()])
        {
            st.pop();
        }

        if (!st.empty() && nums[i] <= nums[st.top()])
        {

            pgee[i] = st.top();
        }

        st.push(i);
    }

    return pgee;
}

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

long long subArrayRanges(vector<int> &nums)
{

    long long summin = 0;
    long long summax = 0;
    int n = nums.size();
    vector<int> psee = findPSEE(nums);
    vector<int> nse = findNSE(nums);
    vector<int> pgee = findPGEE(nums);
    vector<int> nge = findNGE(nums);

    for (int i = 0; i < n; i++)
    {
        summin = summin + ((long long )nums[i] * ((long long )(i - psee[i]) * (nse[i] - i)));
    }

    for (int k = 0; k < n; k++)
    {
        summax = summax + ((long long )nums[k] * ((long long )(k - pgee[k]) * (nge[k] - k)));
    }

    return summax - summin;
}

int main()
{

    vector<int> nums = {-32, 0, -2, 72};

    long long res = subArrayRanges(nums);
    // vector<int> hey = findNSE(nums);
    // vector<int> he = findPSEE(nums);

    // cout << hey[0] << "," << hey[1] << "," << hey[2] << "," << hey[3] << "," << hey[4] << endl;
    // cout << he[0] << "," << he[1] << "," << he[2] << "," << he[3] << "," << he[4] << endl;
    cout<<res;

    return 0;
}