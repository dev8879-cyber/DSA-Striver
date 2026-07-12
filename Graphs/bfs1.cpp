#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    queue<int>q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[n]){
            if(vis[it]==0){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}