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

    ~Node()
    {
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
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

 void copy_data(Node* &head , int zero_cnt, int one_cnt,int two_cnt)
 {
    Node *temp = head;

    while(zero_cnt--)
    temp -> data = 0 , temp = temp ->next;


    while(one_cnt--)
    temp -> data = 1 , temp = temp ->next;

    while(two_cnt--)
    temp -> data = 2 , temp = temp ->next;

 }

 void count(Node *&head)
 {
    Node *temp = head;
    int zero_cnt = 0;
    int one_cnt = 0;
    int two_cnt = 0;

    while(temp != NULL)
    {
        if(temp -> data == 0)
        zero_cnt++;

       else if(temp -> data == 1)
        one_cnt++;

        else
        two_cnt++;

        temp = temp -> next;
    }
    // cout << one_cnt << " " << zero_cnt <<" " << two_cnt;
    copy_data(head,zero_cnt,one_cnt,two_cnt);
 }

 void dummy_insert_tail(Node *&tail , Node *&temp)
 {
     tail -> next = temp;
     tail = temp;
 }

 void dummy_Node(Node *&head)
 {
     Node *zerohead = new Node(-1);
     Node *zerotail = zerohead;
 
     Node *onehead = new Node(-1);
     Node *onetail = onehead;

     Node *twohead = new Node(-1);
     Node *twotail = twohead;

    Node *temp = head;

    while(temp != NULL)
    {
        if(temp -> data == 0)
            dummy_insert_tail(zerotail,temp);

        else if(temp -> data == 1)
            dummy_insert_tail(onetail,temp);

        if(temp -> data == 2)
        {
            dummy_insert_tail(twotail,temp);
        }
        temp = temp -> next;
    }

    if(onehead -> next != NULL)
    zerotail -> next = onehead -> next;

    else
    zerotail -> next = twohead -> next;

    onetail -> next = twohead -> next;
    twotail -> next = NULL;
    head = zerohead -> next;

    zerohead -> next = NULL;
    onehead -> next = NULL;
    twohead -> next = NULL;
    
    delete zerohead;
    delete onehead;
    delete twohead;
 }

int main()
{
    Node *head = NULL;
    insertion_at_end(head,0);
    insertion_at_end(head,2);
    insertion_at_end(head,1);
    insertion_at_end(head,1);
    insertion_at_end(head,1);
    insertion_at_end(head,0);
    insertion_at_end(head,0);
    insertion_at_end(head,1);
    insertion_at_end(head,0);
    insertion_at_end(head,0);
    insertion_at_end(head,2);
    insertion_at_end(head,2);
    insertion_at_end(head,1);
    insertion_at_end(head,2);

    // Traversal(head);
    // count(head);
    // Traversal(head);

    dummy_Node(head);
    Traversal(head);

    return 0;
}