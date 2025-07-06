#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findpse(vector<int> &heights)

{
    stack<int> st;
    int n = heights.size();
    vector<int> pse(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[i] < heights[st.top()])
        {
            st.pop();
        }

        if (!st.empty() && heights[i] > heights[st.top()])
        {

            pse[i] = st.top();

        }
        
        if (!st.empty() && heights[i] == heights[st.top()])
        {

            pse[i] = pse[i-1];

        }


        st.push(i);
    }

    return pse;
}

vector<int> findnse(vector<int> &heights)

{

    stack<int> st;
    int n = heights.size();
    vector<int> nse(n, n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[i] <= heights[st.top()])
        {
            
            st.pop();
        }

        if (!st.empty() && heights[i] > heights[st.top()])
        {

            nse[i] = st.top();
        }
        
        
        st.push(i);
    }

    return nse;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> pse = findpse(heights);
    vector<int> nse = findnse(heights);
    int n = heights.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, heights[i] * ((i - pse[i] - 1) + (nse[i] - i)));
    }

    return res;
}


int main()

{

    vector<int> heights = {5,5,1,7,1,1,5,2,7,6};
    vector<int> nse = findpse(heights);

    // cout << nse[0] << "," << nse[1] << "," << nse[2] << "," << nse[3] << "," << nse[4] << "," << nse[5] << endl;
    cout<<largestRectangleArea(heights);
    return 0;
}
