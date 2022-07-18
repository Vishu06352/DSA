#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insertion()
    {
        size++;
        cout << "Enter the data for insertion in heap array: ";
        cin >> arr[size];

        if (size > 1)
        {
            int childIndex = size;
            int parentIndex = childIndex / 2;

            while (parentIndex >= 1)
            {
                if (arr[parentIndex] < arr[childIndex])
                {
                    swap(arr[parentIndex], arr[childIndex]);
                    childIndex = parentIndex;
                    parentIndex = childIndex / 2;
                }

                else
                    return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "Noting to delete from heap array" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int parent_index = 1;

        while(parent_index < size)
        {
            int child_Index1 = 2*parent_index;
            int child_Index2 = 2*parent_index+1;


            if(child_Index1 <= size && arr[parent_index] < arr[child_Index1] )
            {
                swap(arr[parent_index] , arr[child_Index1]);
                parent_index = child_Index1;
            }

            else if(child_Index2 <= size && arr[parent_index] < arr[child_Index2])
            {
                swap(arr[parent_index] , arr[child_Index2]);
                parent_index = child_Index2;
            }

            else
            return;
        }
    }
};

int main()
{
    heap h;
    h.insertion();
    // h.print();
    h.insertion();
    // h.print();
    h.insertion();
    // h.print();
    h.insertion();
    // h.print();
    h.insertion();
    h.print();

    h.deletion();
    h.print();

    return 0;
}