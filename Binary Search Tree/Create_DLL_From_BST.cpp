#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class node
{
    public:
    int data;
    node *left,*right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *Create_BST(node *root,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(root -> data > data)
    root -> left = Create_BST(root -> left,data);

    else
    root -> right = Create_BST(root->right,data);

    return root;
}

void Input_BST(node *&root)
{
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    while(data != -1)
    {
        root = Create_BST(root,data);
        cout<<"Enter the data for insertion: "<<endl;
        cin>>data;
    }
}


void Sorted_DLL(node *root,node*&dummy_pointer)
{
    if(root == NULL)
        return;
    
    Sorted_DLL(root->left,dummy_pointer); // left call
        
    dummy_pointer ->right = root;
    root->left = dummy_pointer;
    dummy_pointer = root;
    Sorted_DLL(root -> right , dummy_pointer); // right call
}

int main()
{
    //string 50 40 60 30 45 55 70 80 -1
    node *root = NULL;
    Input_BST(root);

    node* head1 = new node(-1);
    node* dummy_pointer = head1;

    Sorted_DLL(root,dummy_pointer);
    head1 = head1 -> right;
    head1 ->left = NULL;
    
    node *temp = head1;
    while(temp != NULL)
    {
        cout<<temp->data << " ";
        temp = temp->right;
    }cout<<endl;
    return 0;
}