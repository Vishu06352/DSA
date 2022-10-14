#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<limits.h>
#include<list>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

class graph
{
    public:
    unordered_map<int,list<pair<int,int> > > adj;
    void add(int u,int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> MST(int srcNode)
    {
        vector<bool>visited(adj.size());
        vector<int>Distance(adj.size(),INT_MAX);

        unordered_map<int,int>parent;
        set<pair<int,int> > st;

        Distance[srcNode] = 0;
        parent[srcNode] = -1;
        visited[srcNode] = true;
        st.insert({0,srcNode});


        while(!st.empty())
        {
            auto top = *(st.begin());
            int Node = top.second;

            for(auto i : adj[Node])
            {
                int ;
            }
        }
        
    }
};

int main()
{
    graph g;
   g.add(0,1,5);
    g.add(0,2,3);

    g.add(1,0,5);
    g.add(1,3,6);
    g.add(1,2,2);

    g.add(2,0,3);
    g.add(2,1,2);
    g.add(2,3,7);
    g.add(2,4,4);
    g.add(2,5,2);

    g.add(3,1,6);
    g.add(3,2,7);
    g.add(3,4,-1);

    g.add(4,3,-1);
    g.add(4,2,4);
    g.add(4,5,-2);
    
    g.add(5,4,-2);
    g.add(5,2,2);

    int srcNode = 2;
    g.MST(srcNode);
    return 0;
}