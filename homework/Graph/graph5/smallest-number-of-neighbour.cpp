#include<bits/stdc++.h>
using namespace std;
int find(int n, vector<vector<int>>& edges, int distance)
{
    vector<vector<int>> mat(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++)
    {
        mat[i][i]=0;
    }
    for(int i=0;i<edges.size();i++)
    {
        int src=edges[i][0];
        int dist=edges[i][1];
        int weight=edges[i][2];
        mat[src][dist]=weight;
        mat[dist][src]=weight;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    int city=0,maxi=n;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(i!=j && mat[i][j]<=distance)
                count++;
        }
        if(count<=maxi)
        {
            city=i;
            maxi=count;
        }
    }
    return city;
}