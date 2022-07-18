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
void findMiddle(Node *&head)
{
    Node *fast = head -> next;
    Node *slow = head ;

    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    cout << slow -> data;
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
    insert_at_end(tail,head,6);
    Traversal(head);

    findMiddle(head);
    // cout << middle -> data;

    return 0;
}