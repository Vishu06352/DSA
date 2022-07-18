#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void add(vector<int>str1,vector<int>str2)
{
    vector<int>ans;

    int length = min(str1.size() , str2.size());
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());

    int carry = 0;

    for(int i = 0 ; i  < length ; i++)
    {
        int value  = str1[i] + str2[i] + carry;
        carry = value /10;
        ans.push_back(value % 10);
    }

    while(length < str1.size())
    {
        int value = carry + str1[length++];
        carry = value /10;
        ans.push_back(value % 10);
    }
    while(length < str2.size())
    {
        int value = carry + str2[length++];
        carry = value /10;
        ans.push_back(value % 10);
    }
    while(carry)
    {
        ans.push_back(carry % 10);
        carry /=10;
    }
    reverse(ans.begin(),ans.end());
    for(int i : ans)
    {
        cout << i;
    }
}


int main()
{
    string s1 = "12345", s2 = "123456";
    vector<int>str1,str2;

    for(int i = 0 ; i  < s1.length() ; i++)
    {
        str1.push_back(s1[i]-'0');
    }

    for(int i = 0 ; i  < s2.length() ; i++)
    {
        str2.push_back(s2[i]-'0');
    }

    add(str1,str2);

    return 0;
}