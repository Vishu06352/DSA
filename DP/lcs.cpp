#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

void printPath(vector<vector<char> > &path,string str,int n,int m)
{
    if(n == 0 || m == 0)
        return;
    
    if(path[n][m] == '.')
    {
        printPath(path,str,n-1,m-1);
        cout << str[n];
    }
    else if(path[n][m] == '^')
        printPath(path,str,n-1,m);
    else
        printPath(path,str,n,m-1);

}

int find_Lcs(string x,string y)
{
    int n = x.length();
    int m = y.length();

    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    vector<vector<char> > path(n+1,vector<char>(m+1,'0'));

    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(x[i] == y[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                path[i][j] = '.';
            }
            else if(dp[i-1][j] >= dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                path[i][j] = '^';
            }
            else{
                dp[i][j] = dp[i][j-1];
                path[i][j] = '<';
            }
        }
    }
    printPath(path,x,n,m);
    cout << endl;
    return dp[n][m];
}

int main()
{
    string x , y;
    cout <<"Enter string 1: ";
    cin>>x;
    cout << "Enter string 2: ";
    cin>>y;
    cout << endl;

    cout << find_Lcs(x,y);
    return 0;
}