#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

void BuildTree(int index,int start,int end,int *arr,int *segment)
{
    if(start == end)
    {
        segment[index] = arr[start];
        return;
    }

    int mid = start + (end - start)/2;
    BuildTree(2*index+1,start,mid,arr,segment);
    BuildTree(2*index+2,mid+1,end,arr,segment);

    segment[index] = max(segment[2*index+1],segment[2*index+2]);
}


int query(int index,int start,int end,int leftrange,int rightrange,int *segment)
{
    if(start >= leftrange && end <= rightrange)//if the start and end lies in the range(case 1)
    return segment[index];

    if(start > rightrange || end < leftrange )//if start and end does not lies in the range(case 2)
    return INT_MIN;

    int mid = start + (end - start)/2; //(search in rest part (case 3))

    int leftans = query(2*index+1,start,mid,leftrange,rightrange,segment);
    int rightans = query(2*index+2,mid+1,end,leftrange,rightrange,segment);

    return max(leftans,rightans);
}


int main()
{
    // left child index -> 2*i+1 where i is the parent index (zero based indexing)
    // right child index -> 2*i+2 where i is the parent index (zero based indexing)

    int arr[] = {8,2,5,1,4,5,3,9,6,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    int n = size *4;
    int *segment = new int[n];
    BuildTree(0,0,size-1,arr,segment);

    for(int i = 0 ; i < n ; i++)
    {
        cout << segment[i] <<" ";
    }cout << endl;

    int leftrange = 3 ,rightrange = 7;

    cout << "Max element in the range is: "<< query(0,0,size-1,leftrange,rightrange,segment) << endl;

    return 0;
}