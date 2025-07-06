#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> 
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;

    for (int i = 0; i < asteroids.size(); i++)
    {
        int curr = asteroids[i];

        while (!st.empty() && curr * st.top() < 0 && st.top()>curr)
        {
            if (abs(curr) > abs(st.top()))
            {
                st.pop();
                continue;
            }
            else if (abs(curr) == abs(st.top()))
            {
                st.pop();
                curr = 0; // both destroy each other
                break;
            }
            else
            {
                curr = 0; // current destroyed
                break;
            }
        }

        if (curr != 0)
        {
            st.push(curr);
        }
    }

    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        result[i] = st.top();
        st.pop();
    }
    

    return result;

}
    
int main()
{
    // vector<int> arr = {11, 10, 3, -8, 9, 4, -6, 14, -6, -7, -8, 10, 5, 3, -12};
    vector<int> arr ={8,-8};

    vector<int> final = asteroidCollision(arr);

    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i] << " ";
    }
    cout << endl;
}
