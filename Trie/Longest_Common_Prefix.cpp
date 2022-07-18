#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class TrieNodes
{
public:
    char data;
    TrieNodes *Children_Node[26];
    bool Terminal_Node;
    int child_cnt;

    TrieNodes(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
            Children_Node[i] = NULL;
        Terminal_Node = false;
        child_cnt = 0;
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
            root->child_cnt++;
        }

        insertionUtil(child, words.substr(1));
    }
    void insertion(string words)
    {
        insertionUtil(root, words);
    }

  
    void longestPrefix(string str,string &ans)
    {
        if(root->Terminal_Node)
        return;

        for(int i = 0 ; i < str.length() ; i ++)
        {
            if(root -> child_cnt == 1)
            {
                ans += str[i];
                int index = str[i] - 'a';

                root = root ->Children_Node[index];
            }
            else
            break;

            if(root->Terminal_Node)
            break;
        }
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
};

int main()
{
    Trie_Implementation *t = new Trie_Implementation();
    string ans;
    t->insertion("aba");
    t->insertion("ab");
    t->insertion("");
    // t->insertion("coders");

    // cout <<" string "" is present or not: "<<t->search("")<<endl;

    t->longestPrefix("ab",ans);

    if(ans.length() == 0)
    cout<<"There may be a blank string in the insertion"<<endl;

    else
    cout<<"Longest prefix is: "<<ans<<endl;
}

/*     RECURSIVE FUNCTION CALL
void commonPrefix(Trie *&root,string word,string &output)
    {
        if(word.length() == 0 || root->childcnt > 1 || root ->isTerminal) //doing root ->isTerminal for test case ("ab","a");
        return ;
        
        
        if(root->childcnt == 1)
        {
            int index = word[0]-'a';
            output.push_back(word[0]);
            commonPrefix(root->child[index],word.substr(1),output);
        }
            
        else //to handle the node with zero cnt
            return;
    }
    
    string prefix(string word)
    {
        string output = "";
        commonPrefix(root,word,output);
        
        if(output.length() == 0)
        return "BLANK";
        
        return output;
    }

    */