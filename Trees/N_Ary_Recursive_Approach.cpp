#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int val;
    vector<TreeNode *> children;

    TreeNode()
    {
    }
    TreeNode(int val)
    {
        this->val = val;
    }
};

TreeNode *BuildTree(TreeNode *&root)
{
    int data;
    cout << "Enter the date for insertion: ";
    cin >> data;
    cout << endl;

    if (data == -1)
        return NULL;

    root = new TreeNode(data);

    for (int i = 0; i < 10; i++)
    {
        TreeNode *temp;
        cout <<"Enter the "<<i+1<<" child of "<<data<<endl;
        root->children.push_back(BuildTree(temp));

        int choice = 0;
        cout << "Do you want to insert more child of " << data << " (0,1): " << endl;
        cin >> choice;
        if (!choice)
        {
            break;
        }
    }

    return root;
}

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
    };

int main()
{
    TreeNode *root;
    root = BuildTree(root);
    LevelOrderTraversal(root);
    return 0;
}