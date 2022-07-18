#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

void insert_at_bottom(stack<int>&st,int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    
    int xx = st.top();
    st.pop();
    
    insert_at_bottom(st,x);
    
    st.push(xx);
    
}


void reversee(stack<int>&st)
{
    if(st.empty())
    {
        return ;
    }
    
    int x = st.top();
    st.pop();
    
    reversee(st);
    
    insert_at_bottom(st,x);
    
}

int main()
{
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
   
    for (int i = 0; i < 4; i++) {
        
        cout << st.top() << " ";
        st.pop();
    } cout << endl;


    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    reversee(st);
    
    for (int i = 0; i < 4; i++) {
        
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}
