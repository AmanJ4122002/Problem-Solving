#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int BottomLeft(TreeNode* root) {
    queue<TreeNode *> qu;
    int leftMostval=-1;
    qu.push(root);
    while(!qu.empty())
    {
        TreeNode* curr=qu.front();
        qu.pop();
        leftMostval=curr->val;
        if(curr->right!=NULL)
            qu.push(curr->right);
        if(curr->left!=NULL)
            qu.push(curr->left);
    }
    return  leftMostval;
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right= new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->right->left = new TreeNode(50);
    root->right->right = new TreeNode(60);
    root->right->left->left = new TreeNode(70);

    cout<<BottomLeft(root)<<endl;
    return 0;
}