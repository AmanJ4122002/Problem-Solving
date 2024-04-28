#include<bits/stdc++.h>
using namespace std;

void remove(vector<vector<char>>& grid,int i,int j)
{
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1')
        return;
    grid[i][j]='0';
    remove(grid,i-1,j);
    remove(grid,i+1,j);
    remove(grid,i,j-1);
    remove(grid,i,j+1);
}

int islands(vector<vector<char>>& grid)
{
    if(grid.size()==0)
        return 0;
    int cnt=0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]=='1')
            {
                remove(grid,i,j);
                cnt++;
            }
        }
    }
    return cnt;
}