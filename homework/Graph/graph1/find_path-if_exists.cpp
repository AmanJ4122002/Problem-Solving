#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& vis, int cur, int dest) 
{
    if(cur==dest)
        return true;
    if(vis[cur])
        return false;
    vis[cur]=1;
    for(int i=0; i<graph[cur].size(); i++)
    {
        if(dfs(graph,vis,graph[cur][i],dest))
            return true;
    }
    return false;
}

bool path(int n, vector<vector<int>>& edges, int source, int destination) 
{
    vector<vector<int>> graph(n);
    for(int i=0; i<edges.size(); i++) 
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(n, 0);
    return dfs(graph,visited,source,destination);
}