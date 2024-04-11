#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

bool find(TreeNode* root, int k) {
    if(root == NULL)return false;
    set<int> st;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        if(st.find(k - curr->value)!=st.end())
        {
            return true;
        }
        st.insert(curr->value);
        if(curr->left != NULL)
        {
            q.push(curr->left);
        }
        if(curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    return false;
}

int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(10);
    cout << find(root,12) << endl;
    return 0;
}