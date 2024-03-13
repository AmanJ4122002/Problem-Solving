#include<bits/stdc++.h>
using namespace std;

bool check(int mid,int cost, string s, string t)
    {
        int sum=0;
        for(int i=0;i<mid;i++)
        {
            sum+=abs(t[i]-s[i]);
        }
        if(sum<=cost)
        {
            return true;
        }
        int j=0;
        for(int i=mid;i<s.length();i++)
        {
            sum+=abs(t[i]-s[i]);
            sum-=abs(t[j]-s[j]);
            if(sum<=cost)
            {
                return true;
            }
            j++;
        }
        return false;
    }
int equalSubstring(string s, string t, int maxCost) {
        int low=0;
        int high=s.length();
        int a=0;
        while(low<=high)
        {
            int mid=(high+low)/2;
            bool ans=check(mid,maxCost,s,t);
            if(ans)
            {
                a=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return a;
}

int main()
{
    string s="abcd";
    string t="bcdf";
    int maxCost=3;
    cout<<equalSubstring(s,t,maxCost)<<endl;
}