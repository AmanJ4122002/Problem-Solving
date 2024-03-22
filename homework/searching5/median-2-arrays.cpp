#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    if(n1>n2)
    {
        return findMedianSortedArrays(nums2,nums1);
    }
    int low=0;
    int high=n1;
    int left=(n1+n2+1)/2;
    int n=n1+n2;
    while(low<=high)
    {
        int mid1=(high+low)/2;
        int mid2=left-mid1;
        int l1=INT_MIN;
        int l2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MAX;
        if(mid1<n1)
        {
            r1=nums1[mid1];
        }
        if(mid2<n2)
        {
            r2=nums2[mid2];
        }
        if(mid1-1>=0)
        {
            l1=nums1[mid1-1];
        }
        if(mid2-1>=0)
        {
            l2=nums2[mid2-1];
        }
        if(l1<=r2 && l2<=r1)
        {
            if(n%2==1)
            {
                return max(l1,l2);
            }
            else
            {
                return (double)(max(l1,l2)+min(r1,r2))/2;
            }
        }
        else if(l1>r2)
        {
            high=mid1-1;
        }
        else
        {
            low=mid1+1;
        }
    }
    return 0;
}
int main()
{
    vector<int> nums1={1,3};
    vector<int> nums2={2};
    double ans=findMedianSortedArrays(nums1,nums2);
    cout<<ans;
    return 0;
}