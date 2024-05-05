#include<bits/stdc++.h>
using namespace std;
int bfs(vector<vector<pair<int, int>>> &adj, int n, int s, int e)
{
    vector<int> dist(n+1,INT_MAX);
    deque<int> dq;
    dq.push_back({s});
    dist[s]=0;
    while (!dq.empty())
    {
        int node=dq.front();
        dq.pop_front();
        for (auto it:adj[node])
        {
            int v=it.first;
            int weight=it.second;
            if (dist[node]+weight<dist[v])
            {
                dist[v]=dist[node]+weight;
                if(weight==1)
                {
                    dq.push_back(v);
                }
                else
                {
                    dq.push_front(v);
                }
            }
        }
    }
    return dist[e]==INT_MAX?-1:dist[e];
}
int minEdge(vector<vector<int>> &edges, int n, int src, int dst)
{
    vector<vector<pair<int, int>>> adj(n+1);
    for (auto it:edges)
    {
        adj[it[0]].push_back({it[1],0});
        adj[it[1]].push_back({it[0],1});
    }
    return bfs(adj,n,src,dst);
}