#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{

public:
    int val;
    Node *next;

    // yeh constructor bana pade ga taki head ya first node intiallize kar paye aur baad me new nodes bhi create kar paye
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }

    // deleting ke liye ek destructor lagana pade ga

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void Traversal(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_at_tail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)
    {
        Node *NN = new Node(d);
        tail = NN;
        head = NN;
    }

    else
    {
        Node *NN = new Node(d);
        tail->next = NN;
        tail = NN;
    }
}

Node *deleteDuplicates(Node *&head)
{
    int data = 2002;
    Node *current = head;
    Node *prev = NULL;

    if(head == NULL || head -> next ==NULL)
    return head;

    while (current != NULL) // if number is in begining
    {
        if ((current->next != NULL) && (current->val == current->next->val))
        {
            data = current->val;
            head = current->next->next;

            while (current != head)
            {
                Node *temp = current->next;
                current->next = NULL;
                delete current;
                current = temp;
            }
            current = head;
        }

        else if (current->val == data)
        {
            head = current->next;
            current->next = NULL;
            delete current;
            current = head;
        }
        else
            break;
    }

    if (head != NULL)
    {
        prev = current;
        current = head->next;
        while (current != NULL)
        {
            if (current->next != NULL && (current->val == current->next->val))
            {
                data = current->val;
                prev->next = current->next->next;
                while (current != prev->next)
                {
                    Node *temp = current->next;
                    current->next = NULL;
                    delete current;
                    current = temp;
                }
                current = prev->next;
            }
            else if (current->val == data)
            {
                prev->next = current->next;
                current->next = NULL;
                delete current;
                current = prev->next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    return head;
}

int main()
{
    Node *head = NULL;
    Node *tail = head;

    insert_at_tail(tail, head, 1);
    insert_at_tail(tail, head, 2);
    insert_at_tail(tail, head, 2);
    insert_at_tail(tail, head, 2);
    insert_at_tail(tail, head, 3);
    insert_at_tail(tail, head, 3);
    insert_at_tail(tail, head, 3);
    insert_at_tail(tail, head, 4);
    deleteDuplicates(head);
    Traversal(head);

    return 0;
}