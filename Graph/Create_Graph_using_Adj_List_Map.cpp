#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<unordered_map>
using namespace std;

class graph
{
    public:
    unordered_map<int,list<int>>adj_list;

    void addNode(int x,int y , bool direction)
    {
        //If direction is 0 - Undirected Grapgh
        //If direction is 1 - Directed Graph

        adj_list[x].push_back(y);

        if(direction == 0){
            adj_list[y].push_back(x);
        }

    }

    void PrintGraph()
    {
        for(auto i : adj_list)
        {
            cout << i.first <<"-> ";
            for(auto j : i.second)
            {
                cout<<j<<" ,";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n , m ;

    cout<<"Enter the number of nodes and edges: "<<endl;
    cin>>n>>m;

    graph g;

    for(int i = 0 ; i < n ; i++)
    {
        int x , y;
        cin>>x>>y;
        g.addNode(x,y,0);
    }

    g.PrintGraph();

    
    return 0;
}