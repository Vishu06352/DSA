#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

bool isOperator(string ch)
{
    if(ch == "+" || ch == "-" || ch == "*" || ch == "/" )
    return true;

    return false;
}

int Evalute(string tokens)
{
    if(isOperator(tokens[0]))
    return -1;

    stack<int>st;
    int ans = 0;

    for(int i = 0 ; i < tokens.size(); i++)
    {
        if(isOperator(tokens[i]))
        {
            int x = st.top();
            st.pop();

            int y = st.top();
            st.pop();

            if(tokens[i] == "+")
                ans = x+y;

           else if(tokens[i] == "-")
                ans = y - x ; ///important

            else if(tokens[i] == "*")
                ans = x*y;

            else if(tokens[i] == "/") //important
                ans = y/x;

                st.push(ans);
        }
        else
            st.push(stoi(tokens[i]));
    }
        // do not return the ans because if we push only 18 into stack then it will given wrong output
    return st.top();
}

int main()
{
    string tokens;
    tokens = {"2","1","+","3","*"};
    cout << Evalute(tokens);


    return 0;
}