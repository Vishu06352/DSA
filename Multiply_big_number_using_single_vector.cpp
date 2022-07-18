#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string find(string s1, string s2)
{
    if (s1 == "0" || s2 == "0")
        return "0";

    bool flag1 = false, flag2 = false;

    if (s1[0] == '-') // logic to handle (-) multiplication
        flag1 = true;

    if (s2[0] == '-')// logic to handle (-) multiplication
        flag2 = true;

    int len1 = s1.length(), len2 = s2.length();

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    vector<int> ans(len1 + len2);
    string str;
    int i = 0, j = 0, m = 0;

    while (j < len2 && s2[j] != '-')
    {
        i = 0;
        int k = ans.size() - 1 - j;
        int carry = 0;
        while (i < len1 && s1[i] != '-')
        {
            int val = (s1[i] - '0') * (s2[j] - '0') + carry + ans[k];
            carry = val / 10;
            ans[k--] = val % 10;
            i++;
        }
        while (carry)
        {
            ans[k--] = carry % 10;
            carry /= 10;
        }
        j++;
    }

    while (ans[m] == 0 && m < ans.size()) // logic to skip any leading zero
    {
        m++;
    }
    if ((flag1 == true && flag2 == false) || (flag1 == false && flag2 == true))// logic to handle (-) multiplication
    {
        str.push_back('-');
    }
    while (m < ans.size()) // logic to convert the int to string
    {

        str.push_back(ans[m] + '0');
        m++;
    }
    return str;
}

int main()
{
    // with logic to handle (-) multiplication
    
    string s1 = "25", s2 = "25";
    cout << find(s1, s2);

    return 0;
}
