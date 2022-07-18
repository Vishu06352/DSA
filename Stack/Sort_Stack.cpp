#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void sort(stack<int>&s1,int num)
{
    if((!s1.empty() && s1.top() <= num )|| s1.empty())  ////IMPORTANT BASE CASE PLEASE GO THROUGH IT CHECK S.EMPTY() && CONDITION
    {
        s1.push(num);
        return;
    }
    int num2 = s1.top();
    s1.pop();
    sort(s1,num);
    s1.push(num2);
}

void emptyStack(stack<int>&s1)
{
    if(s1.empty())
    {
        return;
    }
    int num = s1.top();
    s1.pop();
    emptyStack(s1);
    
    sort(s1,num);
}

int main()
{
    stack<int>s;
    stack<int>s1;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    // s1.push(s.top());
    // s.pop();
    emptyStack(s);
    
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    return 0;
}