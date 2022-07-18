#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class doublyQ{

    int *arr;
    int size,front,rear;

    public:

    doublyQ(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    int Dequeue_rear()
    {
        if(front == -1 && rear == -1)
        return -1;

        int x = arr[rear];
        arr[rear] = -1;

        if(front == rear) //single element 
        front = rear = -1;

        else if(rear == 0) //cyclic nature
        rear = size -1;

        else//normal case
        rear --;

        return x;

    }
    int Dequeue_front()
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

    bool Enqueue_front(int val)
    {
                if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)) ) // important as we have included front!=0 in this case i.e diff from circular queue
            return false;

            if(front == -1 && rear == -1) // first insertion
            front = rear = 0;

            else if(front == 0) // cyclic nature
            front = size-1;

            else // normal case
            front--;

            arr[front] = val;
            return true;
    }
    bool Enqueue_rear(int val)
    {
         if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)) ) // important
        return false;

        else if(front == -1)//first insertion
        front = rear = 0;
        
        if(front != -1 && rear == size-1)//cyclic nature
        rear = 0;

        else//normal case
        rear++;

        arr[rear] = val;
        return true;

    }

};

int main()
{
    
    return 0;
}