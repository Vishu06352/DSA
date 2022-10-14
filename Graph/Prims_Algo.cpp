#include<iostream>
#include<vector>
#include<set>
#include<limits.h>
#include<unordered_map>
#include<list>
#include<utility>
#include<algorithm>
using namespace std;

class graph
{
    unordered_map<int,list<pair<int,int> > >adj;
    public: 

    void add(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }   

    unordered_map<int,int>shortest(int srcNode)
    {
        set<pair<int,int> > st;
        unordered_map<int,int>parent;
        vector<int>Distance(adj.size(),INT_MAX);
        Distance[srcNode] = 0;
        parent[srcNode] = -1;

        st.insert(make_pair(0,srcNode));

        while(!st.empty())
        {
            auto top = *(st.begin());
            int node = top.second;
            st.erase(st.begin());

            for(auto i : adj[node])
            {
                int adjNode = i.first;
                int adjNodeDist = i.second;

                if(Distance[adjNode] > adjNodeDist){
                    Distance[adjNode] = adjNodeDist;
                    st.insert(make_pair(adjNodeDist,adjNode));
                    parent[adjNode] = node;
                }
            }
        }
        return parent;
    }
};

int main()
{
    graph g;
    // g.add(0,1,2);
    // g.add(0,3,6);

    // g.add(1,0,2);
    // g.add(1,3,8);
    // g.add(1,4,5);
    // g.add(1,2,3);

    // g.add(2,1,3);
    // g.add(2,4,7);

    // g.add(3,0,6);
    // g.add(3,1,8);

    // g.add(4,1,5);
    // g.add(4,2,7);

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
    unordered_map<int,int>parent = g.shortest(3);
    
    for(int i = 0 ; i  < parent.size() ; i++)
    {
        cout<<"Parent of "<<i << " is " << parent[i]<<endl;
    }
    
    return 0;
}