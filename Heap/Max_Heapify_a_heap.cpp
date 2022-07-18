#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

void Max_heapify(int *arr,int given_parent_index,int n)
{
    int parent_index = given_parent_index;
    int left_child_index = 2 * parent_index;
    int right_child_index = 2 * parent_index + 1;

    if(left_child_index <= n && arr[parent_index] < arr[left_child_index])
    {
        parent_index = left_child_index;
    }
    if(right_child_index <= n && arr[parent_index] < arr[right_child_index])
    {
        parent_index = right_child_index;
    }

    if(parent_index != given_parent_index)
    {
        swap(arr[given_parent_index],arr[parent_index]); 
        Max_heapify(arr,parent_index,n); // recursive call will come into play when the index is less than n/2 i.e for smaller index it will balance the rest of heap
    }

}

int main()
{
    int arr[] = {-1,7,10,4,3,20,15};
    int n = 6;

    for(int i = n/2 ; i > 0 ; i--)
    {
        Max_heapify(arr,i,n);
    }

    cout <<"Max heap of the array "<<endl;
    for(int i = 1 ; i  <= n ; i++)
    {
        cout << arr[i] <<" ";
    }cout<<endl;

    return 0;
}