#include<bits/stdc++.h>
using namespace std;
//Memoization
int f(int ind, vector<vector<int>> mat, vector<int> &dp)
{
    if(ind==0)
    {
        return max(mat[0][0],mat[1][0]);
    }
    if(ind<0)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int take=max(mat[0][ind],mat[1][ind])+f(ind-2,mat,dp);
    int notTake=0+f(ind-1,mat,dp);
    return dp[ind]=max(take,notTake);
}
int maxSum(int N, vector<vector<int>> mat)
{
    vector<int> dp(N,-1);
    return f(N-1,mat,dp);
}

//Tabulation
int maxSum(int N, vector<vector<int>> mat)
{
    vector<int> dp(N,-1);
    dp[0]=max(mat[0][0],mat[1][0]);
    for(int i=1;i<N;i++)
    {
        int take=max(mat[0][i],mat[1][i]);
        if(i>1)
        {
            take+=dp[i-2];
        }
        int notTake=0+dp[i-1];
        dp[i]=max(take,notTake);
    }
    return dp[N-1];
}

//Space optimization
int maxSum(int N, vector<vector<int>> mat)
{
    int prev1=0;
    int prev2=0;
    for(int i=0;i<N;i++)
    {
        int take=max(mat[0][i],mat[1][i]);
        if(i>1)
        {
            take+=prev2;
        }
        int notTake=0+prev1;
        prev2=prev1;
        prev1=max(take,notTake);
    }
    return prev1;
}