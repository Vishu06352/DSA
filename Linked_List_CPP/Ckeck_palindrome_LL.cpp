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

void insert_at_tail(Node *&head,Node *&tail,int data)
{
    if(tail == NULL)
    {
        Node * NN = new Node(data);
        tail = NN;
        head = NN;
    }
    else{
        Node * NN = new Node(data);
        tail ->next = NN;
        tail = NN;
    }
}

Node* middle(Node* &head)
{
    Node *slow = head;
    Node *fast = head -> next;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow ->next;
    }
    return slow;
    
}

void reverse(Node *&head)
{
    Node *prev = NULL;
    Node *current  = head -> next;
    while(current != NULL)
    {
        Node *temp = current -> next;
        current -> next = prev;
        prev = current;
        current = temp;
    }
    head -> next = prev;
}

bool check(Node *&head , Node *&head2)
{
    Node *head1 = head;

    while(head2 != NULL)
    {
        if(head1 -> data != head2 -> data)
        return false;

        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    Node* tail = head;

   insert_at_tail(head,tail,1);
   insert_at_tail(head,tail,2);
//    insert_at_tail(head,tail,2);
//    insert_at_tail(head,tail,2);
//    insert_at_tail(head,tail,1);

    //finding the middle
    Node *Middle = middle(head);

    // reversing the node after the middle node 
    reverse(Middle);
    Node *head2 = Middle -> next;

    if(check(head,head2))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    reverse(Middle);

    Traversal(head);
    return 0;
}