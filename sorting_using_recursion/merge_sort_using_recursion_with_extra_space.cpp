#include<iostream>
using namespace std;

void merge(int *arr , int start , int end)
{
    //take picture of original arr divided into 2 parts...........imp.................
    int mid = start + (end -start)/2;

    int length1 = mid - start + 1;
    int length2 = end - mid;

    // abb do array bana lo dynamically for temperory purpose
    int *first = new int[length1];
    int *second = new int[length2];

    // abb dobara take picture of original arr divided into 2 parts and these 2 parts need to be copy into temporary array first and second

    int k = start; //  k is the index of the mainarray which we get in parameter of the function (merge)
    
    for(int i = 0 ; i < length1 ; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < length2; i++)
    {
        second[i] = arr[k++];
    }

    k = start;
    int index1 = 0 , index2 = 0;
    //abb sorting start karo aur original array arr mein dal do

    while(index1 < length1 && index2 < length2)
    {
        if(first[index1] < second[index2])
        arr[k++] = first[index1++];

        else
        arr[k++] = second[index2++];
    }
     // check kar lena ki agar ko array abhi bach hua h toh usse bas copy kardena original arr m
    while (index1 < length1)
    {
        arr[k++] = first[index1++];
    }
    while(index2 < length2)
    {
        arr[k++] = second[index2++];
    }

}

void sort(int *arr , int start , int end)
{
    if(start >= end)
    return ;

    int mid = start + (end - start)/2;

    //left part ko toodo
    sort(arr, start , mid);

    //right part ko toodo
    sort(arr,mid+1,end);

    // abb merging start kar do toote hue array ki in sorting manner using merging 2 array logic
    merge(arr,start,end);
}

int main()
{
    int arr[] = {21,45,2,6,875,54,4};
    int size = sizeof(arr)/sizeof(int);

    sort(arr,0,size-1);
    for (int i = 0; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}