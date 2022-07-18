#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void previous_Greatest(int *arr, int size)
{
    stack<int>st;
    st.push(-1);
    
    for(int i = 0 ; i  < size ; i++)
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
    int arr[] = {2,1,5,6,2,3};
    previous_Greatest(arr,6);    
    return 0;
}