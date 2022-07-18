
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class CircularQ{

    int *arr;
    int size,front,rear;

    public:

    CircularQ(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    
    int Dequeue()
    {
        if(front == -1 && rear == -1)
        return -1;

        int x = arr[front];
        arr[front] = -1;

        if(front == rear) // single element
        front = rear = -1;

        else if(front == size-1)//cyclic nature
        front = 0;

        else//normal case;
        front++;

        return x;
    }

    bool Enqueue(int val)
    {
        if((front == 0 && rear == size -1) && (rear == (front-1) % (size-1)))
        return false;
        
        if(front != -1 && rear == size-1)//cyclic nature
        rear = 0;

        else if(front == -1) //first insertion
        front = rear = 0;

        else //normal case
        rear++;

        arr[rear] = val;
        return true;

    }

};

int main()
{
    
    return 0;
}