#include <iostream>
using namespace std;

class ArrayStack
{
public:
    int st[1000];
    int front = -1;
    
    ArrayStack()
    {
        
    }

    void push(int x)
    {

        if (front >= 99)
        {
            cout << "Stack Overflow\n";
            return;
        }
        else
            front += 1;
        st[front] = x;
        // size += 1;
    }

    int pop()
    {
        if (front == -1)
        {
            cout << "Stack Underflow\n";
            return -1; // or throw an exception
        }
        else
        {
            int temp = st[front];
            front = front - 1;
            return temp;
        }
    }

    int top()
    {
        if (front == -1)
        {
            cout << "Stack is empty\n";
            return -1; // or throw an exception
        }
        else
            return st[front];
    }

    bool isEmpty()
    {
        if (front == -1)
            return 1;
        else
            return 0;
    }
};

int main()
{
    ArrayStack stack;
    stack.push(5);
    stack.push(10);
    stack.push(7);
    stack.push(0);
    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    stack.push(11);
    stack.push(98);
    cout << stack.isEmpty() << endl;
    stack.push(47);
    cout << stack.top() << endl;     // Output: 10
    cout << stack.pop() << endl;     // Output: 10
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    cout << stack.isEmpty() << endl; // Output: 0 (false)

    return 0;
}
