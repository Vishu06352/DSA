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
    vector<TreeNode*>children;

    TreeNode()
    {}

    TreeNode(int val)
    {
        this->val = val;
    }

    void Preorder(TreeNode *root,vector<int>&ans)
    {
        if(root == NULL)
        return;

        for(auto i : root ->children)
        Preorder(i,ans);
        
        ans.push_back(root->val);
    }
};

int main()
{   
    TreeNode *root = new TreeNode(10);
    root->children.push_back(new TreeNode(20));
    root -> children.push_back(new TreeNode(30));
    root -> children.push_back(new TreeNode(40));    

    //children of 20
    root -> children[0]->children.push_back(new TreeNode(21));
    root -> children[0]-> children.push_back(new TreeNode(31));
    root -> children[0]-> children.push_back(new TreeNode(41));
    
    //children of 30
    root -> children[1]-> children.push_back(new TreeNode(100));
    root -> children[1]-> children.push_back(new TreeNode(200));
    root -> children[1]-> children.push_back(new TreeNode(300));

    vector<int>ans;
    root->Preorder(root,ans);

    for(auto i : ans)
    {
        cout << i <<" ";
    }
    return 0;
}