#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b) {
    if(root==NULL||root==a||root==b)return root;
    TreeNode *l1=lca(root->left,a,b);
    TreeNode *l2=lca(root->right,a,b);
    if(l1!=NULL&&l2!=NULL)return root;
    else if(l1!=NULL)return l1;
    else
        return l2;
}

int main()
{
    TreeNode* root=new TreeNode(50);
    root->left=new TreeNode(20);
    root->right=new TreeNode(70);
    root->left->left=new TreeNode(10);
    root->left->right=new TreeNode(30);
    root->right->left=new TreeNode(60);
    root->right->right=new TreeNode(80);

    TreeNode* a=root->left;
    TreeNode* b=root->right;
    TreeNode* c=lca(root,a,b);
    cout<<c->value<<endl;
    return 0;
}