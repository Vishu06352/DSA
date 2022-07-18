#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> diagonal(Node *root)
{
map<int,vector<int> > nodes;
    queue<pair<Node*,int > > q;
    vector<int>ans,output;
    
    pair<Node*,int > p = make_pair(root,0);
    q.push(p);
   
    while(!q.empty())
    {
        int size = q.size();
        
        for(int i = 0 ; i < size ; i++)
        {
            pair<Node*,int > temp = q.front();
            q.pop();
            
            Node *front = temp.first;
            int hd = temp.second;
            
            nodes[hd].push_back(front->data);
        
             if(front-> left){
               q.push(make_pair(front->left,hd-1));
            }
            if(front-> right){
                q.push(make_pair(front->right,hd));
            }
        }
    }
    
    int x = 0 , y = 0;
    for(auto i :nodes) // most important part
    {
        for(auto j :i.second)
        {
            ans.push_back(j);
            y++;
        }
       reverse(ans.begin()+x,ans.end());
       x = y;
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}


void BuildTree_Level_Order(Node *&root)
{
    int data;
    cout <<"Enter the root node data: "<<endl;
    cin>>data;

    if(data == -1) // that is we don't want to create a tree
    return;

    root = new Node(data);
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter the data for left insertion of " << temp ->data << endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1)
        {
            temp -> left = new Node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the data for right insertion of " << temp ->data <<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1)
        {
            temp -> right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

void Level_Order_Traversal_optimise(Node *root)
{
    queue<Node *>q;
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
            Node * temp = q.front();
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
    //string 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    // 12 11 12 7 1 12 14 11 -1 7 3 6 4 12 7 14 14 -1 2 10 8 7
    Node *root = NULL;
    BuildTree_Level_Order(root);
    
    // Level_Order_Traversal_optimise(root);

    vector<int>ans;
    ans = diagonal(root);

    for(auto i : ans)
    {
        cout << i <<" ";
    }
    return 0;
}