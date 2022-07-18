#include <iostream>
#include<algorithm>
using namespace std;

bool check(char ch , string &s2)
{
    if(ch == ']' && s2[s2.length()-1] == '[')
    return true;
    
    else if(ch == ')' && s2[s2.length()-1] == '(')
    return true;
    
    else if(ch == '}' && s2[s2.length()-1] == '{')
    return true;
    
    else{
    return false;
    }
}

bool check_parent(string s1,string s2)
{
    
    int i = 0 ;
    
    while(i < s1.length())
    {
        
        if(s1[i] == '[' || s1[i] == '{' || s1[i] == '(')
        {
            s2.push_back(s1[i]);
        }
        else if(s1[i] == ']' || s1[i] == '}' || s1[i] == ')')
        {
            if(s2.length() == 0)
            {
                return false;
                break;
            }
            else
            {
                char ch = s1[i];
                // cout<<ch<<" ";
                if(check(ch,s2))
                {
                    s2.pop_back();
                }
                else{
                return false;
                break;
                }
            }
        }
        i++;
    }
    
    if(s2.length() == 0)
    return true;
    
    return false;
}

int main()
{
    string s1 = "[]]";
    string s2 ="";
    
    if(check_parent(s1,s2))
    {
        cout<<"Valid";
    }
    else
    cout<<"Not valid";

    return 0;
}
