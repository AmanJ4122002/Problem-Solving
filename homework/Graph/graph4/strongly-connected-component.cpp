#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>& vis, vector<vector<int>>& adj ,stack<int>& st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}
void dfs(int node, vector<int>& vis, vector<vector<int>>& adj)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj);
        }
    }
}

int kosaraju(int v, vector<vector<int>>& adj)
{
    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,st);
        }
    }
    vector<vector<int>> adj(v);
    for(int i=0;i<v;i++)
    {
        vis[i]=0;
        for(auto it:adj[i])
        {
            adj[it].push_back(i);
        }
    }
    
    int cnt=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            cnt++;
            dfs(node,vis,adj);
        }
    }
    return cnt;
}