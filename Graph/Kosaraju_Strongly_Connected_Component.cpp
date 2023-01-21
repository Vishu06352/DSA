#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map<int,list<int> > adjList;
unordered_map<int,list<int> > tadjList;
stack<int>st;
class graph{
    public:
    void addNodes(int n) //directed graph
    {
        for(int i = 0 ; i < n; i++)
        {
            int u,v;
            cout <<"Enter the node: "<<endl;
            cin>>u>>v;
            adjList[u].push_back(v);
        }
    }

    void print()
    {
        for(auto i : adjList)
        {
            cout << i.first <<" -> ";
            for(auto j : i.second)
                cout << j <<" ";
            cout<<endl;
        }
    }
};

 // step 1 find topological sort
    void topologicalSort(int srcNode,vector<bool>&visited)
    {
        visited[srcNode] = true;

        for(auto i : adjList[srcNode])
        {
            if(!visited[i])
            topologicalSort(i,visited);
        }

        st.push(srcNode);
    }

// step 2 cerate transpose adjList
    void transposeAdjList()
    {
        for(auto i : adjList)
        {
            for(auto j : i.second)
            tadjList[j].push_back(i.first);
        }
    }

// step 3 dfs call 

void DFS(int srcNode,vector<bool>&visited)
{
    visited[srcNode] = true;

    for(auto i : tadjList[srcNode])
    {
        if(!visited[i]){
            DFS(i,visited);
        }
    }
}
int main()
{
    // eg 0->1, 1->2 , 2->1, 3->0, 3->4

    graph g;
    int nodes = 5,cnt = 0;
    vector<bool>visited(nodes,false);

    g.addNodes(nodes);

    // step 1 -> Topological sort
    for(int i = 0 ; i < nodes; i++)
    {
        if(!visited[i]){
            topologicalSort(i,visited);
        }
    }

    // step 2 -> transpose AdjList
    transposeAdjList();
    // step 3 -> DFS call

    for(int i = 0 ; i < nodes; i++)
    visited[i] = false;

    while(!st.empty())
    {
        if(!visited[st.top()])
            DFS(st.top(),visited),cnt++;

        else
        st.pop();
    }
    cout << "Number of strongly connected component is: "<< cnt << endl;

   
    return 0;
}