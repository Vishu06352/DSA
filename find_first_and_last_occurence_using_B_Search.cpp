#include<iostream>
using namespace std;

int fisrt_occ(int *arr , int size ,int target)
{
    int occurence = -1;
    int start = 0 ; 
    int end = size-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(arr[mid] == target)
        {
            occurence = mid;
            end = mid - 1;
        }

        else if (arr[mid] < target)
                start = mid + 1;

        else
        end = mid - 1;
    }
    return occurence;    
}

int last_occ(int *arr,int size , int target)
{
    int occurence = -1;
    int start = 0 ; 
    int end = size -1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(arr[mid] == target)
        {
            occurence = mid; 
            start = mid + 1;
        }

        else if(arr[mid] < target )
        start = mid +1;

        else
        end = mid -1;
    }

    return occurence;
}
int main()
{

    int arr[] ={1,2,3,4,5,6,7,7,7,7,7,8};
    int size = 12;
    int target = 7;

    cout<<fisrt_occ(arr,size,target)<<endl;
    cout<<last_occ(arr,size,target)<<endl;

    return 0;
}