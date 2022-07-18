#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class queue
{
private:
    int *arr;
    int size, front, rear;

public:
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
         rear = 0;
    }

    bool isEmpty()
    {
        if (front == rear)
            return true;

        return false;
    }
    int full()
    {
        if (front == rear)
            return -1;

        return arr[front];
    }

    bool Enqueue(int val)
    {
        if (rear == size)
            return false;

        arr[rear++] = val;
        return true;
    }

    int Dequeue()
    {
        if (front == rear)
            return -1;

        int x = arr[front];
        arr[front] = -1;
        front++;

        if (front == rear)
        {
            front = 0;
             rear = 0;
        }
        return x;
    }
};

int main()
{
    queue q(3);
    
    if(q.Enqueue(10))
    cout << "Value Entered" << endl;
    else
    cout << "Queue is full" << endl;

    if(q.Enqueue(20))
    cout << "Value Entered" << endl;
    else
    cout << "Queue is full" << endl;

    if(q.Enqueue(30))
    cout << "Value Entered" << endl;
    else
    cout << "Queue is full" << endl;

    if(q.Enqueue(30))
    cout << "Value Entered" << endl;
    else
    cout << "Queue is full" << endl;

   

    return 0;
}