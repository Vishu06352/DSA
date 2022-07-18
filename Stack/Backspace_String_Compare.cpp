#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

   bool check(char top,char str)
    {
        if(top == str)
            return true;
        
        return false;
    }

bool find(string s, string t)
{
    stack<char>st;
        int i = 0;
        string s1,s2;
        while (i < s.length())
        {

        if(!st.empty() && s[i] == '#')
            st.pop();

        else if(s[i] != '#')
            st.push(s[i]);

        i++;
      }
        while (!st.empty())
        {
        s1.push_back(st.top());
        st.pop();
        }
        
        i = 0;
        while (i < t.length())
        {
    
        if(!st.empty() && t[i] == '#')
        st.pop();

        else if(t[i] != '#')
        st.push(t[i]);

        i++;
        }
        
        while (!st.empty())
        {
        s2.push_back(st.top());
        st.pop();
        }
        
        if (s1.length() != s2.length())
        return false;

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            return false;
    }

    return true;
}

int main()
{
    string s = "##abc", t = "#abc";

    if (find(s, t))
        cout << "Equal";

    else
        cout << " Not Equal";

    return 0;
}