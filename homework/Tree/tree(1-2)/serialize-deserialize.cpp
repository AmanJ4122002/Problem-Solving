#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
string serialize(TreeNode* root) {
    if(root==NULL)
    {
        return "";
    }
    queue<TreeNode*> q;
    q.push(root);
    string ans="";
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        if(node==NULL)
        {
            ans+="#,";
        }
        else
        {
            ans+=to_string(node->val)+",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return ans;
}
TreeNode* deserialize(string data) {
    if(data.empty())
    {
        return NULL;
    }
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root=new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        getline(s,str,',');
        if(str!="#")
        {
            TreeNode* leftNode=new TreeNode(stoi(str));
            node->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str!="#")
        {
            TreeNode* rightNode=new TreeNode(stoi(str));
            node->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<serialize(root)<<endl;
    cout<<deserialize(serialize(root))<<endl;
    return 0;
}