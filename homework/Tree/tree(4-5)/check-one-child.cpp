#include<bits/stdc++.h>
using namespace std;
 
bool oneChild(vector<int> v, int size)
{
    int next, last;
 
    for (int i=0; i<size-1; i++)
    {
        next=v[i]-v[i+1];
        last=v[i]-v[size-1];
        if (next*last<0)
            return false;;
    }
    return true;
}

int main()
{
    vector<int> v={1,2,3,4,5};
    int size=5;
    if (oneChild(v,size)==true)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}