#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node,
         vector<int> adj[],
         vector<int>& vis,
         vector<int>& pathVis,
         vector<int>& check)
{
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0;

    for(auto neighbour:adj[node])
    {
        if(!vis[neighbour])
        {
            if(dfs(neighbour,adj,vis,pathVis,check))
                return true;
        }
        else if(pathVis[neighbour])
        {
            return true;
        }
    }

    check[node]=1;
    pathVis[node]=0;

    return false;
}

int main()
{
    int V,E;
    cin>>V>>E;

    vector<int> adj[V];

    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    vector<int> vis(V,0);
    vector<int> pathVis(V,0);
    vector<int> check(V,0);

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
            dfs(i,adj,vis,pathVis,check);
    }

    cout<<"Safe Nodes : ";

    for(int i=0;i<V;i++)
    {
        if(check[i])
            cout<<i<<" ";
    }

    return 0;
}