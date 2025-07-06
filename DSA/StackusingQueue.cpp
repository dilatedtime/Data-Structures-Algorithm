#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    int front = -1;
    int size=0;

    MyStack()
    {
    }

    void push(int x)
    {        
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        size+=1;
        
    }

    int pop()
    {
        if (size == 0)
        {
            cout << "Stack Underflow\n";
            return -1; // or throw an exception
        }
        else
        {
            int temp = q1.front();
            q1.pop();
            size-=1;
            return temp;
        }
    
    }

    int top()
    {
        if (size == 0)
        {
            cout << "Stack is empty\n";
            return -1; // or throw an exception
        }
        else
            return q1.front();
    }

    bool empty()
    {
        if (size== 0)
            return 1;
        else
            return 0;
    }
};

int main()
{
    MyStack stack;
    stack.push(5);
    stack.push(10);
    stack.push(7);
    stack.push(0);
    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    stack.push(11);
    stack.push(98);
    cout << stack.empty() << endl;
    stack.push(47);
    cout << stack.top() << endl; // Output: 10
    cout << stack.pop() << endl; // Output: 10
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    cout << stack.empty() << endl; // Output: 0 (false)

    return 0;
}
