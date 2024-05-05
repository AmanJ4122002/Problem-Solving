#include<bits/stdc++.h>
using namespace std;

int largestPath(string colors, vector<vector<int>>& edges)
{
    int n = colors.size();
    vector<int> adj[n];
    vector<int> inDeg(n, 0);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        inDeg[it[1]]++;
    }
    queue<int> q;
    vector<vector<int>> nodeToColor(n,vector<int>(26, 0));
    for(int i=0;i<n;i++)
    {
        if(inDeg[i]==0)
        {
            q.push(i);
            nodeToColor[i][colors[i]-'a']=1;
        }
    }
    int ans=0;
    int count=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        count++;
        for(int& it:adj[node])
        {
            for(int col=0;col<26;col++)
            {
                nodeToColor[it][col]=max(nodeToColor[it][col],nodeToColor[node][col]+(colors[it]-'a'==col?1:0));
            }
            inDeg[it]--;
            if(inDeg[it]==0)
                q.push(it);
        }
        ans=max(ans,*max_element(nodeToColor[node].begin(),nodeToColor[node].end()));
    }
    return count<n?-1:ans;
}