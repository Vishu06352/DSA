#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

class graph
{
    public:
    unordered_map<int,list<int> > adj;

    void add(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print()
    {
        for(int i = 0 ; i < adj.size(); i++)
        {
            cout << i <<"-> ";

            for(auto j : adj[i])
            {
                cout << j << " ,";
            }cout <<endl;
        }
    }
};

int main()
{
    graph g;
    g.add(0,1);
    g.add(0,2);
    g.add(1,2);
    g.add(1,6);
    g.add(1,3);
    g.add(1,4);
    g.add(3,5);
    g.add(5,4);

    g.print();

    return 0;
}