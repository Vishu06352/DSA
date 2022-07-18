#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Stack
{
    public:
    int *arr;
    int size;
    int top ;

    Stack(){}
    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    int isEmpty()
    {
        if(top == -1)
            return 1;

            return 0;   
    }
    int isFull()
    {
        if(top == size)
        return 1;

        return 0;
    }
    void push(int data)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        cout << "Stack is overflow" << endl;
    }

    void pop()
    {
        if(top >= 0)
        {
            int x = -1;
            x = arr[top--];
            cout << "Element " << x << " is poped out" << endl;
        }
        else
        cout << "Stack is underFlow" << endl;
    }
    int peek()
    {
        if(top >= 0)
        return arr[top];

        else
        cout << "Stack is underFlow"<< endl;
    }

    int Stack_size()
    {
        return top;
    }
};

int main()
{
    Stack s(5);
    cout << "Size of stack is " << s.Stack_size() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.pop();
    s.pop();
    return 0;
}