#include<iostream>
using namespace std;

int find_pivot_index(int *arr, int start , int end)
{
    int pivot = arr[start];
    int count = 0;
    
    //for counting the element less then the pivot
    for(int i = start + 1 ; i <= end ; i++ )
    {
        if( pivot >= arr[i] )
        count++;
    }
 
    //getting pivot position in the array with the help of count
    int pivot_index = count + start ;
    
    //now swapping the pivot with its right position
    swap(arr[start], arr[pivot_index]);

    //checking the left part need to be smaller then the pivot and the right part element need to be greater then the pivot
    int i = start , j = end;
    
    while(i < pivot_index && j > pivot_index)
    {
        while(arr[i] < pivot)
        i++;

        while(arr[j] > pivot)
        j--;

        if(arr[i] >= pivot && arr[j] < pivot)
        swap(arr[i++],arr[j--]);

    }
    return pivot_index;
}

void quickSort(int *arr , int start , int end)
{
    if(start >= end)
    return ;

    //Tip to remeber quicksort -> is that it is tail recursion so first we have to find the pivotindex using find_pivot_index and then apply quicksort recursively
    int pivot_index = find_pivot_index(arr,start,end);

    quickSort(arr,start, pivot_index-1);
    quickSort(arr,pivot_index+1,end);

}


int main()
{
    int arr[] = {21,34,54,2,12,54,76,42,11};
    int size = sizeof(arr) / sizeof(int);

    quickSort(arr,0,size-1);
    for(int i = 0 ; i < size ; i++)
    {
        cout<<arr[i] << " ";
    }

    return 0;
}