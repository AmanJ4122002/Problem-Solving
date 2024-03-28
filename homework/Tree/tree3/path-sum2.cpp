#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void pathsum(TreeNode* root, int target,vector<int>&temp,vector<vector<int>>& ans)
{
    if(root==NULL){
        return;
    }
    if(target==root->value && root->left==NULL && root->right==NULL){
        temp.push_back(root->value);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
    temp.push_back(root->value);
    pathsum(root->left,target-root->value,temp,ans);
    pathsum(root->right,target-root->value,temp,ans);
    temp.pop_back();
}
vector<vector<int>> Sum(TreeNode* root, int target) {
    vector<int> temp;
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
    pathsum(root,target,temp,ans);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(50);
    root->left=new TreeNode(40);
    root->right=new TreeNode(9);
    root->left->left=new TreeNode(11);
    root->right->left=new TreeNode(2);
    root->right->right=new TreeNode(30);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(1);
    root->right->right->left=new TreeNode(9);
    root->right->right->right=new TreeNode(6);


    vector<vector<int>> ans=Sum(root,22);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}