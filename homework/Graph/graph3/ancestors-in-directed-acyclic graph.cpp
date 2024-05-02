#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int> &v, vector<bool> &vis)
{
    vis[node]=true;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            v.push_back(it);
            dfs(it,adj,v,vis);
        }
    }
}
vector<vector<int>> ancestor(int n, vector<vector<int>>& edge)
{
    vector<int> adj[n];
    for(int i=0;i<edge.size();i++)
    {
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        vector<bool> vis(n,false);
        dfs(i,adj,v,vis);
        sort(v.begin(),v.end());
        ans.push_back(v);
    }
    return ans;
}