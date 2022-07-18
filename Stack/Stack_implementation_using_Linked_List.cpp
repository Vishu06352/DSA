#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data){
   this -> data = data;
   this -> next = NULL;
    }

    ~Node(){
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
    }
};

void Traversal(Node *&head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
}

void push(Node *&head,Node *&tail,Node* &top,int data)
{
    if(tail == NULL)
    {
        Node * NN = new Node(data);
        tail = NN;
        head = NN;
        top = NN;
    }
    else{
        Node * NN = new Node(data);
        tail ->next = NN;
        tail = NN;
        top = tail;
    }
}

bool isEmpty(Node* &tail)
{
    if(tail == NULL)
    return true;

    return false;
}

void pop(Node* &tail , Node* &top ,Node* &head )
{
    if(isEmpty(tail))
    cout << "Stack is underFlow" << endl;

    else
    {
        Node *current = head;
        Node *prev = NULL;

        if(current -> next == NULL)
        {
            head = NULL;
            tail = NULL;
            top = NULL;
            cout << "Element " << current -> data << " is deleted successfully" << endl;
            delete current;
            return;
        }

        while(current -> next != NULL)
       {
           prev = current;
           current = current -> next;
       }
       prev -> next = NULL;
       tail = prev;
       top = prev;

        cout << "Element " << current -> data << " is deleted successfully" << endl;
       current -> next = NULL;
       delete current;
    }
}
int main()
{
    Node *head = NULL;
    Node* tail = head;
    Node* top = tail;

    if(isEmpty(tail))
    cout << "Stack is Empty" << endl;

    else
    cout << "Stack is not empty" << endl;

    push(head,tail,top,1);
    push(head,tail,top,2);
    push(head,tail,top,3);
    push(head,tail,top,4);

    pop(tail,top,head);
    pop(tail,top,head);
    pop(tail,top,head);
    pop(tail,top,head);
    pop(tail,top,head);

    push(head,tail,top,3);
    pop(tail,top,head);
    return 0;
}