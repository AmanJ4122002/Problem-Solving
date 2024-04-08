#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void preorder(TreeNode *root,map<int,int>& ans)
{
    if(root==NULL)
        return ;
    preorder(root->left,ans);
    ans[root->value]++;
    preorder(root->right,ans);
}


vector <int> common(TreeNode *root1, TreeNode *root2)
{
    vector<int> res;
    map<int,int> ans;
    preorder(root1,ans);
    preorder(root2,ans);
    for(auto it:ans)
    {
        if(it.second==2)
            res.push_back(it.first);
    }
    return res;
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);


    TreeNode *root2=new TreeNode(6);
    root2->left = new TreeNode(7);
    root2->right = new TreeNode(8);
    root2->left->left = new TreeNode(9);
    root2->left->right = new TreeNode(10);

    vector<int> v=common(root1,root2);
    for(auto it:v)
        cout<<it<<" ";
    cout<<endl;
    return 0;

}