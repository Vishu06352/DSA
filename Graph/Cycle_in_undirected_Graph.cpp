#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

unordered_map<int,list<int> > adjList;
class graph{
    public:
    void addNodes(int nodes)
    {
        for(int i = 0 ; i < nodes; i++)
        {
            int u,v;
            cout <<"Enter the node1 and node2 values"<<endl;
            cin>>u>>v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i : adjList)
        {
            cout << i.first <<" -> ";
            for(auto j : i.second)
            cout << j <<" ";
            cout <<endl;
        }
    }

    bool BFSTraversal()
    {
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        queue<int>q;

        for(auto i : adjList)
        {
            if(!visited[i.first])
            {
                q.push(i.first);
                visited[i.first] = true;
                parent[i.first] = -1;
                
                while(!q.empty())
                {
                    int srcNode = q.front();
                    q.pop();

                    for(auto j : adjList[srcNode])
                    {
                        if(!visited[j])
                        {
                            q.push(j);
                            visited[j] = true;
                            parent[j] = srcNode;
                        }
                        else if(visited[j] && j != parent[srcNode])
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

bool DFSTraversal(int srcNode,int parent,unordered_map<int,bool>&visited)
{
    visited[srcNode] = true;

    for(auto i : adjList[srcNode])
    {
        if(!visited[i])
        {
            bool ans = DFSTraversal(i,srcNode,visited);
            if(ans)
            return ans;
        }
        else if(visited[i] && i != parent)
        return true;
    }
    return false;
}

int main()
{
    graph g;
    unordered_map<int,bool>visited;
    int nodes;

    cout<<"Enter the number of the nodes" << endl;
    cin >> nodes;

    g.addNodes(nodes);
    
    if(g.BFSTraversal())
    cout << "Cycle is present in the graph" << endl;
    else
    cout << "Cycle is not present in the graph" << endl;
    
    if(DFSTraversal(1,-1,visited))
    cout << "Cycle is present in the graph" << endl;
    else
    cout << "Cycle is not present in the graph" << endl;


    return 0;
}