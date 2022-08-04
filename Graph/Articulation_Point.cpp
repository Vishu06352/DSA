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

    void DFSTraversal(int srcNode , int parent , unordered_map<int,bool>&visited,vector<int>&DiscoveryTime,vector<int>&Lowest_DiscoveryTime,vector<int>&ans,int &timer)
    {
        visited[srcNode] = true;
        DiscoveryTime[srcNode] = Lowest_DiscoveryTime[srcNode] = timer++;

        int child = 0;

        for(auto futureNode : adj[srcNode])
        {
            if(futureNode == parent)
                continue;
            
            if(!visited[futureNode])
            {
                DFSTraversal(futureNode,srcNode,visited,DiscoveryTime,Lowest_DiscoveryTime,ans,timer);
                child++;

                Lowest_DiscoveryTime[srcNode] = min(Lowest_DiscoveryTime[futureNode],Lowest_DiscoveryTime[srcNode]);

                if(Lowest_DiscoveryTime[futureNode] >= DiscoveryTime[srcNode] && parent != -1)
                {
                    ans.push_back(srcNode);
                }
            }

            else // find a back edge
            {
                Lowest_DiscoveryTime[srcNode] = min(Lowest_DiscoveryTime[srcNode],DiscoveryTime[futureNode]);
            }
        }

        if(parent == -1 && child > 0)
            ans.push_back(srcNode);
    }

    vector<int> Find_Articulation_Point()
    {
        vector<int>ans;

        vector<int>DiscoveryTime(adj.size(),-1);
        vector<int>Lowest_DiscoveryTime(adj.size(),-1);
        unordered_map<int,bool>visited;

        int timer = 0;
        int parent = -1;

        for(int i = 0 ; i < adj.size(); i++)
        {
            if(!visited[i])
            {
                DFSTraversal(i,parent,visited,DiscoveryTime,Lowest_DiscoveryTime,ans,timer);
            }
        }
        return ans;
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

    // g.print();

    vector<int> ans = g.Find_Articulation_Point();

   
    for(auto i : ans)
    {
        cout << i <<" ";
    }
    return 0;
}