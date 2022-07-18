#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>
#include<limits.h>
#include<stack>
#include<vector>
using namespace std;

class Graph
{
    public:
    unordered_map<int,list<pair<int,int> > > adj;

    void addNode(int u,int v,int w)
    {
        pair<int,int> p = make_pair(v,w);
        adj[u].push_back(p);
    }

    void PrintGraph()
    {
        for(auto i : adj)
        {
            cout << i.first <<"-> ";
            for(auto j :i.second)
            {
                cout << "["<<j.first<<","<<j.second <<"]";
            }cout<<endl;
        }
    }

    void DFSTraversal(int srcNode, unordered_map<int,bool>&visited,stack<int>&s)
    {
        visited[srcNode] = true;

        for(auto i : adj[srcNode])
        {
            if(!visited[i.first])
            {
                DFSTraversal(i.first,visited,s);
            }
        }
        s.push(srcNode);
    }

    stack<int> findTopologicalSort()
    {
        unordered_map<int,bool>visited;
        stack<int>s;

        for(int i = 0 ; i < adj.size() ; i++)
        {
            if(!visited[i])
            {
                DFSTraversal(i,visited,s);
            }
        }
        return s;
    }


    vector<int> ShortestDistance(int srcNode)
    {
        stack<int>s = findTopologicalSort();

        vector<int>ans(adj.size(),INT_MAX);
        ans[srcNode] = 0;

        int node = s.top();
        s.pop();

        for(auto i : adj[node])
        {
            int adjnode = i.first;
            int adjnodeDis = i.second;

            if(ans[adjnode] > adjnodeDis)
            ans[adjnode] = adjnodeDis;
        }
       
        while(!s.empty())
        {
            int topNode = s.top();
            s.pop();

            for(auto i : adj[topNode])
            {
                int topNodeDistance = ans[topNode];

                int adjNode = i.first;
                int adjDistance = i.second + topNodeDistance;

                if(ans[adjNode] > adjDistance)
                ans[adjNode] = adjDistance;
            }
        }
        
        return ans;
    }
};

int main()
{
    Graph g;
    g.addNode(0,1,5);
    g.addNode(0,2,3);
    g.addNode(1,2,2);
    g.addNode(1,3,6);
    g.addNode(2,3,7);
    g.addNode(2,4,4);
    g.addNode(2,5,2);
    g.addNode(3,4,-1);
    g.addNode(4,5,-2);

    g.PrintGraph();

    vector<int>ShortesPath = g.ShortestDistance(0);

    for(auto i : ShortesPath)
    {
        cout << i <<" ";
    }

    
    return 0;
}