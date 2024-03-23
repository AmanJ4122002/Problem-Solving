#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p!=NULL && q==NULL)  
        return false;
    if(p==NULL && q!=NULL)  
        return false;
    if(p==NULL && q==NULL) 
        return true;
    return (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
}

int main()
{
    TreeNode* a = new TreeNode(1);
    a -> left = new TreeNode(2);
    a -> right = new TreeNode(3);

    TreeNode* b = new TreeNode(1);
    b -> left = new TreeNode(2);
    b -> right = new TreeNode(3);

    if(isSameTree(a,b)) 
        cout << "Both trees are same";
    else 
        cout << "Trees are not the same";

    return 0;
}