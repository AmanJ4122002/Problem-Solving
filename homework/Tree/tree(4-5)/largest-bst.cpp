#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

int size(TreeNode* root)
{
    if(!root)
        return 0;
    return (size(root->left)+size(root->right)+1);
}

bool isBST(TreeNode* root,int min_,int max_)
{
    if(!root)
        return true;
    if(root->value <= min_ or root->value >= max_)
        return false;
    return (isBST(root->left, min_, root->value) && isBST(root->right, root->value, max_));
}

int largest(TreeNode *root)
{
	if(isBST(root,INT_MIN,INT_MAX)==true)
	    return size(root);
	 return max(largest(root->left),largest(root->right));
}

int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(15);
    root->right=new TreeNode(15);
    root->left->left=new TreeNode(45);
    root->left->right=new TreeNode(80);

    cout<<largest(root)<<endl;
    return 0;
}