#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(string& given , int index , vector<string>& ans)
{
    if(index >= given.length())
    {
        ans.push_back(given);
        return ;
    }

    for(int i = index ; i  < given.length() ; i++)
    {
        swap(given[index],given[i]);
        solve(given,index+1,ans);
        swap(given[index],given[i]);
    }
}

vector<string> find_seq(string given)
{
    int index = 0;
    vector<string>ans;
    
    solve(given,index,ans);

    return ans;
}

int main()
{
    string given = "123";
    vector<string>ans;
    ans = find_seq(given);

    for(string i : ans)
    {
        cout << i <<" ";
    }
    return 0;
}