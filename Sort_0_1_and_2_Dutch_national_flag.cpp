#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int arr[] = {0, 2, 1, 2, 1, 0, 0, 0, 1, 0, 1, 2, 2, 0};
    int size = sizeof(arr) / sizeof(int);

    int i = 0,k=0;
    int j = size-1;

    while(i <= j )
    {
        if(arr[i] == 1)    //hadling 1
        i++;

        else if(arr[i] == 2)   //handling 2
        swap(arr[i],arr[j--]);

        else         // handing zero
        swap(arr[i++],arr[k++]);

    }

    for(int i = 0 ; i  < size ; i++)
    {
        cout<< arr[i] << " ";
    }

    return 0;
}