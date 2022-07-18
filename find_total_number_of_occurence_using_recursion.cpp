#include <iostream>
using namespace std;

int fisrt_occ(int *arr, int start, int end, int target, int size)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target && (arr[mid - 1] < target || mid == 0))
        return mid;

    else if (arr[mid] < target)
        fisrt_occ(arr, mid + 1, end, target, size);

        else
        fisrt_occ(arr,start , mid-1, target ,size);
}

int last_occ(int *arr, int start ,int end , int target , int size)
{
    if(start > end)
    return -1;

    int mid = start +(end - start)/2;

     if ((mid == size - 1 || target < arr[mid + 1]) && arr[mid] == target)
            return mid;
      else if (target < arr[mid])
            return last_occ(arr, start, (mid - 1), target, size);
        else
            return last_occ(arr, (mid + 1), end, target, size);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 7, 7, 8};
    int size = sizeof(arr) / sizeof(int);
    int target = 7;

    int Total_occ = last_occ(arr, 0, size - 1, target, size) - fisrt_occ(arr, 0, size - 1, target, size) +1;
    cout<<Total_occ;
    // cout<<last_occ(arr, 0, size - 1, target, size)<<" "<< fisrt_occ(arr, 0, size - 1, target, size);
    return 0;
}