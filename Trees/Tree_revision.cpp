#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;

    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node *BuildTree(node *root)
{
    int data;
    cout <<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1)
    return NULL;

    root = new node(data);
    
    cout <<"Enter the data for left insertion of "<<data<<endl;
    root -> left = BuildTree(root -> left);

    cout <<"Enter the data for right insertion of "<<data<<endl;
    root -> right = BuildTree(root -> right);

    return root;
}
void Level_order(node *root)
{
    queue<node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << temp ->data <<" ";

        if(temp -> left)
        q.push(temp->left);

        if(temp -> right)
        q.push(temp->right);
        
    }
}

void Level_order_Modified(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        if(q.front() == NULL)
        {
            cout<<endl;
            q.pop();

            if(!q.empty())
            q.push(NULL);
        }
        else{
        node *temp = q.front();
        q.pop();

        cout << temp ->data <<" ";

        if(temp -> left)
        q.push(temp->left);

        if(temp -> right)
        q.push(temp->right);
    }
    }   
}

node *BuildTree_LevelOrder(node *root)
{
    int data;
    cout << "Enter the data for root node: "<<endl;
    cin>>data;

    if(data == -1)
    return;

    root = new node(data);
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        int data1;
        cout<<"Enter the left insertion of "<<temp->data;
        cin>>data1;

        if(data1 != -1){
        temp -> left = new node(data1);
        q.push(temp->left);
        }

         int data2;
        cout<<"Enter the left insertion of "<<temp->data;
        cin>>data2;

        if(data2 != -1){
        temp -> right = new node(data2);
        q.push(temp->right);
        }
    }    
}
int main()
{
    node *root = NULL;
    root = BuildTree(root);
    Level_order(root);cout<<endl;
    Level_order_Modified(root);
    //string 1 3 7 -1 -1 4 -1 -1 5 17 -1 -1 -1
    // string 2(complex tree testing) 1 2 4 8 13 -1 -1 14 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 12 15 -1 -1 16 -1 -1 7 -1 -1
    return 0;
}