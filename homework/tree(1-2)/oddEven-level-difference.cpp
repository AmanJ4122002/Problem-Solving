#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int oddEveDiff(TreeNode *root)
{
    if(root==NULL)
        return 0;
    int oddsum=0,evensum=0;
    int a=1;
    queue<TreeNode* > qu;
    qu.push(root);
    while(!qu.empty())
    {
        int count=qu.size();
        for(int i=0;i<count;i++)
        {
            TreeNode* curr=qu.front();
            qu.pop();
            if(a%2==0)
            {
                evensum+=curr->val;
            }
            else
            {
                oddsum+=curr->val;
            }
            if(curr->left!=NULL)
            {
                qu.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                qu.push(curr->right);
            }
            
        }
        a++;
    }
    return oddsum-evensum;  
}

int main()
{
    TreeNode  * root = new TreeNode(10);
    root->left=new  TreeNode(20);
    root->right=new TreeNode(30);
    root->left->left=new TreeNode(40);
    root->left->right=new TreeNode(60);

    cout<<oddEveDiff(root);
    return 0;

}