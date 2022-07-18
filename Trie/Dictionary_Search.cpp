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

    void getSuggestion(TrieNodes *curr, string prefix, vector<string> &temp)
    {
        if (curr->Terminal_Node)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int index = ch - 'a';
            TrieNodes *next = curr->Children_Node[index];

            if (next != NULL)
            {
                prefix.push_back(ch);
                getSuggestion(next, prefix, temp);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getContacts(string s)
    {
        vector<vector<string>> output;
        string prefix = "";
        TrieNodes *prev = root;

        for (int i = 0; i < s.length(); i++)
        {
            char lastch = s[i];

            int index = lastch - 'a';
            prefix.push_back(lastch);

            TrieNodes *curr = prev->Children_Node[index];
     vector<string> temp;
          if(curr == NULL)
            {
                temp.push_back("0") ;
                output.push_back(temp);
                temp.clear();
            }
        else{
            getSuggestion(curr, prefix, temp);
            output.push_back(temp);
            prev = curr;
            temp.clear();
        }
        }

        return output;
    }
};

int main()
{
    string s[10] = {"joneffenbl", "jonggkcg" ,"jonajlkiame", "jonkicmdoeoeb" ,"joniogloekjgbjo" ,"jonnjlfoamj" ,"jongndgcckehkk" ,"jonhjj" ,"jonlikfhgkicb" ,"jonjfjcmog"};

    Trie_Implementation *t = new Trie_Implementation();

    for(int i = 0 ; i < 10 ; i ++)
    {
        t->insertion(s[i]);
    }


    vector<vector<string>>ans = t->getContacts("geeips");

    for(int i = 0 ; i < ans.size() ; i++)
    {
        for(int j = 0 ;  j < ans[0].size() ; j++)
        cout<<ans[i][j]<<" ";

        cout<<endl;
    }
}