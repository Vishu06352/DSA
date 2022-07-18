#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
    public :
    int data ;
    Node *next , *prev;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
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

void insert_at_tail(Node *&head,Node *&tail,int d)
{
    if(tail == NULL)
    {
        Node *NN = new Node(d);
        tail = NN;
        head = tail;
    }

    else{
        Node *NN = new Node(d);
        NN -> prev = tail;
        tail -> next = NN;
        tail = NN;
    }
}

void reverseList(Node* &head,Node* Forward,Node* Backward,Node* current)
{
    if(current == NULL)
    {
        head = Backward;
        return ;
    }
        
}

int main()
{
    Node *head = NULL;
    Node *tail = head;

    insert_at_tail(head,tail,1);
    insert_at_tail(head,tail,2);
    insert_at_tail(head,tail,3);
    insert_at_tail(head,tail,4);
    insert_at_tail(head,tail,5);

    Traversal(head);

    Node* Backward = NULL;
    Node* current = head ;
    Node* Forward = NULL;
    reverseList(head,Forward,Backward,current);
    Traversal(head);

    
    return 0;
}