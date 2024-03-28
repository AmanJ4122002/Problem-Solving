#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void path(TreeNode* root,int k,vector<int>& ans,vector<int>& v)
{
    if(root == NULL)
        return ;
    v.push_back(root->value);
    if(root->value==k)
    {
        ans=v;
        return ;
    }
    path(root->left,k,ans,v);
    path(root->right,k,ans,v);
    v.pop_back();    
}

vector<int> solve(TreeNode* root,int k)
{
    vector<int> ans;
    vector<int> v;
    path(root,k,ans,v);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    int x=50;
    vector<int> ans = solve(root,x);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}