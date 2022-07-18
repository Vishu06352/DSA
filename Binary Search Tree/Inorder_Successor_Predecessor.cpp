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

node *Create_Tree(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    if (root->data > data)
        root->left = Create_Tree(root->left, data);

    else
        root->right = Create_Tree(root->right, data);

    return root;
}

void Input(node *&root)
{
    int data;
    cout << "Enter the data for insertion: " << endl;
    cin >> data;

    while (data != -1)
    {

        root = Create_Tree(root, data);
        cout << "Enter the next data for insertion: " << endl;
        cin >> data;
    }
}

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

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
            q.pop();
        }
    }
    cout << endl;
}

void Predecessor(node *root, int target, node *&predecessor)
{
    if (root == NULL)
        return;

    if (root->data == target)
    {
        if(root -> left)
        {
            predecessor = root->left;
            while(predecessor -> right)
            predecessor = predecessor -> right;

            return;
        }
    }

    if (root->data > target) // search in left part
        Predecessor(root->left, target, predecessor);

    else if (root->data < target) // search in right part
    {
        predecessor = root;
        Predecessor(root->right, target, predecessor);
    }
}

void Successor(node *root, int target, node *&successor)
{
    if (root == NULL)
        return;

    if (root->data == target)
    {
        if (root->right)
        {
            successor = root -> right;

            while(successor->left)
                successor = successor -> left;

            return;
        }
    }

    if (root->data > target) // search in left part
    {   
        successor = root; //important
        Successor(root->left, target, successor);
    }

    else if (root->data < target) // search in right part
        Successor(root->right, target, successor);
}

int main()
{
    // string 20 8 22 4 12 10 14 -1
    node *predecessor = NULL, *successor = NULL;
    node *root = NULL;
    Input(root);

    Level_Order_Traversal_optimise(root);
    Predecessor(root,20, predecessor);
    Successor(root, 20, successor);

    if (predecessor == NULL)
        cout << "No predecessor" << endl;
    else
        cout << "Predecessor: " << predecessor->data << endl;

    if(successor ==NULL)
    cout<<"No successor"<<endl;

    else
    cout <<"Successor: "<< successor->data <<endl;
}