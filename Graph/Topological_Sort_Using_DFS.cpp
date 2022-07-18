#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<utility>
#include<unordered_map>
#include<algorithm>
using namespace std;

class graph
{
    public:
   
    unordered_map<int,list<pair<int,int> > > adj;

    void add(int u , int v ,int w)
    {
        pair<int,int>p = make_pair(v,w);
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

    void DFSTraversal(int srcNode,unordered_map<int,bool>&visited,stack<int>&s)
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

    vector<int> topoLogical()
    {
        vector<int>ans;
        stack<int>s;
        unordered_map<int,bool>visited;
        for(int i = 1 ; i <= adj.size(); i++)
        {
            if(!visited[i])
            {
                DFSTraversal(6,visited,s);
            }
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    graph g;
    g.add(1,2,2);
    g.add(1,3,2);
    g.add(1,4,1);
    g.add(2,4,2);
    g.add(3,4,3);
    g.add(3,5,1);
    g.add(4,5,2);
    g.add(6,1,1);
    g.add(6,2,5);

    g.PrintGraph();
    vector<int>ans = g.topoLogical();

    for(auto i : ans)
    {
        cout << i <<" ";
    }

    
    return 0;
}