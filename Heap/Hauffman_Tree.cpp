#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left,*right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class cmp
{
    public:

    bool operator()(TreeNode* a,TreeNode *b){
        return a->val > b->val;
    }

};

void PreorderTraversal(TreeNode* root ,string output,vector<string> &ans)
{
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(output);
        return;
    }

    PreorderTraversal(root->left,output+'0',ans);
    PreorderTraversal(root->right,output+'1',ans);
}

vector<string> HuaffmanString(string str,vector<int>&freq)
{
    if(str.length() == 0)
        return {};

    vector<string>ans;
    string output;

    priority_queue<TreeNode*,vector<TreeNode*>,cmp >q;

    for(int i = 0 ; i < freq.size(); i++)
    {
        TreeNode *node = new TreeNode(freq[i]);
        q.push(node);
    }

    while(q.size() != 1)
    {
        TreeNode *temp1 = q.top();
        q.pop();

        TreeNode *temp2 = q.top();
        q.pop();

        TreeNode *root = new TreeNode(temp1->val + temp2->val);
        root -> left = temp1;
        root -> right = temp2;

        q.push(root);
    }

    TreeNode *root = q.top();

    PreorderTraversal(root,output,ans);
    return ans;
}

int main()
{
    string str = "abcdef";
    vector<int> freq = {5,9,12,13,16,45};

    vector<string> ans = HuaffmanString(str,freq);

    for(auto i : ans)
    {
        cout << i <<" ";
    }
    
    return 0;
}


/*
                        NOTES

    1-> When we travel in tree towards left add "0" on the edge 
    2-> When we travel in tree towards right add "1" on the edge
    3-> All the leaf node are character while non leaf node (with there frequency) contain the sum of the leaf nodes.

*/