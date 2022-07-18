#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class graph
{
    public:

    void addNodes(int x,int y,bool direction,vector<int>adj_list[])
    {
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    void Print(vector<int>adj[])
    {
        for(int i = 0 ; i < 5; i++)
        {
            cout << i <<"->";

            for(auto j : adj[i])
            {
                cout << j<<" ,";
            }cout<<endl;
        }
    }
    
};


int main()
{
   
    vector<int>adj_list[5];
    graph g;
    
    cout<<"Enter the pair of node and edge"<<endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        int x,y;
        cin>>x>>y;
        g.addNodes(x,y,0,adj_list);
    }

    g.Print(adj_list);

    return 0;
}