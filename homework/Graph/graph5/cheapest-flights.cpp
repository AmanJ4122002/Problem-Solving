#include<bits/stdc++.h>
using namespace std;
int cheapest(int n, vector<vector<int>>& flights, int src, int dist, int k) 
{
    vector<pair<int,int>> adj[n];
    for(int i=0;i<flights.size();i++)
    {
        adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    }
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,src}});
    vector<int> dis(n,1e9);
    dis[src]=0;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int stop=it.first;
        int cost=it.second.first;
        int node=it.second.second;
        if(stop>k)
            continue;
        for(auto i:adj[node])
        {
            int adjNode=i.first;
            int weight=i.second;
            if(cost+weight<dis[adjNode] && stop<=k)
            {
                dis[adjNode]=cost+weight;
                q.push({stop+1,{dis[adjNode],adjNode}});
            }
        }
    }
    if(dis[dist]==1e9)
        return -1;
    return dis[dist];
}