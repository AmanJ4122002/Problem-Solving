#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->value);
    inorder(root->right,ans);
}

void Merge(vector<int> &ans1,vector<int> &ans2,vector<int> &ans)
{
    
    int i=0;
    int j=0;
    
    while(i<ans1.size() && j<ans2.size())
    {
        if(ans1[i]<ans2[j])
        {
            ans.push_back(ans1[i]);
            i++;
        }
        else{
            ans.push_back(ans2[j]);
            j++;
        }
    }
    
    while(i<ans1.size())
    {
        ans.push_back(ans1[i]);
        i++;
    }
    
    while(j<ans2.size())
    {
        ans.push_back(ans2[j]);
        j++;
    }
}

vector<int> merge(TreeNode *root1, TreeNode *root2)
{
    vector<int> ans;    
    vector<int> ans1;
    vector<int> ans2;
   
    inorder(root1,ans1);
    inorder(root2,ans2);
    Merge(ans1,ans2,ans);
   
    return ans;
}

int main()
{
    TreeNode* root1 = new TreeNode(8);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(10);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(6);

    TreeNode* root2 = new TreeNode(7);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(11);
    root2->right->right = new TreeNode(15);
    root2->right->right->left = new TreeNode(13);

    vector<int> ans = merge(root1,root2);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}