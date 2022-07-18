#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if(this -> next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void Traversal(Node *&tail)
{
    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }while (temp != tail);
    cout << endl;
}

void insert_at_tail(Node *&tail,int key, int d)
{
    if(tail == NULL)
    {
        Node *NN = new Node(d);
        NN -> next = NN;
        tail = NN;
    }
    else
    {
        Node *current = tail;

        while(current -> data != key)
        {
            current = current -> next;
        }
        Node *NN = new Node(d);
        NN -> next = current -> next;
        current -> next = NN;
    }
}

void deleteNode(Node *&tail ,int key)
{
    Node *prev = tail;
    Node *current = prev ->next;


    while(current -> data != key)
    {
        prev = current;
        current = current -> next;
    }

    prev -> next = current -> next;
    if(tail == current)
    {
        tail = prev;
    }
    current -> next = NULL;
    delete current;
}
int main()
{
    Node *tail = NULL;

    insert_at_tail(tail,-1,10);
    Traversal(tail);

    insert_at_tail(tail,10,20);
    Traversal(tail);

    insert_at_tail(tail,20,30);
    Traversal(tail);

    insert_at_tail(tail,10,-11);
    Traversal(tail);
    
    insert_at_tail(tail,-11,99);
    Traversal(tail);

    deleteNode(tail,10);
    Traversal(tail);

    return 0;
}