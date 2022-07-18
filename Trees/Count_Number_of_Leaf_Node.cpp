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
    node *left;
    node *right;

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
    cout << "Enter the data: " << endl;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the Data to be inserted at left of " << root->data << endl;
    root -> left = BuildTree(root->left);

    cout << "Enter the Data to be inserted at right of " << root->data << endl;
    root -> right = BuildTree(root->right);

    return root;
}

void Cnt_Leaf(node *root, int &cnt)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cnt++;
        cout << "aaya for " << root->data << endl;
    }

    Cnt_Leaf(root->left, cnt);
    Cnt_Leaf(root->right, cnt);
}

int main()
{
    // string: 1 3 7 -1 -1 4 -1 -1 5 17 -1 -1 -1
    //  string 2(complex tree testing): 1 2 4 8 13 -1 -1 14 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 12 15 -1 -1 16 -1 -1 7 -1 -1
    node *root = NULL;
    root = BuildTree(root);

    int cnt = 0;
    Cnt_Leaf(root,cnt);
    cout <<"Number of leaf node is -> " << cnt << endl;
    return 0;
}