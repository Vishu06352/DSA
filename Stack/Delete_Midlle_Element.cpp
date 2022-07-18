#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void deletee(stack<int>&st,int cnt,int size)
{
    if(cnt == size/2)
    {
        st.pop();
        return;
    }
    
    int x = st.top();
    st.pop();
    
    deletee(st,cnt+1,size);
    st.push(x);
}

int main() // code shi h but print tab shi show kare ka jab actual size khud input karo gye agar st.size use kiya toh galt print kare ga
{
    stack<int>st;

    st.push(21);
    st.push(1);
    st.push(5);
    st.push(4);
    st.push(24);
    
    deletee(st,0,st.size());
    
    for (int i = 0; i < 4; i++) {
        
        cout << st.top() << " ";
        st.pop();
    }
    
    
    return 0;
}