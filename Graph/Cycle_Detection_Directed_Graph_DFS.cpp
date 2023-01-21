#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

/*
    Note in cycle Detection we have 2 graph -> Directed and Undirected 
    Undirected Graph -> BFS and DFS normal way to find cycle and just create visited and parent mapping
    Directed Graph -> Using DFS we take DFSVisited and Visited mapping 
                      But using BFS use kahn's Algorithm (BFS Topological ordering)
*/

unordered_map<int,list<int> >adjList;
class graph{
    public:
    void addNodes(int nodes)
    {
        for(int i = 0 ; i < nodes; i++)
        {
            int u,v;
            cout <<"Enter the node1 and node2 value"<<endl;
            cin>>u>>v;
            adjList[u].push_back(v);
        }
    }

    void Print()
    {
        for(auto i: adjList)
        {
            cout << i.first;
            for(auto j : i.second)
            cout << j <<" ";
            cout <<endl;           
        }
    }
};

bool DFSTraversal(unordered_map<int,bool>&visited,unordered_map<int,bool>&DFSVisited,int srcNode)
{
    visited[srcNode] = true;
    DFSVisited[srcNode] = true;

    for(auto i : adjList[srcNode])
    {
        if(!visited[i])
        {
            bool ans = DFSTraversal(visited,DFSVisited,i);
            if(ans)
            return ans;
        }
        else if(visited[i] && DFSVisited[i])
        return true;
    }
    DFSVisited[srcNode] = false;
    return false;
}

int main()
{
    graph g;
    unordered_map<int,bool>visited,DFSVisited;
    int nodes;
    cout <<"Enter the number of nodes"<<endl;
    cin>>nodes;

    g.addNodes(nodes);
    bool ans = false;

    for(int i = 0 ; i < nodes; i++)
    {
        if(!visited[i])
        ans = DFSTraversal(visited,DFSVisited,i);

        if(ans)
        break;
    }

    if(ans)
    cout <<"Cycle is present in the directed graph"<<endl;
    else
    cout <<"Cycle is not present in the directed graph"<<endl;

    return 0;
}