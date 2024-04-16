#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* child[2];
    int count=0;
};

void insert(node *root, int n) 
{ 
    for (int i = 31; i >= 0; i--) 
    { 
        bool x = (n) & (1 << i);    
        if(!root->child[x]) 
        { 
            root->child[x] = new node(); 
        } 
        root->child[x]->count+= 1; 
        root= root->child[x]; 
    } 
} 


int smaller(node * root, int n, int k) 
{ 
    int pairs = 0; 
    for (int i = 31; i >= 0 && root; i--) 
    {                                      
        bool x=n&(1 << i); 
        bool y=k&(1 << i); 
        if(y==true) 
        { 
            if(root->child[x])
            {
                pairs+=root->child[x]->count; 
            }
            root=root->child[1 - x]; 
        }  
        else
        {  
            root=root->child[x]; 
        } 
    } 
    return pairs; 
} 

int Pair(vector<int>arr, int n, int k)
{
    node *root = new node(); 
    int pairs = 0; 
    for(int i = 0;i < n; i++)
    { 
        pairs+=smaller(root, arr[i], k); 
        insert(root, arr[i]); 
    } 
    return pairs; 
}

int countPairs(vector<int>& nums, int low, int high) {
    int n = nums.size(); 
    return Pair(nums, n, high + 1)-Pair(nums, n, low);
}