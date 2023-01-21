#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

/*
    NOTES
    1 -> We can also find wheather cycle is present or not in graph;
    2-> We can find out the number of component in the graph
*/

void makeSet(vector<int>&parent,vector<int>&rank,int n)
{
    for(int i= 0 ; i<n; i++)
    {
        parent[i]=i;
        rank[i] = 0;
    }
}

int findParent(int node,vector<int>&parent)
{
    if(parent[node] = node)
        return node;

    return parent[node] = findParent(parent[node],parent);
}

int unionFind(int u,int v,vector<int>&rank,vector<int>&parent)
{
    int parent_of_u = findParent(u,parent);
    int parent_of_v = findParent(v,parent);
    
    if(rank[parent_of_u] > rank[parent_of_v])
        parent[parent_of_v] = parent_of_u;

    else if(rank[parent_of_v] > rank[parent_of_u])
        parent[parent_of_u] = parent_of_v;

    else{
        parent[parent_of_v] = parent_of_u;
        rank[parent_of_u]++;
    }

}
int main()
{
    int n = 7;
    vector<int>parent,rank;
    makeSet(parent,rank,n);
    return 0;
}