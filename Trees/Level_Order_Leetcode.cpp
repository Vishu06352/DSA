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

vector<vector<int>> Level_order(node *root)
{
    vector<vector<int>>ans;
    vector<int>output;
    queue<node *>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        if(q.front() == NULL)
        {
            ans.push_back(output);
            output.clear();
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            node *temp = q.front();
            output.push_back(temp->data);
            q.pop();

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
    }
    return ans;
}  

int main()
{
    // string: 1 3 7 -1 -1 4 -1 -1 5 17 -1 -1 -1
    //  string 2(complex tree testing): 1 2 4 8 13 -1 -1 14 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 12 15 -1 -1 16 -1 -1 7 -1 -1

    node *root = NULL;
    root = BuildTree(root);

    vector<vector<int>>ans;

    ans = Level_order(root);
    
    int n = ans.size();

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j <ans[i].size() ; i++)
        {
            cout << ans[i][j] <<" ";
        }cout<<endl;
    }
    return 0;
}