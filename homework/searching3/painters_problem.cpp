#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &boards, int mid)
{
    int painters=1;
    int sum=0;
    for(int i=0;i<boards.size();i++)
    {
        if(sum+boards[i]<=mid)
        {
            sum+=boards[i];
        }
        else
        {
            painters++;
            sum=boards[i];
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low=*max_element(boards.begin(),boards.end());
    int high=accumulate(boards.begin(),boards.end(),0);
    while(low<=high)
    {
        int mid=(high+low)/2;
        int painters=partition(boards,mid);
        if(painters>k)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr={2,1,5,6,2,3};
    int k=2;
    cout<<findLargestMinDistance(arr,k)<<endl;
}