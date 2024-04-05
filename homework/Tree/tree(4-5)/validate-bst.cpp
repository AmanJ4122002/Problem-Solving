#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

bool isBST(TreeNode* root,long long min, long long  max)  
{  
    if (root == NULL)  
        return true;  
    return ( root->value>min && root->value<max && isBST(root->left,min,root->value) && isBST(root->right,root->value,max));  
}

bool valid(TreeNode* root) {
    if(root->left==NULL && root->right==NULL)
        return true;
    return isBST(root,LLONG_MIN,LLONG_MAX);
}

int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if(valid(root)==true)
        cout<<"Valid BST";
    else
        cout<<"Invalid BST";

}