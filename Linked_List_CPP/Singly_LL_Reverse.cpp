#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    //yeh constructor bana pade ga taki head ya first node intiallize kar paye aur baad me new nodes bhi create kar paye
    Node(int data)
    {
        this -> data = data;
        this->next = NULL;
    }

};

void Traversal(Node *&head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
}

void insertion_at_end(Node *&head,int d){

    if(head == NULL)
    {
        Node *NN = new Node(d);
        head = NN;

    }
    else{
    Node *temp = head;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    Node *NN = new Node(d);

    temp -> next = NN;
    }
}

void reverse(Node *&head,Node*current,Node*prev,Node*forward)
{
    if(current == NULL)
    {
        head = prev;
        return;
    }
    
    forward = current -> next;
    current -> next = prev;
    prev = current;
    current = forward;

    reverse(head,current,prev,forward);
}

int main()
{
    Node *head = NULL;
    insertion_at_end(head,1);
    insertion_at_end(head,2);
    insertion_at_end(head,3);
    insertion_at_end(head,4);
    insertion_at_end(head,5);
    insertion_at_end(head,6);
    insertion_at_end(head,7);
    // insertion_at_end(head,8);

    // Traversal(head);

    Node *prev = NULL;
    Node *current = head;
    Node *forward = NULL;

    reverse(head ,current,prev,forward);
    Traversal(head);

    return 0;
}