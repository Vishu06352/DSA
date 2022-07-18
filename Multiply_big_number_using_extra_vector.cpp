#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;

void big_sum(vector<int>&v1,vector<int>&v2)
{
   
    int i = 0 , j =0 , carry =0;
    vector<int>ans;
    
    while(i < v1.size() && j < v2.size())
    {
        int val = carry + v1[i] + v2[j];
        carry = val /10;
        
        ans.push_back(val%10);
        i++,j++;
    }
    
    while(i < v1.size())
    {
        int val = carry + v1[i];
        carry = val /10;
        i++;
        ans.push_back(val%10);
    }
    
    while(j < v2.size())
    {
        int val = carry + v2[j];
        carry = val/10;
        j++;
        ans.push_back(val%10);
    }
    
    while(carry)
    {
        ans.push_back(carry%10);
        carry /= 10;
    }
    
    v1 = ans;
}
void multiply(vector<int>v1,vector<int>v2)
{
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    
    vector<int>ans;
    
    int push_zero = 0;
    for(int j = 0 ; j < v2.size() ; j++)
    {
        int carry = 0;
        push_zero = j;
        vector<int>output;
        while(push_zero--)
        {
            output.push_back(0);
        }
        
        for(int i = 0 ; i < v1.size() ; i++)
        {
                int val = v1[i] *v2[j] + carry;
                carry = val/10;
                output.push_back(val%10);
        }
        while(carry)
        {
            output.push_back(carry%10);
            carry /=10;
        }
        big_sum(ans,output);
    }
    reverse(ans.begin(),ans.end());
    for (auto i : ans) {
        cout << i ;
    }
}
int main()
{
    string s1 = "625";
    string s2 = "1";
    
    vector<int>v1,v2;
    
    for(int i = 0 ; i < s1.length() ; i++)
    {
        v1.push_back(s1[i] - '0');
    }
    
    for(int i = 0 ; i < s2.length() ; i++)
    {
        v2.push_back(s2[i] - '0');
    }

    multiply(v1,v2);
    
    return 0;
}
