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

    // TreeNode(int val,vector<TreeNode*>child)
    // {
    //     this->val = val;
    //     this->children = child;
    // }

    void LevelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            if(q.front() == NULL)
            {
                q.pop();
                cout << endl;

                // if(!q.empty())
                // q.push(NULL);
            }
            else{
                TreeNode* temp = q.front();
                cout<<temp->val << " ";
                q.pop();

                for(auto i : temp->children)
                q.push(i);

                q.push(NULL);
            }
        }
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

    root->LevelOrderTraversal(root);
    return 0;
}