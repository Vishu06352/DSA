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

    void DFSTraversal(int srcNode,int parent,unordered_map<int,bool>&visited,vector<int>&DiscoveryTime,vector<int>&Lowest_DiscoveryTime,int &timer,vector<vector<int> > &ans)
    {
        visited[srcNode] = true;
        DiscoveryTime[srcNode] = Lowest_DiscoveryTime[srcNode] = timer++;

        for(auto futureNode : adj[srcNode])
        {
            if(futureNode == parent)
                continue;
            
            if(!visited[futureNode])
            {
                DFSTraversal(futureNode,srcNode,visited,DiscoveryTime,Lowest_DiscoveryTime,timer,ans);
                Lowest_DiscoveryTime[srcNode] = min(Lowest_DiscoveryTime[futureNode],Lowest_DiscoveryTime[srcNode]);

                if(Lowest_DiscoveryTime[futureNode] > DiscoveryTime[srcNode]) // finding the bridge edge this condition means that there is one and only one way to reach this node
                {
                    vector<int>output;
                    output.push_back(srcNode);
                    output.push_back(futureNode);
                    ans.push_back(output);
                }
            }

            else // we will come to else case when we get a already visited node and this means that there is a back edge so need to update the lowDisc of srcNode by Disc time of futureNode
            {
                Lowest_DiscoveryTime[srcNode] = min(Lowest_DiscoveryTime[srcNode],DiscoveryTime[futureNode]);
            }
        }
    }

    vector<vector<int> > Find_Bridge_Edge()
    {
        vector<vector<int> > ans;

        vector<int>DiscoveryTime(adj.size(),-1);
        vector<int>Lowest_DiscoveryTime(adj.size(),-1);

        unordered_map<int,bool>visited;

        int parent = -1;
        int timer = 0;


        for(int i = 0 ; i < adj.size() ;i++)
        {
            if(!visited[i])
                DFSTraversal(i,parent,visited,DiscoveryTime,Lowest_DiscoveryTime,timer,ans);
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

    vector<vector<int> > ans = g.Find_Bridge_Edge();

   
    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i][0] <<" -> " << ans[i][1] <<endl;
    }

    return 0;
}