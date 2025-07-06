#include <iostream>
#include <stack>
using namespace std;

int main()
{

    int t;
    cin >> t;
    int n;
    

    while (t--)
    {
        cin >> n;
        int num;
        stack<int> st;
        
        for (int i = 0; i < n; i++)
        {
            

            cin >> num;

            if (st.empty())
            {
                st.push(num);
                continue;
            }

            if (!st.empty() && num > st.top() + 1)
            {
                st.push(num);
            }
            else
                continue;
        }

        cout << st.size() << endl;
        
    }

    return 0;
}