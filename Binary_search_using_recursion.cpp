#include<iostream>
using namespace std;

bool search(int *arr,int start , int end,int target)
{

    if(start > end)
    return false;

    int mid = start +(end-start)/2;

    if(arr[mid] == target)
    return true;

    else if(arr[mid] < target)
    search(arr,mid+1,end,target);

    else
    search(arr,start,mid-1,target);
}

int main()
{

    int arr[] ={1,2,3,4,5,6,7,8};
    int size = 8;
    int target = 6;

    if(search(arr,0,size-1,target))
    cout<<"Target is present"<<endl;

    else
    cout<<"Target is not present"<<endl;

    return 0;
}