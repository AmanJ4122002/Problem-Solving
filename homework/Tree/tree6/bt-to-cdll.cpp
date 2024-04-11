#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* prev=NULL;
TreeNode * doubly(TreeNode *root)
{
    if(root==NULL) return root;
    TreeNode *head=doubly(root->left);
    if(::prev==NULL)
    head=root;
    else{
        root->left=::prev;
        ::prev->right=root;
    }
    ::prev=root;
    doubly(root->right);
    return head;
    
}
TreeNode *circular(TreeNode *root)
{
  root=doubly(root);
  TreeNode *curr=root;
  while(curr->right!=NULL){
      curr=curr->right;
  }
  curr->right=root;
  root->left=curr;
  return root;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);

    TreeNode* ans=circular(root);
    cout<<ans->left->value;

    return 0;
}