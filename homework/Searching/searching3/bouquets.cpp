#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> arr, int mid, int m, int k)
{
  int cnt=0;
  int noOfB=0;
  for(int i=0;i<arr.size();i++)
  {
    if(arr[i]<=mid)
    {
      cnt++;
    }
    else
    {
      noOfB+=(cnt/k);
      cnt=0;
    }
  }
  noOfB+=(cnt/k);
  return noOfB>=m;
}
int roseGarden(vector<int> arr, int k, int m)
{
  int low=*min_element(arr.begin(),arr.end());
  int high=*max_element(arr.begin(),arr.end());
  long long ans=m*1LL*k*1LL;
  if(arr.size()<ans)
  {
    return -1;
  }
  while(low<=high)
  {
    int mid=(high+low)/2;
    if(possible(arr,mid,m,k))
    {
      high=mid-1;
    }
    else
    {
      low=mid+1;
    }
  }
  return low;
}

int main()
{
    vector<int> arr={1,2,1,2,7,2,2,3,1};
    int k=3,m=2;
    cout<<roseGarden(arr,k,m)<<endl;
}