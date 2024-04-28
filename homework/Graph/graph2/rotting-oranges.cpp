#include<bits/stdc++.h>
using namespace std;

int rotten(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> direction={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int frsh=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({i, j});
            }
            else if(grid[i][j]==1)
            {
                frsh++;
            }
        }
    }
    int time = 0;
    while(!q.empty() && frsh>0)
    {
        time++;
        int size=q.size();
        while(size)
        {
            pair<int,int> p=q.front();
            q.pop();
            for(auto it:direction)
            {
                int i=p.first+it[0];
                int j=p.second+it[1];
                if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1)
                {
                    grid[i][j]=2;
                    q.push({i,j});
                    frsh--;
                }
            }
            size--;
        }
    }
    if(frsh>0)
    {
        return -1;
    }
    return time;
}