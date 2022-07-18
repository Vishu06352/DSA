#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

void Min_heapify(int *arr,int given_parent_index ,int n)
{
    int parent_index = given_parent_index;
    int left_child_index = 2 * parent_index;
    int right_child_index = 2 * parent_index + 1;

    if(left_child_index <= n && arr[parent_index] > arr[left_child_index]) // first check whether a left child exist or not then compare the values at left_child_index & parent_index
    {
        parent_index = left_child_index;
    }
    if(right_child_index <= n && arr[parent_index] > arr[right_child_index]) // first check whether a left child exist or not then compare the values at right_child_index & parent_index
    {
        parent_index = right_child_index;
    }

    if(parent_index != given_parent_index) //means that heap is not in mini heap so just modify it to mini heap
    {
        swap(arr[parent_index],arr[given_parent_index]);
        Min_heapify(arr,parent_index,n);
    }
}


int main()
{
    int arr[] = {-1,3,2,3,1,2};
    int n = 5;
    for(int i = n/2; i > 0 ; i--)
    {
        Min_heapify(arr,i,n);
    }

    cout<<"Min Heap of the given array"<<endl;

    for(int i = 1 ; i  <= n ; i++)
    {
        cout << arr[i] <<" ";
    }
    return 0;
}