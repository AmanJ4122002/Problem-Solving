#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode *ancestor(TreeNode* root,int a,int b)
    {
        if(root==NULL || root->value==a || root->value==b)
            return root;
        TreeNode* left=ancestor(root->left,a,b);
        TreeNode* right=ancestor(root->right,a,b);
        if(left!=NULL && right!=NULL)
            return root;
        if(left!=NULL)
            return left;
        else
            return right;
    }
    
    int distance(TreeNode* root,int val)
    {
        int temp=0,dis=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->value==val)
                {
                    dis=temp;
                    return dis;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            temp++;
        }
    }
    
    int find(TreeNode* root, int a, int b) {
        
        TreeNode* meet=ancestor(root,a,b);
        int disa=distance(meet,a);
        int disb=distance(meet,b);
        return disa+disb;
    }

int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(20);
    root->right=new TreeNode(30);
    root->left->left=new TreeNode(40);
    root->left->right=new TreeNode(50);
    root->right->left=new TreeNode(60);
    root->right->right=new TreeNode(70);

    int a=70,b=30;
    cout<<find(root,a,b)<<endl;
    return 0;
}