#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    //-----------------------------------MAX HEAP--------------------------------------------
    cout <<"Max Heap"<<endl;
    priority_queue<int>q;

    q.push(3);
    q.push(2);
    q.push(5);
    q.push(4);

    cout<<"Q top is -> " << q.top() << endl;
    q.pop();
    cout<<"Q top is -> " << q.top() << endl;
    q.pop();

    //-----------------------------------MIN HEAP------------------------------------------------

    cout <<endl<< "MIN Heap"<<endl;
    priority_queue<int,vector<int>, greater<int> > minHeap;

    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(4);

    cout<<"Q top is -> " << minHeap.top() << endl;
    minHeap.pop();
    cout<<"Q top is -> " << minHeap.top() << endl;
    minHeap.pop();

    /*
        1. By default mode of priority queue is MAX heap
        2. Creation on min heap is as follow priority_queue<int,vector<int>, greater<int> > minHeap;
    */
   
    return 0;
}