#include <iostream>
using namespace std;

class ArrayQueue
{
public:
    int q[1000];
    int front = -1;
    int back = -1;
    int size = 0;

    ArrayQueue()
    {
    }

    void push(int x)
    {

        if (size >= 1000)
        {
            cout << "Queue Overflow\n";
            return;
        }
        else if (front == back && front == -1)
        {
            front += 1;
            back += 1;
            q[back] = x;
            size += 1;
        }
        else
        {
            back = (back + 1) % 1000;
            q[back] = x;
            size += 1;
        }
    }

    int pop()
    {
        if (front == -1)
        {
            cout << "Queue Underflow\n";
            return -1; // or throw an exception
        }
        else
        {
            int temp = q[front];
            front = (front + 1)%1000;
            size -= 1;
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
            return q[front];
    }

    bool isEmpty()
    {
        if (size == 0)
            return 1;
        else
            return 0;
    }
};

int main()
{
    ArrayQueue Queue;
    Queue.push(5);
    Queue.push(10);
    Queue.push(7);
    Queue.push(0);
    cout << Queue.peek() << endl;
    cout << Queue.pop() << endl;
    Queue.push(11);
    Queue.push(98);
    cout << Queue.isEmpty() << endl;
    Queue.push(47);
    cout << Queue.peek() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.peek() << endl;
    cout << Queue.isEmpty() << endl; // Output: 0 (false)

    return 0;
}
