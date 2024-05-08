#include<bits/stdc++.h>
using namespace std;
//Memoization
int mod=(int)(1e9+7);
int f(int ind, int k, int target, vector<vector<int>> &dp)
{
    if(ind==0 && target==0)
    {
        return 1;
    }
    else if(ind==0 || target<=0)
    {
        return 0;
    }
    if(dp[ind][target]!=-1)
    {
        return dp[ind][target];
    }
    long long count=0;
    for(int i=1;i<=k;i++)
    {
        count+=f(ind-1,k,target-i,dp)%mod;
    }
    return dp[ind][target]=count%mod;
}
int numRollsToTarget(int n, int k, int target)
{
    vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
    return f(n,k,target,dp);
}

//Tabulation
int numRollsToTarget(int n, int k, int target)
{
    vector<vector<int>> dp(n+1,vector<int> (target+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            long long count=0;
            for(int l=1;l<=k;l++)
            {
                if(l<=j)
                {
                    count+=dp[i-1][j-l]%mod;
                }
            }
            dp[i][j]=count%mod;
        }
    }
    return dp[n][target];
}