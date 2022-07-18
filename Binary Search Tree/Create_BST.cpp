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

int main()
{
    node *root = NULL;
    Input_BST(root);
    return 0;
}