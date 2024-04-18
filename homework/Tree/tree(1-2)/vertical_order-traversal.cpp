#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 vector<vector<int>> verticalTraversal(TreeNode* root)
 {
    map<int,map<int,multiset<int>>> mp;
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        TreeNode* node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        mp[x][y].insert(node->val);
        if(node->left)
        {
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right)
        {
            q.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto it:mp)
    {
        vector<int> v;
        for(auto a:it.second)
        {
            v.insert(v.end(),a.second.begin(),a.second.end());
        }
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left =new TreeNode(9);
    root->right =new TreeNode(20);
    root->right->left =new TreeNode(15);
    root->right->right =new TreeNode(7);

    vector<vector<int>> ans = verticalTraversal(root);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}