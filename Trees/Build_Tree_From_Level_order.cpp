#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class node{
    public:
    node *left,*right;
    int data;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void BuildTree_Level_Order(node *&root)
{
    int data;
    cout <<"Enter the root node data: "<<endl;
    cin>>data;

    if(data == -1) // that is we don't want to create a tree
    return;

    root = new node(data);
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter the data for left insertion of " << temp ->data << endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1)
        {
            temp -> left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the data for right insertion of " << temp ->data <<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1)
        {
            temp -> right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void Level_Order_Traversal_optimise(node *root)
{
    queue<node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        if(q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if(!q.empty())
            q.push(NULL);
        }
        else{
            node * temp = q.front();
            cout << temp->data <<" ";

            if(temp -> left)
            q.push(temp->left);

            if(temp -> right)
            q.push(temp->right);
            q.pop();
        }
    }cout<<endl;
}

int main()
{
    node *root = NULL;
    //string 1 3 7 -1 -1 4 -1 -1 5 17 -1 -1 -1
    // string 2(complex tree testing) 1 2 4 8 13 -1 -1 14 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 12 15 -1 -1 16 -1 -1 7 -1 -1
    BuildTree_Level_Order(root);
    Level_Order_Traversal_optimise(root);
    return 0;
}