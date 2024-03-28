#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

int res=0;
int help(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lh=help(root->left);
    int rh=help(root->right);
    res=max(res,lh+rh);
    return 1+max(lh,rh);
}
int diameter(TreeNode* root) {
    int a=help(root);
    return res;
}


int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(30);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(60);
    root->left->right=new TreeNode(40);

    cout<<diameter(root)<<endl;
    return 0;
}