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

 Node* merge(Node* &head1 , Node* &head2)
 {
     Node* ans = NULL;
     Node* tail = ans;
     Node* temp1 = head1;
     Node* temp2 = head2;

     while(temp1 != NULL && temp2 != NULL)
     {
         if(temp1 -> data < temp2 -> data)
         {
             tail -> next = temp1;
             tail = temp1;
             temp1 = temp1 -> next;
         }
         else{
         cout << "while 1";
            tail -> next = temp2;
            tail = temp2;
            temp2 = temp2 -> next;
         }
     }

     while(temp1 != NULL)
     {
        cout << "while 2";
        tail -> next = temp1;
        tail = temp1;
        temp1 = temp1 -> next;
     }

     while(temp2 != NULL)
     {
         cout << "while 3";
        tail -> next = temp2;
        tail = temp2;
        temp2 = temp2 -> next;
     }
     tail -> next = NULL;
     ans = ans -> next;
     return ans;
}
int main()
{
    // edge cases
    // if (head1 == NULL)
    // return head2;

    // if(head2 == NULL)
    // return head1;
    
    Node *List1 = NULL;
    insertion_at_end(List1,1);
    insertion_at_end(List1,2);
    insertion_at_end(List1,5);
    insertion_at_end(List1,5);
    insertion_at_end(List1,7);

    Node *List2 = NULL;
    insertion_at_end(List2,1);
    insertion_at_end(List2,3);
    insertion_at_end(List2,6);
    insertion_at_end(List2,8);
    
    Node* mergeHead = merge(List1,List2);
    Traversal(mergeHead);

    return 0;
}