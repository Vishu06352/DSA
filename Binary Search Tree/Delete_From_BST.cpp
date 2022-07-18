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
        this -> data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createBST(node* root,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(root -> data > data)
    root -> left = createBST(root->left,data);

    if(root -> data < data)
    root -> right = createBST(root->right,data);

    return root;
}

void input(node *&root)
{
    int data;
    cout <<"Enter the data for insertion: "<<endl;
    cin>>data;

    while(data != -1)
    {
        root = createBST(root,data);
        cout <<"Enter the data for insertion: "<<endl;
        cin>>data;
    }
}

void level_order(node *root)
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

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
    }
}

node *find_mini_from_right(node *root)
{
    if(root -> left == NULL)// agar root ka right pass kiya hai to find minimum value from its left we have to check kahi left hi toh null nhi agar esa hai toh return root 
    return root;

    node *temp = root -> left;
    while(temp ->left)
        temp = temp ->left;

    return temp;    
}

node *find_max_from_right(node *root)
{
    if(root -> right == NULL)// agar root ka right pass kiya hai to find minimum value from its left we have to check kahi left hi toh null nhi agar esa hai toh return root 
    return root;

    node *temp = root;

    while(temp -> right)
    temp = temp->right;

    return temp;
}
node* delete_node(node *root,int data)
{
    if(root == NULL)
    return root;

    if(root ->data == data)
    {
        // 1st case. no child
        if(root -> left == NULL && root ->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 2nd case. only one child either left or right
        else if(root -> left != NULL && root -> right == NULL)
        {
            //save its below tree 1st and then delete it
            node *temp = root -> left;
            delete root;
            return temp;
        }
        else if(root -> left == NULL && root -> right != NULL)
        {
            //save its below tree 1st and then delete it
            node *temp = root -> right;
            delete root;
            return temp;
        }
        
        /*
        *   3rd case. have both left and the right child
        *   there is two ways to deal either find out the maximum value from it left or find out the minimum value from it right
        *   then store that value and copy it to the root value now we have 2 same values
        *   made a recursive call to delete the second value from it right or left(depends from where u find the value i.e you find from the left(maximum) or right(minimum))
       
        */
        else if(root ->left && root ->right)
        {
            // to find mini value from right ke left se
            // int mini = find_mini_from_right(root->right)->data;
            // root->data = mini; // copying the mini value to right node data
            // root -> right = delete_node(root->right,mini);
            // return root;

            //to find max value from left ke right se
            int maxi = find_max_from_right(root->left)->data;
            root->data = maxi; // copying the maxi value to left node data
            root->left = delete_node(root->left,maxi);
            return root;
        }

    }

    if(root -> data > data)
    root->left = delete_node(root->left,data);

    if(root -> data < data)
    root->right = delete_node(root->right,data);

    return root;
}
int main()
{
    // string 50 30 80 15 35 65 95 26 36 55 70 93 110 -1
    node *root = NULL;
    input(root);
    level_order(root);

    // deleting nodes
    cout <<endl;

    root = delete_node(root,80);
    level_order(root);
    return 0;
}