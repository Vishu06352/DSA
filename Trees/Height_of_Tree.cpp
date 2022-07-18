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
        this->left = this->right = NULL;
    }
};

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

int height_of_Tree(node *root)
{
    //ans here is height
    if(root == NULL)
    return 0;

    int left = height_of_Tree(root ->left);
    int right = height_of_Tree(root->right);

    int ans = max(left,right)+1;

    return ans;
}
int main()
{
    node *root = NULL;
    root =  Create_Tree(root);

    int height = height_of_Tree(root);

    cout <<"Max Height of the Tree is: "<< height<< endl;
    return 0;
}