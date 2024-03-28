#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void rightView(TreeNode* root,int level,vector<int>& ans)
{
    if(root==NULL)
        return;
    if(ans.size()<=level)
    {
        ans.push_back(root->value);
    }
    rightView(root->right,level+1,ans);
    rightView(root->left,level+1,ans);
}
vector<int> rightSide(TreeNode* root) {
    vector<int> ans;
    rightView(root,0,ans);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(30);
    root->right=new TreeNode(20);
    root->left->right=new TreeNode(50);
    root->right->right=new TreeNode(60);
    vector<int> ans=rightSide(root);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}