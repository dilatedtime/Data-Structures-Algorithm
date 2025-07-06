#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        stack<int> s1;
        int n = s.length();
        if (n % 2 != 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                s1.push(s[i]);
            }
            else
            // if (s[i] == ']' || s[i] == '}' || s[i] == ')')
            {
                if (s1.empty())
                    return false;

                if (s[i] == ']' && s1.top() == '[')
                {
                    s1.pop();
                }
                else if (s[i] == '}' && s1.top() == '{')
                {
                    s1.pop();
                }
                else if (s[i] == ')' && s1.top() == '(')
                {
                    s1.pop();
                }
                else
                    return 0;
            }
        }

        return (s1.empty());
    }
};


int main()
{
    Solution sol;

    string test1 = "({{[[]]}))";  // valid
    string test2 = "({[})";   // invalid

    cout << "Test 1: " << test1 << " => " << sol.isValid(test1)<< endl;
    cout << "Test 2: " << test2 << " => " << sol.isValid(test2)<< endl;

    return 0;
}