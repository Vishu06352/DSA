#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class TrieNodes
{
public:
    char data;
    TrieNodes *Children_Node[26];
    bool Terminal_Node;

    TrieNodes(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
            Children_Node[i] = NULL;
        Terminal_Node = false;
    }
};

class Trie_Implementation
{
public:
    TrieNodes *root;

    Trie_Implementation()
    {
        root = new TrieNodes('\0');
    }

    void insertionUtil(TrieNodes *&root, string words)
    {
        // Base Case
        if (words.length() == 0)
        {
            root->Terminal_Node = true;
            return;
        }

        TrieNodes *child;

        int index = words[0] - 'a';

        if (root->Children_Node[index] != NULL)
        {
            // Node is Present
            child = root->Children_Node[index];
        }
        else
        {
            // Node is absent
            child = new TrieNodes(words[0]);
            root->Children_Node[index] = child;
        }

        insertionUtil(child, words.substr(1));
    }
    void insertion(string words)
    {
        insertionUtil(root, words);
    }

    bool searchUtil(TrieNodes *root, string words)
    {
        // Base Case  if the end of the root is not Terminal node then it will return false else true
        if (words.length() == 0)
            return root->Terminal_Node;

        TrieNodes *child;
        int index = words[0] - 'a';

        if (root->Children_Node[index] != NULL)
            child = root->Children_Node[index];

        else
            return false;

        return searchUtil(child, words.substr(1));
    }

    bool search(string words)
    {
        return searchUtil(root, words);
    }

    void deletionUtil(TrieNodes *&root, string words)
    {
        if (words.length() == 0)
        {
            root -> Terminal_Node = false;
            return;
        }

        TrieNodes *child;
        int index = words[0] - 'a';

        if (root->Children_Node[index] != NULL)
        {
            child = root->Children_Node[index];
        }
        else
        {
            cout << "The word Does not exist in the Trie" << endl;
            return;
        }
        // recursive call
        deletionUtil(child, words.substr(1));
    }
    void deletion(string words)
    {
        deletionUtil(root, words);
    }
};

int main()
{
    Trie_Implementation *t = new Trie_Implementation();

    t->insertion("a");
    // t->insertion("");

    cout<<"Present or not " << t->search("")<<endl;

    // t->deletion("arnold");

    // cout << "Present or not " << t->search("arm") << endl;
    // cout << "Present or not " << t->search("armholder") << endl;
    // cout << "Present or not " << t->search("armine") << endl;
    // cout << "Present or not " << t->search("arnold") << endl;

    return 0;
}