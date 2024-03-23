#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode *root)
{
    if(root==NULL)
        return 0;
    else
        return max(height(root->left),height(root->right))+1;
}

int main()
{
    TreeNode* root=new TreeNode(3);
    root->right=new TreeNode(1);
    root->right->left=new TreeNode(2);

    cout<<height(root);


}