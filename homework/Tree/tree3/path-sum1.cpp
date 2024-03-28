#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

bool Sum(TreeNode* root, int target) {
    if(root==NULL )
        return false;
    if(target==root->value && root->left==NULL && root->right==NULL)
        return true;
    return Sum(root->left,target-root->value)||Sum(root->right,target-root->value);
}


int main()
{
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right->right->right=new TreeNode(1);

    if(Sum(root,22))
        cout<<"Path Found";
    else
        cout<<"NO path Found";
    return 0;
}