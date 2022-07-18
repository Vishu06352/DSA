#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

 void minRemoveToMakeValid(string &s) {
        stack<char>st;

        int i = 0 , cnt = 0;
        
        while(i < s.length())
        {
            if(s[i] == '(')    
            {
                st.push(s[i]);
                cout << "1" << endl;
                i++;
            }
            else if(!st.empty() && s[i] == ')')
            {
                st.pop();
                cout << "2" << endl;
                i++;
            }
            else if(st.empty() && s[i] == ')')
            {
                s.erase(s.begin()+i,s.begin()+i+1);
                cout << "3" << endl;
                i++;
                i = 0;
            }
            else
            {
                i++;
            }
            
        }
        while(!st.empty())
        {
            int index = s.find(')');
            s.erase(s.begin()+index,s.begin()+index+1);
            cout << "4" << endl;
            st.pop();
        }
    }

int main()
{
    // string s = "lee(t(c)o)de)";
    string s = "))aba) ((";
    minRemoveToMakeValid(s);

    cout << s;
    
    return 0;
}