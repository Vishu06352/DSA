#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // yeh constructor bana pade ga taki head ya first node intiallize kar paye aur baad me new nodes bhi create kar paye
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void Traversal(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertion_at_end(Node *&head, Node *&tail, int d)
{

    if (tail == NULL)
    {
        Node *NN = new Node(d);
        head = NN;
        tail = NN;
    }
    else
    {
        Node *NN = new Node(d);
        tail->next = NN;
        tail = NN;
    }
}

bool detechLoop(Node *head)
{
    map<Node*,bool>visited;
    Node *temp = head;

    while(temp != NULL)
    {
        if(visited[temp] == true)
        {
            cout << "Loop is present at " << temp -> data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
    /*
        T.C = O(n)
        S.C = O(n)
    */
}

Node *floyd_cycle_begining(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    if (head == NULL || head -> next == NULL)
    return NULL;

    while(fast != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;
        if(fast != NULL)
        fast = fast -> next;

        if(fast == slow)
        {
            break;
            // return slow;
            // or we can return fast as well
        }
    }
    if(fast != slow)
    return NULL;

    slow = head;

    while(slow != fast)
    {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}
Node *floydDetect(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    if (head == NULL || head -> next == NULL)
    return NULL;

    while(fast != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;
        if(fast != NULL)
        fast = fast -> next;

        if(fast == slow)
        {
            return slow;
            // or we can return fast as well
        }
    }
    return NULL;
}

void delete_cycle(Node *&head)
{
    Node *current = head;

    while(current ->next != head)
    {
        current = current -> next;
    }
    current -> next = NULL;
}
int main()
{
    Node *head = NULL;
    Node *tail = head;

    insertion_at_end(head, tail, 1);
    insertion_at_end(head, tail, 2);
    insertion_at_end(head, tail, 3);
    insertion_at_end(head, tail, 4);
    insertion_at_end(head, tail, 5);
    insertion_at_end(head, tail, 6);
    insertion_at_end(head, tail, 7);

    tail -> next = head -> next -> next;

    // if(detechLoop(head)) 
    // cout << "Loop is present " << endl;

    // else
    // cout << "Loop is not present " << endl;

    //-------------------------------Flyod's Loop Detection-----------------------------------

    if(floydDetect(head)) 
    cout << "Loop is present " << endl;

    else
    cout << "Loop is not present " << endl;

    //------------------------------flyod detecting begining of cycle---------------------------

    Node *temp = floyd_cycle_begining(head);
    if(temp != NULL)
    cout << "Begining of cycle " << temp -> data << endl;

    // ---------------------------------using flyod begining of cycle we will make a cycle list into a regular list

    Node *head2 = floyd_cycle_begining(head);

    delete_cycle(head2);

    if(floydDetect(head)) 
    cout << "Loop is present " << endl;

    else
    cout << "Loop is not present " << endl;

    return 0;
}