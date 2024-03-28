#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void path(TreeNode* root,vector<string>& ans,string s)
{
    if(root==NULL)  return;
    if(root->left==NULL && root->right==NULL){
        s+=to_string(root->value);
        ans.push_back(s);
        return ;
    } 
    s+=to_string(root->value)+"->";
    if(root->left!=NULL)
        path(root->left,ans,s);
    if(root->right!=NULL)
        path(root->right,ans,s);
}
vector<string> Paths(TreeNode* root) {
    vector<string> ans;
    string s;
    path(root,ans,s);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(40);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->right = new TreeNode(20);

    vector<string> ans = Paths(root);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}