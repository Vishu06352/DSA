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

node *BuildTree(node *root)
{
    int data;
    cout <<" Enter the data: "<<endl;
    cin>>data;

    root = new node(data);

    if(data == -1)
    return NULL;

    cout<<"Enter the data for left insertion of "<<root->data<<endl;
    root -> left = BuildTree(root->left);

    cout<<"Enter the data for right insertion of "<<root->data<<endl;
    root -> right = BuildTree(root->right);

    return root;
}

void cnt_left_leaf(node* root,int &ans,int flag)
{
    if(root == NULL)
    return;

    if((root ->left == NULL && root ->right == NULL) && flag == 1)
    ans += root->data;

    cnt_left_leaf(root->left,ans,1);
    cnt_left_leaf(root->right,ans,0);

}

int main()
{
    // string: 1 3 7 -1 -1 4 -1 -1 5 17 -1 -1 -1
    //  string 2(complex tree testing): 1 2 4 8 13 -1 -1 14 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 12 15 -1 -1 16 -1 -1 7 -1 -1
    node *root = NULL;
    root = BuildTree(root);

    int ans = 0;
    cnt_left_leaf(root,ans,1);
    /* 
        ADD a base case in cnt_left_leaf function that if only root node is there with no children then return 0 (see leetcode)
    */
    cout<<"Sum of all left leaf node is -> " << ans << endl;

    return 0;
}