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

pair<int,int> find_diamter(node *root)
{
    if(root == NULL)
    {
        pair<int,int>p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = find_diamter(root -> left);
    pair<int,int> right = find_diamter(root -> right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second;

    pair<int,int>ans;
    
    ans.first = max(opt1,max(opt2,opt3));
    ans.second = max(left.second ,right.second)+1;

    return ans;
}
int main()
{
    node *root = NULL;
    root = Create_Tree(root);

    pair<int,int> diamter = find_diamter(root);

    cout <<"Max Diameter of the Tree is "<<diamter.first<<endl;

    return 0;
}