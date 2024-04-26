#include<bits/stdc++.h>
using namespace std;

bool valid(int x, int y, int a, int b)
{
    return (x>=1 && x<=a && y>=1 && y<=b);
}
int knight(int a, int b, int c, int d, int e, int f)
{
    vector<pair<int, int>> directions={{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    vector<vector<bool>> vis(a+1,vector<bool>(b+1,false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{c,d},0});
    while (!q.empty())
    {
        pair<pair<int,int>,int> p=q.front();
        q.pop();
        pair<int, int> cur=p.first;
        int distance=p.second;
        if (cur.first==e && cur.second==f)
        {
            return distance;
        }
        for(auto it:directions)
        {
            int new_x=cur.first+it.first;
            int new_y=cur.second+it.second;
            if (valid(new_x,new_y,a,b) && !vis[new_x][new_y])
            {
                vis[new_x][new_y]=true;
                q.push({{new_x, new_y},distance+1});
            }
        }
    }
    return -1;
}