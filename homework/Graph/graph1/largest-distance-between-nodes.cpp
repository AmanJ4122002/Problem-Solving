#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int d, int& maxD, int& maxi, vector<int> adj[], vector<bool>& vis) {
    vis[node]=1;
    if(d>maxD)
    {
        maxD=d;
        maxi=node;
    }
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(vis[child]==0)
        {
            dfs(child,d+1,maxD,maxi,adj,vis);
        }
    }
}

int solve(vector<int> &v)
{
    int n=v.size();
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        if(v[i]==-1) 
            continue;
        addEdge(i,v[i],adj);
    }
    int maxD=-1;
    int node=0;
    vector<bool> vis(n,false);
    dfs(0,0,maxD,node,adj,vis);
    fill(vis.begin(),vis.end(),false);
    maxD=-1;
    dfs(node,0,maxD,node,adj,vis);
    return maxD;
}