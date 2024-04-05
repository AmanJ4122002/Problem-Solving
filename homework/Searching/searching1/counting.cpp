#include<bits/stdc++.h>
using namespace std;

int Greater(vector<int>& a,int val)
{
    int low=0;
    int high=a.size();
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=val)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        
    }
    if(ans==-1) return 0;
    return a.size()-ans;
}

vector<int> count(vector<int>& a,vector<int>&b)
{
    sort(a.begin(),a.end());
    vector<int> ans;
    for(int i = 0; i < b.size(); i++)
    {
        ans.push_back(Greater(a,b[i]));
    }
    return ans;
}

int main()
{
    int n=5,q=5;
    vector<int> a={1,2,3,4,5};
    vector<int> b={6,5,4,3,2};
    vector<int> ans=count(a,b);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}