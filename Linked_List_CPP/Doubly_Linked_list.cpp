#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
    public: 
    
    int data;
    Node *next , *prev;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node(){

        if(this -> next != NULL)
        {
            delete next;
            delete prev;
            this -> next = NULL;
            this -> prev = NULL;
        }
    }
};

void Traversal(Node *head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp ->next;
    }cout << endl;
}

void insert_at_start(Node *&head,Node *&tail, int data)
{
    if(head == NULL)
    {
        Node *NN = new Node(data);
        head = NN;
        tail = NN;
    }

    else{
    Node *NN = new Node(data);

    NN -> next = head;
    head ->prev = NN;
    head = NN;
    }
}

void insert_at_end(Node *&tail , int data)
{
    if(tail == NULL)
    {
        Node *NN = new Node(data);
        tail = NN;
    }

    else{
    Node *NN = new Node(data);

    NN -> prev = tail;
    tail ->next = NN;
    tail = NN;
    }
}

void insert_at_Position(Node *&tail , Node *&head , int index ,int d)
{
    if(index == 1)
    {
        insert_at_start(head,tail,d);
        return ;
    }
    else
    {
        Node *temp = head;
        int cnt = 1;

        while(cnt < index - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if(temp -> next == NULL)
        {
            insert_at_end(tail,d);
            return ;
        }

        Node *NN = new Node(d);
        NN -> next = temp -> next;
        temp -> next -> prev = NN;
        temp -> next = NN;
        NN -> prev = temp;

    }
}

void Delete_Position(Node *&head , Node *&tail , int index)
{

    if(index == 1)
    {
        Node *temp = head ;
        head = head -> next;
        temp -> next = NULL;
        head ->prev = NULL;

        delete temp;
        return ;
    }
    else{

        Node *temp = head;
        int cnt = 1;
        while(cnt < index )
        {
            temp = temp ->next;
            cnt++;
        }

        if(temp -> next == NULL)
        {
            tail = temp -> prev ;
            temp -> prev -> next = NULL;
            temp -> prev = NULL;
            delete temp ;
            return ;
        }

        temp -> next -> prev = temp -> prev ;
        temp -> prev -> next = temp -> next;
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }

}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insert_at_start(head,tail,(-10));
    Traversal(head);
    cout << "head is " << head -> data << " and tail is " << tail -> data << endl;

    insert_at_end(tail,20);
    Traversal(head);
    cout << "head is " << head -> data << " and tail is " << tail -> data << endl;

    insert_at_end(tail,30);
    Traversal(head);
    cout << "head is " << head -> data << " and tail is " << tail -> data << endl;

    insert_at_end(tail,40);
    Traversal(head);
    cout << "head is " << head -> data << " and tail is " << tail -> data << endl;


    insert_at_Position(tail,head,5,300);
    Traversal(head);
    cout << "head is " << head -> data << " and tail is " << tail -> data << endl;

    //--------------------------------------------------------Deleting Node code --------------------------------------------------------------//
   cout<< endl << "Deleting nodes " << endl << endl;

    Delete_Position(head,tail,1);
    Traversal(head);
    cout << "head is " << head -> data << " and tail is " << tail -> data << endl;
    
    Delete_Position(head,tail,4);
    Traversal(head);
    cout << "head is " << head -> data << " and tail is " << tail -> data << endl;
    
    Delete_Position(head,tail,2);
    Traversal(head);
    cout << "head is " << head -> data << " and tail is " << tail -> data << endl;
    
    /*Code toh perfect work kar rha h but kuch galti h next time shi karni hai

        1-> delete node function m current aur previous ka use kar ke delete krna tha just like singly linked list.
        2-> Baaki ig saab shi h aur ek baari last m babbar bhaiya waale code se check kar liyo.
    */
    return 0;
}
