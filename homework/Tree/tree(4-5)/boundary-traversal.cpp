#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

bool leaf(TreeNode *root) {
     if(root->left==NULL && root->right==NULL)return true;
     return false; 
}

void left(TreeNode *root,vector<int>&ans){
    TreeNode *curr=root->left;
    while(curr){
      if (!leaf(curr)) {
        ans.push_back(curr->value);
      }
      if(curr->left) 
        curr=curr->left;
      else 
        curr=curr->right;
    }
}

void right(TreeNode *root,vector<int>&ans){
    TreeNode *curr=root->right;
    vector<int>temp;
    while(curr){
        if(!leaf(curr)){
            temp.push_back(curr->value);
        }
        if(curr->right) 
            curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;--i){
        ans.push_back(temp[i]);
    }
}

void leafNode(TreeNode *root,vector<int>&ans){
    if(leaf(root)){
        ans.push_back(root->value);
        return;
    }
    if(root->left) leafNode(root->left, ans);
    if(root->right) leafNode(root->right, ans);
}

vector<int> traverseBoundary(TreeNode *root)
{  
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    if(!leaf(root)){
        ans.push_back(root->value);
    }
    left(root,ans);
    leafNode(root,ans);
    right(root,ans);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    vector<int> ans = traverseBoundary(root);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}