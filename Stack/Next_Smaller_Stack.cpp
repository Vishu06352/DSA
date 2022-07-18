#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void find(int *arr,int n)
{
    stack<int>st;
    st.push(-1);
    int j = n-1;
    
    while(j >= 0)
    {
        if(st.top() < arr[j])
        {
            int val = arr[j];
            arr[j] = st.top();
            st.push(val);
            // cout << "1";
        }
        else  // do not use else if as it is giving error or if you want to use the also use equal to sign  -------------(st.top() >= arr[j])--------------
        {
            // cout << "2";
            int flag = 1;

            while(st.top() != -1)
            {
                st.pop();
                if(st.top() < arr[j])
                {
                    int val = arr[j];
                    arr[j] = st.top();
                    st.push(val);
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                int val = arr[j];
                arr[j] = st.top();
                st.push(val);
            }
        }
        j--;
    }

}

int main()
{
    int arr[] = {2,1,5,6,2,3 };
    find(arr,6);

    for(auto i : arr)
    {
        cout << i <<" ";
    }
    return 0;
}