#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* ancestor(TreeNode* root,int s,int e)
{
    if(root==NULL || root->value==s || root->value==e)
    {
        return root;
    }
    TreeNode* left=ancestor(root->left,s,e);
    TreeNode* right=ancestor(root->right,s,e);
    if(left!=NULL && right!=NULL)
        return root;
    if(left!=NULL)
        return left;
    else
        return right;
}
bool path(TreeNode* root,int val,string &s)
{
    if(!root)
        return false;
    if(root->value==val)
        return true;
    s.push_back('L');
    if(path(root->left,val,s))  
        return true;
    s.pop_back();
    s.push_back('R');
    if(path(root->right,val,s))
    {
        return true;
    }
    s.pop_back();
    return false;
}
string Directions(TreeNode* root, int start, int end) {
    if(root==NULL)
        return "";
    string s;
    TreeNode* meet=ancestor(root,start,end);
    string s1,s2;
    path(meet,start,s1);
    path(meet,end,s2);
    for(auto &it:s1)
    {
        s+="U";
    }
    return s+s2;
}


int main()
{
    TreeNode *root=new TreeNode(10);
    root->left=new TreeNode(20);
    root->right=new TreeNode(30);
    root->left->left=new TreeNode(40);
    root->right->right=new TreeNode(50);
    root->right->left=new TreeNode(60);

    int s=30,e=60;
    string s=Directions(root,s,e);
    cout<<s<<endl;
    return 0;
}