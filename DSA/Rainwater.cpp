#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findngee(vector<int> &height)
{
    stack<int> st;
    int n = height.size();
    vector<int> ngee(n, height[n - 1]);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && height[i] > st.top())
        {
            ngee[i] = height[i];
            st.pop();
        }

        if (!st.empty() && height[i] <= st.top())
        {

            ngee[i] = st.top();
            continue;
        }

        st.push(height[i]);
    }
    return ngee;
}

vector<int> findpgee(vector<int> &height)
{

    stack<int> st;
    int n = height.size();
    vector<int> pgee(n, height[0]);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && height[i] > st.top())
        {
            pgee[i] = height[i];
            st.pop();
        }

        if (!st.empty() && height[i] <= st.top())
        {

            pgee[i] = st.top();
            continue;
        }

        st.push(height[i]);
    }
    return pgee;
}

int trap(vector<int> &height)
{
    int sum = 0;
    int n = height.size();
    vector<int> pgee = findpgee(height);
    vector<int> ngee = findngee(height);

    for (int i = 0; i < n; i++)
    {
        sum = sum + min(pgee[i], ngee[i]) - height[i];
    }

    return sum;
}

int main()
{
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vector<int> height = {3, 0, 1, 0, 4, 0, 2};
    vector<int> height = {1, 2, 3, 4};
    // vector<int> ngee = findpgee(height);

    // for (int i = 0; i < height.size(); i++)
    // {
    //     cout << ngee[i] << ",";
    // }

    cout<<trap(height);

    return 0;
}
