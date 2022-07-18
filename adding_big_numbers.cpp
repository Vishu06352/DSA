#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int> add(vector<int>s1 , vector<int>s2)
{
    vector<int>ans;
    
    int length = min(s1.size() , s2.size());
    int carry = 0;
    reverse(s1.begin() , s1.end() );
    reverse(s2.begin() , s2.end() );
    
    for(int i = 0 ; i < length ; i++) // carry ko value ka quitent dena h aur push_back karna h value ka remaninder
    {
        int value = s1[i] + s2[i] + carry;
        carry = value / 10;
        ans.push_back(value%10);
    }
    
    if(length < s1.size())
    {
        for(int i = length ; i < s1.size() ; i++)
        {
            int value = s1[i] + carry;
            carry = value / 10;
            ans.push_back(value%10);
        }
    }
    
    if(length < s2.size())
    {
        for(int i = length ; i < s2.size() ; i++)
        {
            int value = s2[i] + carry;
            carry = value / 10;
            ans.push_back(value%10);
        }
    }
    
    while(carry)
    {
        ans.push_back(carry%10);
        carry /= 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string str1 = "12345" ,str2 = "12345";
    
    vector<int>s1,s2;
    
    for(int i = 0 ;i < str1.length() ; i++)
    {
        s1.push_back(str1[i] - '0');
    }
    for(int i = 0 ;i < str2.length() ; i++)
    {
        s2.push_back(str2[i] - '0');
    }
    
    vector<int>ans;
    ans = add(s1,s2);
    
    for (int i : ans) {
        cout<<i;
    }
    return 0;
}
