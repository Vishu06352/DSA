#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void add(vector<int> a1, vector<int> b1)
{
    string final_ans;
    vector<int> ans;

    reverse(a1.begin(), a1.end());
    reverse(b1.begin(), b1.end());

    int length = min(a1.size(), b1.size());
    int i = 0, carry = 0;
    while (i < length)
    {
        int value = a1[i] + b1[i] + carry;
        carry = value / 2;
        ans.push_back(value % 2);
        i++;
    }
 
    while (i < a1.size())
    {
        int value = a1[i] + carry;
        carry = value / 2;
        ans.push_back(value % 2);
        i++;
    }

    while (i < b1.size())
    {
        int value = b1[i] + carry;
        carry = value / 2;
        ans.push_back(value % 2);
        i++;
    }

    while (carry)
    {
        ans.push_back(carry % 2);
        carry /= 2;
    }
    reverse(ans.begin(), ans.end());

    for(int i =0 ; i < ans.size() ; i++ )
    {
        final_ans.push_back(ans[i] +'0');
    }
}

int main()
{
    string a = "10001";
    string b = "11101";

    vector<int> a1, b1;
    string ans;

    for (int i = 0; i < a.length(); i++)
    {
        a1.push_back(a[i] - '0');
    }

    for (int i = 0; i < b.length(); i++)
    {
        b1.push_back(b[i] - '0');
    }

    add(a1, b1);
    cout<<ans;
    return 0;
}