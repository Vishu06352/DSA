#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(string given ,int index, string mapping[10],string output,vector<string>& ans)
{
    if(index >= given.length())
    {
        ans.push_back(output);
        return ;
    }

    int number = given[index] - '0';
    string value = mapping[number];

    for(int i = 0 ; i < value.length() ; i++)
    {
        output.push_back(value[i]);
        solve(given,index+1,mapping,output,ans);
        output.pop_back();
    }

}

vector<string> find_seq(string given, string mapping[10])
{
    string output;
    vector<string> ans;
    int index = 0;
    solve(given,index,mapping,output,ans);
    return ans;
}

int main()
{
    string given = "23";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;

   ans = find_seq(given, mapping);

   for(string i : ans)
   {
       cout << i <<" ";
   }

    return 0;
}