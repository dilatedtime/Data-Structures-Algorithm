#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> st1;
    stack<int> st2;
    int top = -1;
    int bot = -1;
    int size = 0;

    MyQueue()
    {
    }

    void push(int x)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        size += 1;
    }

    int pop()
    {
        if (size==0)
        {
            cout << "Queue Underflow\n";
            return -1; // or throw an exception
        }
        else
        {
            int temp = st1.top();
            size -= 1;
            st1.pop();
            return temp;
        }
    }

    int peek()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return -1; // or throw an exception
        }
        else
            return st1.top();
    }

    bool empty()
    {
        if (size == 0)
            return 1;
        else
            return 0;
    }
};

int main()
{
    MyQueue Queue;
    Queue.push(5);
    Queue.push(10);
    Queue.push(7);
    Queue.push(0);
    cout << Queue.peek() << endl;
    cout << Queue.pop() << endl;
    Queue.push(11);
    Queue.push(98);
    cout << Queue.empty() << endl;
    Queue.push(47);
    cout << Queue.peek() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.peek() << endl;
    cout << Queue.empty() << endl; // Output: 0 (false)

    return 0;
}
