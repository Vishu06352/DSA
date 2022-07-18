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

void level_order_Traversal(node *root)
{
    if(root == NULL)
    return;
    
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(! q.empty())
    {
        if(q.front() == NULL)
        {
            cout << endl;
            q.pop(); // to remove null
            
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        
        else
        {
            node *temp = q.front();
            cout << temp ->data <<" ";
            q.pop();
            
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            q.push(temp->right);
            
        }
    }
}

node *Create_Tree(node *root)
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    
    if(data == -1)
    return NULL;
    
    root = new node(data);
    
    cout<<"Enter the data for left insertion of "<< data<<endl;
    root ->left = Create_Tree(root->left);
    
    cout<<"Enter the data for right insertion of "<< data<<endl;
    root ->right = Create_Tree(root->right);
    
    return root;
}void reverse_Level_Order_Traversal(node *root)
{
    if(root == NULL)
    return ;
    
    queue<node*>q;
    stack<node*>st;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        if(q.front() == NULL)
        {
            st.push(NULL);
            q.pop();
            
            if(!q.empty())
            q.push(NULL);
        }
        
        else{
            node *temp = q.front();
            q.pop();
            
            st.push(temp);
            
            if(temp ->right)
            q.push(temp->right);
            
            if(temp ->left)
            q.push(temp->left);
        }
    }
    
    while(!st.empty())
    {
        if(st.top() == NULL) {
        cout <<endl;
        st.pop();
        }
        
        else
        {
            node *temp = st.top();
            st.pop();
            cout << temp ->data <<" ";
        }
        
    }
    
}

int main()
{
    node *root = NULL;
    //string 80 70 60 -1 -1 -1 100 90 -1 -1 120 -1 -1
    root = Create_Tree(root);
    cout << endl <<"Level order Traversal "<<endl;
    level_order_Traversal(root);
    
    cout<<endl<<"Reverse Level Order Traversal" << endl;
    reverse_Level_Order_Traversal(root);
    return 0;

    /*
        1. In reverse level order we use queue and stack 
        2. purpose of stack is to reverse the nodes 
        3. in level order traversal instead of printing the data we store the nodes in the stack
        4. also in reverse level order traversal we mae right call first then left call otherwise answer or outcome will be wrong
    */
}