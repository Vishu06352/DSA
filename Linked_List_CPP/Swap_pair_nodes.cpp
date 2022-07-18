#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void Traversal(Node *head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
}

void insert_at_end(Node *&tail,Node *&head , int data)
{
    if(tail == NULL)
    {
        Node *NN = new Node(data);
        tail = NN;
        head = NN;
    }

    else
    {
        Node *NN = new Node(data);
        tail -> next = NN;
        tail = tail -> next;
    }
}

void swap(Node *&head)
{
    Node *current = head -> next;
    Node *prev = head;
    Node *forward = NULL;
    Node *backward = NULL;

    bool ask = true;
    int cnt = 0;

    while(current != NULL)
    {
        forward = current -> next ;
        prev -> next = current -> next;
        current -> next = prev;

        if(ask)
        {
            head = current;
            ask = false;
        }

        if(cnt > 0)
        {
            backward -> next = current;
        }

        backward = prev;
        prev = forward;
        if(forward == NULL)
        {
            current = forward;
        }
        else{
        current = forward -> next;
        }
        cnt ++;

    }
}

int main()
{
    Node *head = NULL;
    Node *tail = head;

    insert_at_end(tail,head,1);
    insert_at_end(tail,head,2);
    insert_at_end(tail,head,3);
    insert_at_end(tail,head,4);
    insert_at_end(tail,head,5);
    Traversal(head);

    swap(head);
    Traversal(head);

    return 0;
}