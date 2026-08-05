#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node,
         vector<int> adj[],
         vector<int>& vis,
         stack<int>& st)
{
    vis[node]=1;

    for(auto neighbour:adj[node])
    {
        if(!vis[neighbour])
            dfs(neighbour,adj,vis,st);
    }

    st.push(node);
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
    stack<int> st;

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
            dfs(i,adj,vis,st);
    }

    cout<<"Topological Order : ";

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}