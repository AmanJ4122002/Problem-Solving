#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

struct ModTreeNode
{
    bool bst;
    int mini;
    int maxi;
    int sum;

    ModTreeNode() {}
    ModTreeNode(bool bst, int min, int max, int sum)
    {
        this->bst=bst;
        this->mini=min;
        this->maxi=max;
        this->sum=sum;
    }
    
};

int ans = 0;
ModTreeNode *maxsum(TreeNode *root, int &ans)
{
    if (root == NULL)
    {
        return new ModTreeNode(true, INT_MAX, INT_MIN, 0);
    }
    ModTreeNode *left=maxsum(root->left, ans);
    ModTreeNode *right=maxsum(root->right, ans);
    ModTreeNode *node = new ModTreeNode();
    node->bst=(left->bst&&right->bst&&(root->value>left->maxi)&&(root->value<right->mini));
    node->mini=min(left->mini,root->value);
    node->maxi=max(right->maxi,root->value);
    node->sum=left->sum+right->sum+root->value;
    if (node->bst)
    {
        ans = max(ans,node->sum);
    }
    return node;
}
int maxBST(TreeNode *root)
{
    int maxi = 0;
    ModTreeNode *temp = maxsum(root, maxi);
    if (maxi <= 0)
    {
        return 0;
    }
    return maxi;
}

int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(50);
    root->right=new TreeNode(40);
    root->left->left=new TreeNode(20);
    root->left->right=new TreeNode(50);
    root->right->left=new TreeNode(20);
    root->right->right=new TreeNode(60);
    root->right->right->left=new TreeNode(50);
    root->right->right->right=new TreeNode(70);

    cout<<maxBST(root)<<endl;
    return 0;
}