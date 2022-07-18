#include <iostream>
using namespace std;

int peak_index(int *arr, int start, int end)
{
    if (start > end)
        return -1;

    int mid = start + (end + start) / 2;

    if ((arr[mid - 1] < arr[mid]) && (arr[mid] < arr[mid - 1]))
        return mid;

    else if (arr[mid] < arr[mid + 1])
    peak_index(arr, mid + 1, end);

    else
    peak_index(arr, start, mid);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<size;
    cout << "peak element index is -> " << peak_index(arr, 0, size - 1);
    return 0;
}