#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
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

void Traverse_left(node *root, vector<int> &ans)
{
    if (root == NULL) // this condition work when our intial root at first step is null
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    ans.push_back(root->data);

    if (root->left) // may be left node is present or not so first we check using if
        Traverse_left(root->left, ans);
    else
        Traverse_left(root->right, ans);
}

void Traverse_leaf(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    Traverse_leaf(root->left, ans);
    Traverse_leaf(root->right, ans);
}

void Traverse_right(node *root, vector<int> &ans)
{
    if (root == NULL) // this condition work when our intial root at first step is null
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right)
        Traverse_right(root->right, ans);
    else
        Traverse_right(root->left, ans);

    ans.push_back(root->data);
}

int main()
{
    node *root = NULL;
    // string 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4-1 7 -1 9 10 -1 -1 11 -1 -1
    root = BuildTree(root);
    // Level_Order_Traversal_optimise(root);

    vector<int> ans;
    ans.push_back(root->data);

    // if(root -> left == NULL && root -> right == NULL) // base condition in online platforms if we are given a single node with 1 as it data then 
    // it will be printed 2 time first my manual pushing into ans vector second by leaf node function so this case is impp
    // return ans;


    Traverse_left(root->left, ans);
    Traverse_leaf(root, ans);
    Traverse_right(root->right, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}