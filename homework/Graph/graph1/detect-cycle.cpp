#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[],int ind, vector<bool>& vis, vector<bool>& rec)
{
    vis[ind]=true;
    rec[ind]=true;
    
    for(auto node:adj[ind])
    {
        if(vis[node]==false&&dfs(adj,node,vis,rec))
            return true;
        else if(rec[node]==true)
            return true;
    }
    rec[ind]=false;
    return false;
}

bool cycle(int v, vector<int> adj[]) {
    vector<bool> vis(v,false);
    vector<bool> rec(v,false);
    for(int i=0;i<v;i++)
    {
        if(!vis[i] && dfs(adj,i,vis,rec))
            return true;
    }
    return false;
}