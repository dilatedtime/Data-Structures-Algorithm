#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// class Solution {
// public:
// };
string removeKdigits(string num, int k)
{

    stack<char> st;

    for (int i = 0; i < num.size(); i++)
    {
        while (!st.empty() && num[i] < st.top() && k != 0)

        {
            st.pop();
            k--;
        }

        st.push(num[i]);
    }

    while (k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }

    int size = st.size();
    int m;
    string s(st.size(), ' ');
    for (m = size - 1; m >= 0; m--)
    {
        s[m] = st.top();
        st.pop();
    }

    int i = 0;
    while (i < s.size() && s[i] == '0') i++;
    s = s.substr(i);

    return s.empty() ? "0" : s;
}

int main()
{
    string num = "112";

    string ab = removeKdigits(num, 1);

    cout << ab[0] << ab[1] << ab[2] << ab[3];
}