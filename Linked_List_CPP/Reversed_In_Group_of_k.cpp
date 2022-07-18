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

Node *reverse(Node *&head,int k)
{
   if(head == NULL)
   {
       return NULL;
   }

    Node *prev = NULL;
    Node *current = head;
    Node *forward = NULL;
    int i = 0;
    while(i < k && current != NULL)
    {
        forward = current -> next;
        current -> next = prev;
        prev = current;
        current = forward;
        i++;
    }

    if(forward != NULL)
        head -> next = reverse(forward,k);

    return prev;
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
    insertion_at_end(head,8);


    Node *prev = NULL;
    Node *current = head;
    Node *forward = NULL;

    head = reverse(head ,3);
    Traversal(head);
    
    return 0;
}