#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

void add(stack<int>&st,int element)
{
    if(st.empty())
    {
        st.push(element);
        return;
    }
    
    int x = st.top();
    st.pop();
    
    add(st,element);
    
    st.push(x);
}

int main()
{
    stack<int>st;
    st.push(21);
    st.push(67);
    st.push(132);
    st.push(2);
    st.push(1);
    
    add(st,99);
    
    for (int i = 0; i < 6; i++) {
        
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}
