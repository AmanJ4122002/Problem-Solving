#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int index, vector<bool>& vis, vector<bool>& st)
{
    vis[index]=true;
    st[index]=true;
    for(auto it:adj[index])
    {
        if(vis[it]==false && dfs(adj,it,vis,st))
            return true;
        else if(st[it]==true)
            return true;
    }
    st[index]=false;
    return false;
}
bool cyclic(int v, vector<int> adj[])
{
    vector<bool> vis(v,false);
    vector<bool> st(v,false);
    for(int i=0;i<v;i++)
    {
        if(!vis[i] && dfs(adj,i,vis,st))
            return true;
    }
    return false;
}