#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(string given , int index , string output,vector<string>& ans )
{
    if(index >= given.length())
    {
        ans.push_back(output);
        return ;
    }

    //exclude (waali game m sirf function call marni h with index increment)
    solve(given,index+1,output,ans);

    //include (waali game m phele given string ka number store kara and phir function call marde)
    output.push_back(given[index]);
    solve(given,index+1,output,ans);
}

void find_seq(string given , string output, vector<string>& ans)
{
    int index = 0;
    solve(given,index,output,ans);
}

int main()
{
    string given = "123";
    string output;
    vector<string>ans;

    find_seq(given,output,ans);

    //iss me bass blank add nhi ho rhi maybe compiler ka fark ho 
    for(string i : ans)
    {
        cout << i <<" ";
    }

    return 0;
}