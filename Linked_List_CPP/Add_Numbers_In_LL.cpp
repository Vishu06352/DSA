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

void reverse(Node *&head,Node *prev , Node *current)
{
    if(current == NULL){
        head = prev;
    return;
    }

    reverse(head,current,current -> next);
    current -> next = prev;
}

Node* add(Node* &head1 , Node* &head2)
{
    Node *sum = NULL;
    Node *sum_tail = NULL;

    Node *head11 = head1;
    Node *head22 = head2;
    int carry = 0;
    while(head11 != NULL && head22 != NULL)
    {
        int val = head11 -> data + head22 -> data + carry;
        carry = val / 10;
        insert_at_tail(sum,sum_tail,val%10);
        head11 = head11 -> next;
        head22 = head22 -> next;
    }
    while (head11 != NULL)
    {
        int val = head11 -> data + carry;;
        carry = val /10;
        insert_at_tail(sum,sum_tail,val%10);
        head11 = head11 -> next;
    }
    while (head22 != NULL)
    {
        int val = head22 -> data + carry;;
        carry = val %10;
        insert_at_tail(sum,sum_tail,val%10);
        head22 = head22 -> next;
    }
    while (carry)
    {
       insert_at_tail(sum,sum_tail,carry%10);
       carry /=10;
    }
    reverse(sum,NULL,sum);
    return sum;
   
}

int main()
{
    Node *head1 = NULL;
    Node* tail1 = head1;

    Node *head2= NULL;
    Node* tail2 = head2;

    insert_at_tail(head1,tail1,2);
    insert_at_tail(head1,tail1,4);
    insert_at_tail(head1,tail1,3);
    // insert_at_tail(head1,tail1,4);

    insert_at_tail(head2,tail2,5);
    insert_at_tail(head2,tail2,6);
    insert_at_tail(head2,tail2,4);
    // insert_at_tail(head2,tail2,9);


    reverse(head1,NULL,head1);
    reverse(head2,NULL,head2);

    Node *sum = add(head1,head2);
    Traversal(sum);
    
    return 0;
}