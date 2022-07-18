#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

bool check(char ch1 , char ch2)
{
    if((ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']') || (ch1 == '(' && ch2 == ')') )
    return true;

    return false;
}

bool valid(string str)
{
    stack<char>st;
    int i = 0;
    
    if(str.length()&1) // handling odd case
    return false;


    while(i != str.length())
    {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(' )
        {
            st.push(str[i++]);
        }

        else
        {
            if(!st.empty())
            {
                if(check(st.top(),str[i]))
                {
                    st.pop();
                    i++;
                }
                else // if parenthesis does not match
                return false;
            }
           else
           return false;
        }
    }
    if(!st.empty())
    return false;

    return true;
}

int main()
{
    string str = "{}}}}";

    if(valid(str))
    cout << " Valid parenthesis" << endl;
    
    else
    cout << " Not Valid parenthesis" << endl;
    
    return 0;
}