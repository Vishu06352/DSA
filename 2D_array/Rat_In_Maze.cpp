#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<vector<int>> &m, vector<vector<int>> &visited, int newx, int newy, int size)
{
    if ((newx >= 0 && newx < size) && (newy >= 0 && newy < size) && visited[newx][newy] == 0 && m[newx][newy] == 1)
    {
        return true;
    }
    return false;
}
void find_ways(vector<vector<int>>m, vector<vector<int>> &visited,int x,int y, int n,vector<string>&ans,string path)
{
    if( x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }
        visited[x][y] = 1;

       
            // Down
            int newx = x + 1;
            int newy = y;
            if (check(m, visited, newx, newy, n))
            {
                path.push_back('D');
                find_ways(m,visited,newx,newy ,n,ans,path);
                path.pop_back();
            }

            // Left
            newx = x;
            newy = y - 1;
            if (check(m, visited, newx, newy, n))
            {
                path.push_back('L');
                find_ways(m,visited,newx,newy ,n,ans,path);
                path.pop_back();
            }
            // Right
            newx = x;
            newy = y + 1;
            if (check(m, visited, newx, newy, n))
            {
                path.push_back('R');
                find_ways(m,visited,newx,newy,n,ans,path);
                path.pop_back();
            }
            // Up
            newx = x - 1;
            newy = y;
            if (check(m, visited, newx, newy, n))
            {
                path.push_back('R');
                find_ways(m,visited,newx,newy,n,ans,path);
                path.pop_back();
            }

            visited[x][y] = 0;
}
int main()
{
    int n;
    cout << "Enter the size of the matrix -> ";
    cin >> n;

    vector<vector<int>> m (n,vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string>ans;
    string path;
    int x = 0 , y = 0;

    find_ways(m,visited,x,y ,n,ans,path);
    sort(ans.begin(),ans.end());

    for(auto i : ans)
    {
        cout << i <<" ";
    }

    return 0;
}