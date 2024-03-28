#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* invert(TreeNode* root) {
    if(root==NULL)
        return root;
    TreeNode* left=invert(root->left);
    TreeNode* right=invert(root->right);
    root->left=right;
    root->right=left;
    return root;
}

int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(20);
    root->right=new TreeNode(70);
    root->left->left=new TreeNode(50);
    root->left->right=new TreeNode(40);
    root->right->left=new TreeNode(80);
    root->right->right=new TreeNode(90);
    TreeNode* ans=invert(root);

}