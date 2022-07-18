#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int find_shift(string s)
{
    stack<int>st;
    int open = 0 ,close = 0;
    int i = 0;

    if(s.length()&1)
    return -1;

    while(i < s.length())
    {
        if(s[i] == '{')
        {
            st.push(s[i]);
        }

        else{
            if(!st.empty() && s[i] == '}' ) //ya toh balance part hoga varna direct push kardena
                st.pop();

                else
                st.push(s[i]);
        }
        i++;
    }

    while(!st.empty())
    {
        if(st.top() == '{')
            open++;

        else
        close++;

        st.pop();
    }

    return (open+1)/2 + (close+1)/2;

}
int main()
{   
    // case 1 -> {{{{
    // case 2 -> {{{}}
    // case 3 -> }}}}}
    string str = "}}}{{{";
    cout << "Minimum number of shifting -> " << find_shift(str);
    return 0;
}