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
    node *left , *right;

    node(int data)
    {
        this->data = data;
        this ->left = this->right = NULL;
    }
};

void inorder_Traversal(node *root)
{
    if(root == NULL)
    return;

    inorder_Traversal(root->left);
    cout << root -> data <<" ";
    inorder_Traversal(root->right);
}

node *Create_Tree(node *root)
{
    int data;
    cout<<"Enter the data for insertion: ";
    cin>>data;

    if(data == -1)
    return NULL;

    root = new node(data);

    cout<<"Enter the data for left insertion of "<<data<<endl;
    root -> left = Create_Tree(root ->left);
    cout<<"Enter the data for right insertion of "<<data<<endl;
    root -> right = Create_Tree(root ->right);

    return root;
}

void mirror_Tree_Create(node *root, node *&Mirror_root)
{
    if(root == NULL)
    {
        Mirror_root = NULL;
        return;
    }

    Mirror_root = new node(root->data);

    mirror_Tree_Create(root -> left,Mirror_root->right);
    mirror_Tree_Create(root->right,Mirror_root->left);
}
int main()
{
    //string 1 3 7 -1 -1 4 -1 -1 5 17 -1 -1 -1
    // string 2(complex tree testing) 1 2 4 8 13 -1 -1 14 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 12 15 -1 -1 16 -1 -1 7 -1 -1
    node *root = NULL;
    root = Create_Tree(root);
    
    node *Mirror_root = NULL;

    mirror_Tree_Create(root,Mirror_root);

    cout<<"Inorder of original Tree"<<endl;
    inorder_Traversal(root);
    cout<<endl;

    cout<<"Inorder of Mirror Tree"<<endl;
    inorder_Traversal(Mirror_root);
    cout<<endl;
    
    return 0;
}