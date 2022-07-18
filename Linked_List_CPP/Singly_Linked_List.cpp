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

    // deleting ke liye ek destructor lagana pade ga
    
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

void insertion_at_begining(Node *&head){

    Node *NN = new Node(20);
    
    NN->next = head;
    head = NN;

}

void insertion_at_end(Node *&head){

    Node *temp = head;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    Node *NN = new Node(30);

    temp -> next = NN;
}

void insertion_at_mid(Node *&head,int index)
{
    int cnt = 1;
    Node *temp = head;

    if(index == 1){
        insertion_at_begining(head);
        return ;
    }
    
    
    while(cnt != index-1)
    {
        temp = temp -> next;
        cnt++;
    }

    Node *NN = new Node(400);

    NN ->next = temp -> next; 
    temp -> next = NN;

}

void DeleteNode(Node *&head,int index)
{
    Node *previous = NULL;
    Node *current = head;
    if(index == 1)
    {
        head = head -> next;
        current -> next = NULL;
        delete current;
    }
    else
    {
        int cnt = 1;

        while(cnt < index)
        {
            previous = current;
            current  = current -> next;
            cnt ++;
        }

        previous -> next = current -> next;
        current -> next = NULL;

        delete current;
    }
}

int main()
{
    Node *head = new Node(10);
    int index;

    insertion_at_begining(head);
    Traversal(head);
    
    insertion_at_end(head);
    Traversal(head);

    cout << "Enter the index number -> ";
    cin >> index;
    insertion_at_mid(head,index);
    Traversal(head);

    DeleteNode(head,4);
    Traversal(head);

    /*                            insertion_at_mid 
       1-> insertion at mid ka code generic hai jo ki 1st last and mid position ka sambhal le ga
       2-> issme humne tail waali approach nhi use kari 
       3-> agar krni h toh video dkh liyo
     */

    /*                   DeleteNode
       1-> delete node function bhi generic hai
       2-> iss mei koi bhi node delete krne se phele ussa next NULL karna padega warna segmentation falut aa jaye ga aur galat value show karega
    */
    return 0;
}