#include<bits/stdc++.h>
using namespace std;

vector<int> vertices(int n, vector<vector<int>>& edges)
{
    vector<int> inDegree(n, 0);
    for (auto it:edges)
    {
        inDegree[it[1]]++;
    }
    vector<int> ans;
    for (int i=0;i<n;i++)
    {
        if (inDegree[i]==0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}