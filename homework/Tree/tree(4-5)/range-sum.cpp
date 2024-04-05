#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

int rangeSum(TreeNode* root, int low, int high) {
    if(root==NULL)
        return 0;
    int lsum=0,rsum=0,csum=0;
    if(root->value>=low && root->value<=high)csum=root->value;
    lsum=rangeSum(root->left,low,high);
    rsum=rangeSum(root->right,low,high);
    return lsum+rsum+csum;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    cout<<rangeSum(root,3,5)<<endl;
    return 0;
}