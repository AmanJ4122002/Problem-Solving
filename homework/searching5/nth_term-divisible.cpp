#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
 
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int divisible(int a,int b,int c,int d)
{
    return ((d / a) + (d / b) + (d / c)
            - (d / lcm(a, b))
            - (d / lcm(b, c))
            - (d / lcm(a, c))
            + (d / lcm(a, lcm(b, c))));
}

int findN(int a,int b,int c,int n)
{
    int low=1,high=INT_MAX;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(divisible(a,b,c,mid)<n)
        {
            low=mid+1;
        }
        else
            high=mid;
    }
    return low;
}

int main()
{
    int a=2,b=3,c=5,N=10;
    cout<<findN(a,b,c,N)<<endl;
}