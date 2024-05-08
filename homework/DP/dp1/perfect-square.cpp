#include<bits/stdc++.h>
using namespace std;
//Memoization
int f(int n, vector<int> &dp)
{
    if(n<=0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int count=1e9;
    for(int i=1;i*i<=n;i++)
    {
        count=min(count,1+f(n-i*i,dp));
    }
    return dp[n]=count;
}
int numSquares(int n)
{
    vector<int> dp(n+1,-1);
    return f(n,dp);
}

//Tabulation
int numSquares(int n)
{
    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int count=1e9;
        for(int j=1;j*j<=i;j++)
        {
            count=min(count,1+dp[i-j*j]);
        }
        dp[i]=count;
    }
    return dp[n];
}