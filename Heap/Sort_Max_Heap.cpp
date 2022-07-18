#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

void Max_Heapify(int *arr,int given_parent_index, int n)
{
    int parent_index = given_parent_index;
    int left_child_index = 2* parent_index;
    int right_child_index = 2 * parent_index +1;

    if(left_child_index <= n && arr[parent_index] < arr[left_child_index])
        parent_index = left_child_index;

    if(right_child_index <= n && arr[parent_index] < arr[right_child_index])
        parent_index = right_child_index;

    if(parent_index != given_parent_index){
        swap(arr[given_parent_index],arr[parent_index]);
        Max_Heapify(arr,parent_index,n);
    }
}


void sortHeap(int *arr,int n) // sortHeap(int *arr,int n,vector<int>&ans)
{

    if(n == 0)
    return;

    // ans[n-1] = arr[1];//instead of reversing the ans vector at the end we store the arr array input in reverse manner but remember that we have to declare the size of vector in starting
    swap(arr[1],arr[n]);
    n--;

    
    Max_Heapify(arr,1,n); // instead of using the whole for loop directly give the index of the first node

    sortHeap(arr,n); // sortHeap(arr,n,ans);
}
int main()
{
    // vector<int>ans(5);
    int arr[] = {-1,90,70,80,30,40};
    int n = 5;

    sortHeap(arr,n);

    // for(auto i : ans)
    // {
    //     cout << i <<" ";
    // }
    
    for(int i = 1 ; i  <= 5 ; i++)
    {
        cout<<arr[i] <<" ";
    }

    /*
        -------------------------------------Notes --------------------------

        1. do not use any other space to store the ans like a vector ans 
        2. just swap the values in the original array and decrement the size so that no one can use it again
        3. for heapify the function just pass on the 1 as the given_parent_index instead of starting it from n/2 index
    */

    return 0;
}