#include<bits/stdc++.h>
using namespace std;

bool inside(int x, int y, int a, int b)
{
    return (x>=0 && x<a && y>=0 && y<b);
}

string solve(int a, int b, int n, int r, vector<int>& e, vector<int>& f)
{
    vector<vector<bool>> grid(a,vector<bool>(b,true));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a;j++)
        {
            for(int k= 0;k<b;k++)
            {
                if(sqrt(pow(e[i]-j,2)+pow(f[i]-k,2))< r)
                {
                    grid[j][k]=false;
                }
            }
        }
    }
    if(!grid[0][0] || !grid[a-1][b-1])
    {
        return "NO";
    }
    vector<vector<bool>> vis(a, vector<bool>(b,false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        int x=p.first;
        int y=p.second;
        if(x==a-1 && y==b-1)
        {
            return "YES";
        }
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nx=x+i;
                int ny=y+j;
                if(inside(nx,ny,a,b) && grid[nx][ny] && !vis[nx][ny])
                {
                    q.push({nx, ny});
                    vis[nx][ny]=true;
                }
            }
        }
    }
    return "NO";
}