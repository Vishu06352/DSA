#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<list>
#include<utility>
#include<limits.h>
using namespace std;

class graph
{
    unordered_map<int,list<pair<int,int> > >adj;
    set<pair<int,int> > st;
    public:

    void add(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> shortestPath(int srcNode)
    {
        vector<int>Distance(adj.size(),INT_MAX);
        Distance[srcNode] = 0;

        st.insert(make_pair(0,srcNode));

        while(!st.empty())
        {
            auto top = *(st.begin());
            st.erase(st.begin());

            int nodeDistance = top.first;
            int node = top.second;

            for(auto i : adj[node])
            {
                int adjNode = i.first;
                int adjNodeDistance = i.second;

                if(nodeDistance + adjNodeDistance < Distance[adjNode])
                {
                    auto record = st.find(make_pair(Distance[adjNode],adjNode));
                    
                    if(record != st.end())
                        st.erase(record);

                    Distance[adjNode] = nodeDistance + adjNodeDistance;
                    st.insert(make_pair(Distance[adjNode],adjNode));
                }
            }
        }

        return Distance;
    }

};

int main()
{
    graph g;
    g.add(0,1,7);
    g.add(0,2,1);
    g.add(0,3,2);

    g.add(1,2,3);
    g.add(1,3,5);
    g.add(1,4,1);

    // g.add(2,0,1);
    // g.add(2,1,3);

    // g.add(3,0,2);
    // g.add(3,1,5);
    g.add(3,4,7);

    // g.add(4,1,1);
    // g.add(4,3,7);

    int srcNode = 2;
    vector<int>ans = g.shortestPath(srcNode);

    for(auto i : ans)
    {
        cout << i <<" ";
    }
    // t.c -> o(v^2) and s.c -> o(v+e)
    return 0;
}