#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& connected,int i,vector<bool>& vis)
{
    queue<int> q;
    vis[i]=true;
    q.push(i);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for (int j=0;j<connected.size(); j++)
        {
            if (connected[node][j]==1 && !vis[j])
            {
                vis[j]=true;
                q.push(j);
            }
        }
    }
}

int find(vector<vector<int>>& isConnected) {
   int count=0;
   vector<bool> vis(isConnected.size(),false);
   for(int i=0;i<isConnected.size();i++)
   {
        if(vis[i]==false)
        {
            bfs(isConnected,i,vis);
            count++;
        }
   }
   return count;
}