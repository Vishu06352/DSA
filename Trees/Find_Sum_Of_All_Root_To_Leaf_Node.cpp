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

 void find_sum(node *root ,int &sum,int &MaxSum)
    {
        if(root == NULL)
            return;
        if(root -> left == NULL && root ->right == NULL)
        {
            sum = sum*10 + root->data;
            MaxSum += sum;
            // cout <<"sum before inside if" << sum <<endl;
            sum /= 10;
            // cout <<"sum after inside if" << sum <<endl;
        }
        
        sum = sum *10 + root ->data;
        
        find_sum(root->left,sum,MaxSum);
        find_sum(root->right,sum,MaxSum);
        // cout <<"sum before outside if" << sum<<endl;
        sum /=10;
        // cout <<"sum before outside if" << sum<<endl;
    }

int main()
{
    //string1 ->  1 2 -1 -1 3 -1 -1
   //string 2 -> 4 9 5 -1 -1 1 -1 -1 0 -1 -1
    int sum = 0;
    int MaxSum =0;

    node *root = NULL;
    root = creation(root);
    
    find_sum(root,sum,MaxSum);
    cout << "\nSum from all root to leaf node is -> "<< MaxSum <<endl;
    return 0;
}