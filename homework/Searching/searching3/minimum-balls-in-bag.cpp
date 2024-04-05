#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums, int maxi,int mid)
{
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] % mid == 0){
            count += (nums[i]/mid) - 1;
        }
        else{
            count += (nums[i]/mid);
        }
        if(count > maxi){
            return false;
        }
    }
    if(count > maxi){
        return false;
    }
    return true;
}
int minimum(vector<int>& nums, int maxi) {
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(check(nums,maxi,mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}

int main()
{
    vector<int> v={2,4,8,3};
    int maxi=4;
    cout<<minimum(v,maxi)<<endl;
    return 0;
}