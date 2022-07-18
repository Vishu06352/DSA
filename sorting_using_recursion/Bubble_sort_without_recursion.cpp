#include<iostream>
using namespace std;

void bubble_Sort(int arr[] , int size)
{
    bool sort = true;
    for(int i = 1 ; i < size ; i++)
    {
        for(int  j = 0 ; j < size-i ; j++ )
        {
            if(arr[j] > arr[j+1])
            { 
                swap(arr[j],arr[j+1]);
                sort = false;
            }
        }
        if(sort == true)
            break;
    }
}

int main()
{
    int arr [] = {1,2,3,4,5,44,8};
    int size = sizeof(arr) / sizeof(int);

    bubble_Sort(arr,size);

    for(int i = 0 ; i < size ; i++)
    cout << arr[i] << " ";

    return 0;
}