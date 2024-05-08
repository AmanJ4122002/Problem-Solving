#include<bits/stdc++.h>
using namespace std;
//Memoization
long long f(int i, int n, vector<vector<int>>& questions,vector<long long> &dp)
{
    if(i==n)
    {
        return questions[n][0];
    }
    if(i>n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    long long take=questions[i][0]+f(i+questions[i][1]+1,n,questions,dp);
    long long notTake=0+f(i+1,n,questions,dp);
    return dp[i]=max(take,notTake);
}
long long mostPoints(vector<vector<int>>& questions)
{
    int n=questions.size();
    vector<long long> dp(n,-1);
    return f(0,n-1,questions,dp);
}

//Tabulation
long long mostPoints(vector<vector<int>>& questions)
{
    int n=questions.size();
    vector<long long> dp(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        long long take=questions[i][0];
        if(i+questions[i][1]+1<n)
        {
            take+=dp[i+questions[i][1]+1];
        }
        long long notTake=0+dp[i+1];
        dp[i]=max(take,notTake);
    }
    return dp[0];
}