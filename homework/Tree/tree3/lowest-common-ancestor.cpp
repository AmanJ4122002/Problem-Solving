#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* Ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p||root==q)
        return root;
    TreeNode *a1=Ancestor(root->left,p,q);
    TreeNode *a2=Ancestor(root->right,p,q);
    if(a1!=NULL && a2!=NULL)
        return root;
    else if(a1!=NULL)
        return a1;
    else
        return a2;
}

int main()
{
    TreeNode* root=new TreeNode(40);
    root->left=new TreeNode(50);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(10);
    root->left->right=new TreeNode(60);
    root->right->left=new TreeNode(90);
    root->right->right=new TreeNode(80);
    root->left->right->left=new TreeNode(30);
    root->left->right->right=new TreeNode(100);

    TreeNode* p=root->left;
    TreeNode* q=root->right;
    TreeNode* a=Ancestor(root,p,q);
    cout<<a->value<<endl;
    return 0;
}