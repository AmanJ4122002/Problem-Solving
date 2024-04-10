#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void find(TreeNode* root,TreeNode* &n1,TreeNode* &n2,bool& pair, TreeNode* &prev)
{
    if(root==NULL)return;
    find(root->left,n1,n2,pair,prev);
    if (prev!=NULL&&root->value<prev->value)
    {
        if (!pair)
        {
            n1 = prev;
            n2 = root;
            pair = true;
        } 
        else
        {
            n2 = root;
        }
    }
    prev=root;
    find(root->right,n1,n2,pair,prev);
}

void recover(TreeNode* root) {
    if(root==NULL)return;
    TreeNode* n1=NULL,*n2=NULL, *prev=NULL;
    bool p1=false;
    find(root,n1,n2,p1,prev);
    if (n1!=NULL&&n2!=NULL)
    {
    int temp=n1->value;
    n1->value=n2->value;
    n2->value=temp;
    }
}

int main()
{
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(4);
    root->left->right=new TreeNode(3);

    recover(root);
    return 0;
}