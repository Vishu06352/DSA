#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int find_celebrity(vector<vector<int>>m,int n)
{
    
   int  position = -1;
    for(int i = 0 ; i < n ; i++)
    {
        position = i;
        for(int j = 0 ; j  < n ; j++)
        {
            if( m[i][j] == 1 && i != j)
            {
                position = -1;
                break;
            }
        }
        if(position != -1) //agar celebrity mil gya toh stop karo aur check if everyone knows him or not
            break;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(i == position)
        continue;
        
        if(m[i][position] != 1)
        {
            return -1;
            break;
        }
    }
    return position;
}

int main()
{
    int n = 4;
    vector<vector<int>>m(n,vector<int>(n));
    
    m ={{0,0,1,0} , {0,0,1,0} ,{0,0,0,0} , {0,0,1,0} };

    cout << find_celebrity(m,n) << endl;

    return 0;
}