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

node *Create_Tree(node *root,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(root -> data > data)
        Create_Tree(root->left,data);

    else
    Create_Tree(root->right,data);

    return root;
}

void Input(node* &root)
{
    int data;
    cout<<"Enter the data for insertion: "<<endl;
    cin>>data;

    while(data != -1)
    {
        
        root = Create_Tree(root,data);
        cout<<"Enter the next data for insertion: "<<endl;
        cin>>data;
    }
}

int Find_Smallest(node *root)
{
    if(root -> left == NULL || root == NULL)//if there is no left child then return -1 or can return root -> data
    return -1;

    while(root -> left)
    root = root ->left;
    
    return root ->data;
}

int Find_Greatest(node *root)
{
    if(root -> right == NULL || root == NULL)//if there is no left child then return -1 or can return root -> data
    return -1;

    while(root -> right)
    root = root ->right;
    
    return root ->data;
}

int main()
{
    node *root = NULL;
    Input(root);



    return 0;
}