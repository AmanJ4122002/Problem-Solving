#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* child[2];
    node()
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};

class solve {
public:
    void insert(node* root,int num)
    {
        node* res = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!res->child[bit])
                res->child[bit] = new node();
            res = res->child[bit];
        }
    }
    int maxXor(vector<int>& nums)
    {
        node* root=new node();
        int maxor=0;
        for(auto it:nums)
        {
            insert(root,it);
        }
        for(int j=0;j<nums.size();j++)
        {
            int _xor=0;
            node* res=root;
            for(int i=31;i>=0;i--)
            {
                int bit=(nums[j]>>i)&1;
                if(res->child[1-bit]!=NULL)
                {
                   res = res->child[1-bit];
                   _xor+=(1<<i);
                } 
                else
                {
                    res=res->child[bit];
                }
            }
            maxor=max(maxor,_xor);
        }
        return maxor;
    }
};