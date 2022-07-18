#include<iostream>
#include<stack>
#include <vector>
#include<algorithm>
using namespace std;

void previous_Greatest(int *arr, int size)
{
    stack<int>st;
    vector<int>prev;
    st.push(-1);

    for(int i = 0 ; i < size ; i ++)    
    {
        while(st.top() != -1 &&  arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        prev.push_back(st.top());
        st.push(i);
    }
    
    for(int i = 0 ; i  < size ; i++)
    {
        cout << prev[i] << " ";
    }
}

int main()
{
    int arr[] = {2,1,5,6,2,3};
    previous_Greatest(arr,6);    
    return 0;
}