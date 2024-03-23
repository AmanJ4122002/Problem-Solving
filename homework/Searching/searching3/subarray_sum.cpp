#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> arr, int mid, int k)
{
    int sum=0;
    for(int i=0;i<mid;i++)
    {
        sum+=arr[i];
    }
    if(sum>k)
    {
        return false;
    }
    int j=0;
    for(int i=mid;i<arr.size();i++)
    {
        sum+=arr[i];
        sum-=arr[j];
        if(sum>k)
        {
            return false;
        }
        j++;
    }
    return true;
}
int subarray(vector<int> arr, int k)
{
    int low=1;
    int high=arr.size();
    while(low<=high)
    {
        int mid=(high+low)/2;
        bool ans=check(arr,mid,k);
        if(ans)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return high;
}
int main()
{
    vector<int> arr={1,3,4,2};
    int k=7;
    cout<<subarray(arr,k)<<endl;
}