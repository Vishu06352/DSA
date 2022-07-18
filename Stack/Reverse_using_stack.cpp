#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Stack
{
    public:
    char *arr;
    int size;
    int top ;

    Stack(){}
    Stack(int size)
    {
        this -> size = size;
        arr = new char[size];
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

    char pop()
    {
        if(top >= 0)
        {
            char x ;
            x = arr[top--];
            return x;
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
    string str = "Vishu Yadav";

    Stack s(15);

    for (int i = 0; i < str.length() ;i++)
    {
        s.push(str[i]);
    }

    for (int i = 0; i < str.length() ;i++)
    {
        str[i] = s.pop();
    }
    cout << str;
    
    
    return 0;
}