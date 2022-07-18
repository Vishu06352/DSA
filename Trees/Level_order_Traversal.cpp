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
    node *left;
    node *right;
    
    node(int data)
    {
        this->data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node *creation(node *root)
{
    int data;
    cout << "Enter the data: "<<endl;
    cin>>data;

    root = new node(data);

    if(data == -1)
    return NULL;

    cout << "Enter the data for left insertion of " << data << endl;
    root -> left = creation(root->left);

    cout << "Enter the data for right insertion of " << data << endl;
    root -> right = creation(root->right);

    return root;
}

void Level_Order_Traversal(node *root)
{
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node *temp = q.front();
        cout << temp -> data << " ";
        q.pop();

        if(temp -> right)
            q.push(temp -> right);

        if(temp -> left)
            q.push(temp -> left);
    }cout<<endl;
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
    root = creation(root);
    cout<<"Tree Created Succesfully "<< endl;
    cout<<endl;

    cout<<"Level order traversal" << endl;
    Level_Order_Traversal(root); // without enter approach
    cout<<endl;

    cout<<"Level order traversal with tree format" << endl;
    Level_Order_Traversal_optimise(root); // with enter approach
    cout<<endl;
    return 0;
}