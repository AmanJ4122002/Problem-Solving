#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* bst(vector<int>& pre)
{
    if(pre.size()==0)return NULL;
    if(pre.size()==1)return new TreeNode(pre[0]);
    int i=0;
    vector<int> l,r;
    TreeNode* root=new TreeNode(pre[0]);
    for(int i=1;i<pre.size();i++)
    {
        if(pre[i]>root->value)
            r.push_back(pre[i]);
        else if(pre[i]<root->value)
            l.push_back(pre[i]);
    }
    root->left=bst(l);
    root->right=bst(r);
    return root;
}

int main()
{
    vector<int> pre={8,5,1,7,10,12};
    TreeNode* root=bst(pre);
    cout<<root->value<<endl;
    return 0;
}