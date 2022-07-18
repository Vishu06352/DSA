#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void previous_Greatest(int *arr, int size)
{
    stack<int>st;
    st.push(-1);
    
    for(int i = size-1 ; i  >= 0 ; i--)
    {
        while(st.top() <= arr[i] && st.top() != -1)
        {
            st.pop();
        }
        int val = arr[i];
        arr[i] = st.top();
        st.push(val);
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " ;
    }
    
}

int main()
{
    int arr[] = {7,4,1,9,2};
    previous_Greatest(arr,5);    
    return 0;
}