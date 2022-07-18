#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

bool isReduntant(string str)
{
    stack<char>st;
    int i = 0;
     while(i < str.length())
     {
        if(str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' )
            st.push(str[i]);

        else if(str[i] == ')')
        {
            bool Redundant = true;
            while(st.top() != '(')
            {
                char ch = st.top();
                if(ch == '+' || ch == '-' || ch == '*' || ch == '/' )
                {
                    Redundant = false;
                }
                st.pop();
            }
            if(Redundant)
            return true;

            st.pop();
        }
        i++;
     }
     return false;
}

int main()
{
    string str = "(a+(b+c))";

    if(isReduntant(str))
        cout << "String is Reduntant "<< endl;

    else
    cout << "String is not Reduntant " << endl;
    return 0;
}