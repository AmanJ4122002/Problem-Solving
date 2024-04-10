#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void kth(TreeNode* root, int &ans,int &count,int k)
{
    if(root==NULL)return ;
    kth(root->left,ans,count,k);
    if(count==k)ans=root->value;
    count++;
    kth(root->right,ans,count,k);
}
int smallest(TreeNode* root, int k) {
    int ans=0,count=1;
    kth(root,ans,count,k);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(70);
    root->left=new TreeNode(40);
    root->right=new TreeNode(60);
    root->left->left=new TreeNode(30);
    root->left->right=new TreeNode(50);
    root->left->left->left=new TreeNode(20);
    int k=5;
    cout<<smallest(root,k)<<endl;
    return 0;
}