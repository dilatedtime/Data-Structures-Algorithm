#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> st;
    int arr[300000];
    int i = 0;
    MinStack()
    {
    }

    void push(int val)
    {

        if (i == 0)
        {
            st.push(val);
            arr[i] = val;
            i++;
        }
        else    
        {
            if (val <= arr[i - 1])
            {
                arr[i] = val;
                i++;
                st.push(val);
            }
            else
                st.push(val);
        }
    }

    void pop()
    {
        if (st.top() == arr[i-1])
        {
            i--;
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return arr[i - 1];
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Min: " << minStack.getMin() << endl; // should print -3

    minStack.pop();

    cout << "Top: " << minStack.top() << endl;    // should print 0
    cout << "Min: " << minStack.getMin() << endl; // should print -2

    return 0;
}
