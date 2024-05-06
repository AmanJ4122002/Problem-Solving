#include<bits/stdc++.h>
using namespace std;
//Memoization
int maxSum(int ind, vector<int> nums, vector<int> &dp)
{
    if(ind==0)
    {
        return nums[ind];
    }
    if(ind<0)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int pick=nums[ind]+maxSum(ind-2,nums,dp);
    int notPick=0+maxSum(ind-1,nums,dp);
    return dp[ind]=max(pick,notPick);
}
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
    {
        return nums[0];
    }
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);
    }
    vector<int> dp1(n-1,-1);
    vector<int> dp2(n-1,-1);
    return max(maxSum(n-2,temp1,dp1),maxSum(n-2,temp2,dp2));
}

//Tabulation
int maxSum(vector<int> nums)
{
    int n=nums.size();
    vector<int> dp(n,-1);
    dp[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        int pick=nums[i];
        if(i>1)
        {
            pick+=dp[i-2];
        }
        int notPick=0+dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[n-1];
}
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
    {
        return nums[0];
    }
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);
    }
    return max(maxSum(temp1),maxSum(temp2));
}

//Space optimization
int maxSum(vector<int> nums)
{
    int n=nums.size();
    int prev2=0;
    int prev=nums[0];
    for(int i=1;i<n;i++)
    {
        int take=nums[i];
        if(i>1)
        {
            take+=prev2;
        }
        int notTake=0+prev;
        int curi=max(take,notTake);
        prev2=prev;
        prev=curi;
    }
    return prev;
}
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
    {
        return nums[0];
    }
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);
    }
    return max(maxSum(temp1),maxSum(temp2));
}