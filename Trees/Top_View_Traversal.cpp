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
    node *left, *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void Level_Order_Traversal_optimise(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            node *temp = q.front();
            cout << temp->data << " ";
            q.pop();

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
    cout << endl;
}

node *BuildTree(node *root)
{
    cout << " Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    root = new node(data);

    cout << "Enter the data for left insertion of: " << data << endl;
    root->left = BuildTree(root->left);

    cout << "Enter the data for right insertion of: " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}

void Left_Node_View(node *root ,vector<int>&ans)
{
    if(root == NULL)
        return;

    Left_Node_View(root -> left,ans);
    ans.push_back(root->data);
}

void right_Node_View(node *root,vector<int>&ans)
{
    if(root == NULL)
        return;

    ans.push_back(root->data);
    right_Node_View(root -> right,ans);
}

int main()
{
    // string 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4-1 7 -1 9 10 -1 -1 11 -1 -1

    node *root = NULL;
    root = BuildTree(root);

    vector<int>ans;
    Left_Node_View(root->left,ans);
    ans.push_back(root -> data);
    right_Node_View(root->right,ans);

    for(auto i : ans)
    {
        cout << i <<" ";
    }
    return 0;
}