#include<iostream>
using namespace std;

void selectionSort(int *arr,int size)
{
    for(int i = 0 ; i < size-1 ; i++)
    {
        int index = -1;
        int val = arr[i];
        for(int j = i+1 ; j < size ; j++)
        {
            if(val > arr[j])
            {
                val = arr[j];
                index = j;
            }
        }
        if(index != -1)
        swap(arr[i],arr[index]);
    }
}

int main()
{
    int size;
    cout <<"Enter the size of the array "<<endl;
    cin>>size;
    
    int *arr = new int[size];
    
    for(int i = 0 ; i < size ; i++)
    {
        cout <<"Enter the element at index "<< i <<" : ";
        cin>>arr[i];
    }
    
    selectionSort(arr,size);
    
    for(int i = 0 ; i < size ; i++)
    {
        cout <<arr[i] <<" ";
    }
}