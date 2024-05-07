#include<bits/stdc++.h>
using namespace std;
//Memoization
int f(int ind, vector<int> nums, vector<int> &dp)
{
    if(ind>=nums.size()-1)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int jmp=(int)(1e4);
    for(int i=1;i<=nums[ind];i++)
    {
        jmp=min(jmp,1+f(ind+i,nums,dp));
    }
    return dp[ind]=jmp;
}
int jump(vector<int>& nums)
{
    int n=nums.size();
    vector<int> dp(n,-1);
    return f(0,nums,dp);
}

//Tabulation
int jump(vector<int>& nums)
{
    int n=nums.size();
    vector<int> dp(n,10001);
    dp[0]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<=nums[i];j++)
        {
            if(i+j<n)
            {
                dp[i+j]=min(dp[i+j],1+dp[i]);
            }
        }
    }
    return dp[n-1];
}

