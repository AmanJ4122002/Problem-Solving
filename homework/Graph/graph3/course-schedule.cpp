#include<bits/stdc++.h>
using namespace std;
bool finish(int course, vector<vector<int>>& prerqui)
{
    vector<int> adj[course];
    for(int i=0;i<prerqui.size();i++)
    {
        adj[prerqui[i][0]].push_back(prerqui[i][1]);
    }
    int indeg[course];
    for(int i=0;i<course;i++)
    {
        indeg[i]=0;
    }
    for(int i=0;i<course;i++)
    {
        for(auto it:adj[i])
            indeg[it]++;
    }
    queue<int> q;
    for(int i=0;i<course;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
    vector<int> top_sort;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        top_sort.push_back(node);
        for(auto it:adj[node])
        {
            indeg[it]--;
            if(indeg[it]==0)
                q.push(it);
        }
    }
    if(top_sort.size()==course)
        return true;
    else
        return false;
}