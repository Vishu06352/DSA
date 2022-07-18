#include<iostream>
using namespace std;

int fisrt_occ(int* arr , int start , int end ,int target, int n)
{
    if(start > end )
    return -1; 

    int mid = start + (end - start)/2;

    if(arr[mid] == target && (mid == 0 || arr[mid-1] < target))
         return mid;

    else if(arr[mid] < target)
    fisrt_occ(arr, mid+1 , end ,target, n);

    else
    fisrt_occ(arr,start,mid-1,target, n);
}

int last_occ(int* arr , int start , int end ,int target,int n)
{
    if(start > end)
    return -1;

        int mid = start + (end - start) / 2;
        if ((mid == n - 1 || target < arr[mid + 1]) && arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            return last_occ(arr, start, (mid - 1), target, n);
        else
            return last_occ(arr, (mid + 1), end, target, n);
}

int main()
{

    int arr[] ={1,2,3,4,5,7,7,7,8};
    int size = sizeof(arr)/sizeof(int);
    int target = 7;

    cout<<fisrt_occ(arr,0,size-1,target,size)<<endl;
    cout<<last_occ(arr,0,size-1,target,size)<<endl;

return 0;
}