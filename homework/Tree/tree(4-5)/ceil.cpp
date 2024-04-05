#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

int ceil(TreeNode* root, int n) {
    TreeNode* node=NULL;
    while(root!=NULL)
    {
        if(root->value==n)
            return root->value;
        else if(root->value<n)
            root=root->right;
        else
        {    
            node=root;
            root=root->left;
        }
    }
    if(node==NULL)
        return -1;
    return node->value;
}

int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(8);
    root->left->right=new TreeNode(1);
    root->left->right->right=new TreeNode(9);

    cout<<ceil(root,9)<<endl;
    return 0;
}