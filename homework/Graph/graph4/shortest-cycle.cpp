#include<bits/stdc++.h>
using namespace std;
void bfs(int src,vector<int> adj[],int n,int& ans)
{
    vector<int> d(n,1e9);
    vector<int> p(n,-1);
    queue<int>q;
    d[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(d[it]==(int)(1e9))
            {
                d[it]=1+d[node];
                p[it]=node;
                q.push(it);
            }
            else if(p[node]!=it)
            {
                ans=min(ans,d[it]+d[node]+1);
            }
        }
    }
}
int shortestCycle(int n, vector<vector<int>>& edges)
{
    vector<int> adj[n+1];
    int ans=INT_MAX;
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0;i<n;i++)
    {
        bfs(i,adj,n,ans);
    }
    if(ans==INT_MAX)
        return -1;
    return ans;
}