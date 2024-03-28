#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void pathsum(TreeNode* root, int target , map<long long,int>& mp,int& ans,long long& sum)
{
    if(root==NULL)
        return;
    sum+=root->value;
    if(sum==target)
        ans++;
    ans+=mp[sum-target];
    mp[sum]++;
    pathsum(root->left,target,mp,ans,sum);
    pathsum(root->right,target,mp,ans,sum);
    mp[sum]--;
    sum-=root->value;
}
int Sum(TreeNode* root, int target) {
    map<long long,int> mp;
    long long sum=0;
    int ans=0;
    pathsum(root,target,mp,ans,sum);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(-3);
    root->right->right=new TreeNode(11);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(2);
    root->left->left->left=new TreeNode(3);
    root->left->left->right=new TreeNode(-2);
    root->left->right->right=new TreeNode(1);


    cout<<Sum(root,8);
    return 0;
}