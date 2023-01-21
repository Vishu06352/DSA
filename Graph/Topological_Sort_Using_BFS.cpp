#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;

class graph
{
    public:
    unordered_map<int,list<int> > adj;
    unordered_map<int,int> inDegree;
    void add(int u,int v)
    {
        adj[u].push_back(v);
        inDegree[v]++;
    }

    void PrintGraph()
    {
        for(auto i : adj)
        {
            cout << i.first <<"-> ";
            for(auto j :i.second)
            {
                cout << j << " ";
            }cout<<endl;
        }
    }

    void BFSTraversal(int srcNode , unordered_map<int,bool>&visited,unordered_map<int,int>&inDegree,vector<int>&ans)
    {
        visited[srcNode] = true;
        queue<int>q;
        
        for(auto i : inDegree)
        {
            if(i.second == 0)
            q.push(i.first);
        }

        while(!q.empty())
        {
            int frontNode = q.front();
            ans.push_back(frontNode);
            q.pop();

            for(auto i : adj[frontNode])
            {
                inDegree[i]--;
                if(!visited[i] && inDegree[i] == 0){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    vector<int> TopologicSearch()
    {
        vector<int>ans;
        unordered_map<int,bool>visited(adj.size());

        for(int i = 0 ; i < adj.size() ; i++)
        {
            if(!visited[i] && inDegree[i] == 0)
                BFSTraversal(i,visited,inDegree,ans);
        }
        return ans;
    }
};

int main()
{
    graph g;

    g.add(0,2);
    g.add(0,3);
    g.add(0,4);
    g.add(1,4);
    g.add(2,4);
    g.add(2,5);
    g.add(3,5);
    g.add(5,1);
    g.add(5,2);

    g.PrintGraph();

    vector<int>ans = g.TopologicSearch();

    for(auto i : ans)
    {
        cout << i <<" ";
    }

    return 0;
}